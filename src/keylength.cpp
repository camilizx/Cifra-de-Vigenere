#include "headers.hpp"

// Calcula o Índice de Coincidência (IC) de um texto
double calculateIC(const string& textBlock) {
    vector<int> lettersFrequencies(26, 0);          // Vetor que armazena a frequência de cada letra do alfabeto
    // Conta a frequência de cada letra do alfabeto
    for (int i = 0; i < textBlock.length(); i++) {
        lettersFrequencies[tolower(textBlock[i]) - 'a']++; 
    }
    // Calcula o IC
    double ic = 0.0;
    for (int letterFrequency : lettersFrequencies) {
        ic += (double)letterFrequency * (letterFrequency - 1);
    }
    // Divide o somatório pelo tamanho do bloco vezes o tamanho do bloco menos 1
    ic /= (double)(textBlock.length() * (textBlock.length() - 1));
    return ic;
}

int keyLength(string cipher, int language) {
    vector<double> icValues(MAX_KEY_LEN-1, 0.0);                        // Valores de IC para diferentes tamanhos de bloco                  

    for (int blockSize = 2; blockSize <= MAX_KEY_LEN; blockSize++) {     // Calcula o IC para diferentes tamanhos de bloco 
        double sumIC = 0.0;
        for (int i = 0; i < blockSize; i++) {
            string block;                                               // Bloco de texto com tamanho = blockSize
            for (int j = i; j < cipher.length(); j += blockSize) {      
                block += cipher[j];                                     // Adiciona o caractere na posição j ao bloco
            }
            sumIC += calculateIC(block);                                // Calcula o IC do bloco e adiciona ao somatório
        }
        double averageIC = sumIC / blockSize;
        icValues[blockSize - 2] = averageIC;                            // Armazena o IC médio para o tamanho de bloco atual
    }                                                                   // -2 pois o tamanho mínimo da chave é 2

    // Encontrar o tamanho da chave com base no IC
    int selectedBlockSize = 0;                              // Tamanho da chave selecionado com base no IC
    double minICDifference = numeric_limits<double>::max(); // Pega o maior valor possível de double e armazena em minICDifference
    double defaultIC = (language == 1) ? 0.0745 : 0.0667;   // IC esperado para português = 0.074. IC esperado para inglês = 0.067. 

    for (int i = 0; i < icValues.size(); i++) {             // Encontra o tamanho de bloco com IC mais próximo do esperado
        double icDifference = abs(icValues[i] - defaultIC); 
        if (icDifference < minICDifference) {
            minICDifference = icDifference;
            selectedBlockSize = i + 2;
        }
    }
    cout << "Tamanho da chave selecionado com base no IC: " << selectedBlockSize << endl;
    return selectedBlockSize;
}
