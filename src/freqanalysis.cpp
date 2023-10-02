#include "headers.hpp"

//Funcao que divide a cifra em varias partes n (tamanho da chave).
vector<string> divideCipher(string cipher, int key_length) {
    vector<string> divided_cipher;
    for (int i = 0; i < key_length; i++) {
        string block = "";
        for (int j = i; j < cipher.length(); j+=key_length) {
            block += cipher[j];
        }
        divided_cipher.push_back(block);
    }
    return divided_cipher;
}

// Função que calcula as frequencias das letras que aparecem no texto cifrado
map<char, float> calculateLetterFrequencies(string text) {
    map<char, float> letter_frequencies;
    for (int i = 0; i < text.length(); i++) {
        if (letter_frequencies.find(text[i]) != letter_frequencies.end()) {
            letter_frequencies[text[i]] += 1;
        } else {
            letter_frequencies[text[i]] = 1;
        }
    }
    for (const auto& entry : letter_frequencies) {
        letter_frequencies[entry.first] = (entry.second / text.length())*100;       // *100 pois as frequencias salvas dos idiomas estao em porcentagem
    }
    for (int i = 0; i < 26; i++) {                                                  // Caso nao haja letra no texto, definir frequencia como 0
        if (letter_frequencies.find('a'+i) == letter_frequencies.end()) {
            letter_frequencies['a'+i] = 0;
        }
    }
    return letter_frequencies;
}

//Funcao que calcula a diferenca entre as frequencias das letras do texto cifrado e as frequencias das letras em portugues
char keyGuessLetter (map<char,float> cipher_letter_frequencies, int language) {
    vector<float> differences;                                                              // armazena diferencas entre as frequencias das letras do texto cifrado e as frequencias das letras em portugues
    map <char,float> default_letter_frequencies;                                            

    if (language == 1) default_letter_frequencies = portuguese_letter_frequencies;          // define as frequencias das letras do idioma
    else if (language == 2) default_letter_frequencies = english_letter_frequencies;
    
    for (int i = 0; i < 26; i++) {                                                          // faz o shift das frequencias das letras do texto cifrado e calcula a diferenca entre as frequencias
        map<char,float> cipher_shifted = shiftValues(cipher_letter_frequencies, i);         // faz o shift das frequencias das letras do texto cifrado
        float difference = diff(cipher_shifted, default_letter_frequencies);                // calcula a diferenca entre as frequencias
        differences.push_back(difference);                                                 // armazena a diferenca
    }
    int min_index = min_element(differences.begin(), differences.end()) - differences.begin();  // acha o indice do menor valor no vetor de diferencas
    return char('a' + min_index);                                                               // Retorna a letra correspondente
}

// Funcao que encontra a chave do texto cifrado
string keyFinder (string cipher, int key_length, int language) {
    frequencies();                                                                                  // Contém as frequencias de letras para cada idioma
    string key = "";

    vector<string> divided_cipher = divideCipher(cipher, key_length);                               // Divide a cifra em n partes (tamanho da chave)
    
    for (int i = 0; i < key_length; i++) {
        map<char,float> cipher_letter_frequencies = calculateLetterFrequencies(divided_cipher[i]);  // Calcula as frequencias das letras de cada parte da cifra
        char key_letter = keyGuessLetter(cipher_letter_frequencies, language);                      // Chuta a letra da chave
        key += key_letter;                                                                          // Adiciona a letra na chave
    }
    // Verifica se a chave possui palavras repetidas (ex: ghostghostghost), se sim, retorna a chave sem a repeticao (ghost), se nao, retorna a chave
    return isPasswordRepeatedWords(key) == "" ? key : isPasswordRepeatedWords(key);
}