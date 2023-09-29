#include "enc-dec.hpp"

//Procura os grupos de frequencias mais comuns no texto cifrado
map<string, int> calculateFrequencies(string text, int blockSize) {
    map<string, int> frequency; // Mapa de frequencias
    for (int i = 0; i < text.length() - blockSize + 1; i+= 1) {     
        bool clean_block = true;
        // Nao considerar blocos com pontuacao, espacos e numeros
        for (int j = i; j < i+blockSize; j++) {
            if (isalpha(text[j]) == 0) {
                clean_block = false;
                //cout << "Block " << text.substr(i, blockSize) << " not considered" << endl;
            }
        }
        if (clean_block) {
            string block = text.substr(i, blockSize);
            if (frequency.find(block) != frequency.end()) {
                frequency[block] += 1;
            } else {
                frequency[block] = 1;
            }
        }
    }
    return frequency;
}

//Calcula a distancia entre os grupos de caracteres mais frequentes 
vector<int> calculateDistance(const map<string, int>& most_common_blocks, const string& cipher) {
    vector<int> distances;

    // Para cada bloco mais comum
    for (const auto& entry : most_common_blocks) {
        const string& block = entry.first;
        int block_count = entry.second;
        int block_size = block.length();
        
        int start_index = 0;
        int end_index = 0;
        int dis = 0;

        // Encontre as ocorrências do bloco no texto cifrado
        for (int i = 0; i < cipher.length() - block_size + 1; i++) {
            if (cipher.substr(i, block_size) == block) {
                start_index = i+block_size;
                for (int j = start_index; j < cipher.length() - block_size + 1; j++ ) {
                    if (cipher.substr(j, block_size) == block) {
                        end_index = j;
                        i = j-1;
                        distances.push_back(dis+block_size);
                        dis = 0;
                        break;
                    }
                    if (isalpha(cipher[j]) != 0)
                        dis++;
                }
            }
        }
    }
    return distances;
}

// Calcula os divisores de cada distancia
map<int, int> calculateDivisors(vector<int> distances){
    map<int, int> divisors;

    for (int i=0; i < distances.size(); i++) {
        for (int j = 2; j < distances[i]+1; j++) {
           if (distances[i] % j == 0) {
               divisors[j] += 1;
           }
       }
    }
    return divisors;      
}

// Pega o divisor que aparece mais vezes (esse número vai ser o possível tamanho da chave)
int getMostFrequentDivisor(map<int, int> divisors) {
    int most_frequent_divisor = 0;
    int most_frequent_divisor_count = 0;
    for (const auto& entry : divisors) {
        int divisor = entry.first;
        int divisor_count = entry.second;
        if (divisor_count > most_frequent_divisor_count) {
            most_frequent_divisor = divisor;
            most_frequent_divisor_count = divisor_count;
        }
    }
    return most_frequent_divisor;
}

int poundedDivisor (map<int,int> divisors, int most_frequent_divisor) {
    map <int,int> pounded_divisors;
    int new_most_frequent_divisor = 0;

    // Pegar apenas os múltiplos do divisor mais frequente
    for (const auto& entry : divisors) {
        int divisor = entry.first;
        if (divisor % most_frequent_divisor == 0 && divisor < MAX_KEY_LEN) {
            pounded_divisors[divisor] = entry.second;
        }
    }

    // cout << "Pounded divisors: " << endl;
    // for (const auto& entry : pounded_divisors) {
    //     cout << entry.first << " Aparece " << entry.second << endl;
    // }

    //0.8 número mágico
    for (int i = MAX_KEY_LEN; i > 0; i--) {
        if (divisors[i] > divisors[most_frequent_divisor]*0.7) {
            new_most_frequent_divisor = i;
            break;
        }
    }

    return new_most_frequent_divisor;
}

// Essa funçao tenta descobrir o possível tamanho da chave
int keyLength (string cipher) {
    map<string, int> frequency_triples = calculateFrequencies(cipher, 3);           // Calcula as frequencias dos grupos de 3 caracteres

    multimap<int, string, greater<int>> sorted_frequency = sort(frequency_triples); // Ordena as frequencias em ordem decrescente

    map<string, int> top_10_map;                                                    // Criar um novo map que recebe os top 10 elementos do multimap

    int count = 0;
    for (const auto& entry : sorted_frequency) {
        if (count < 10) {
            top_10_map[entry.second] = entry.first;
            count++;
        }
    }

    //Agora, top_10_map contém os top 10 elementos com maior frequência
    // for (const auto& entry : top_10_map) {
    //     cout << entry.first << ": " << entry.second << endl;
    // }
    
    vector<int> distances = calculateDistance(top_10_map, cipher);
    
    map<int, int> divisors = calculateDivisors(distances);
    // print divisors
    //map<int,int> pounded_divisors;

    //print distances
    // for (int i = 0; i < distances.size(); i++) {
    //     cout << distances[i] << endl;
    // }

    //Print quantidade de vezes que os divisores das distancias aparecem
    for (const auto& entry : divisors) {
        cout << entry.first << " Aparece " << entry.second << endl;
    }

    int most_frequent_divisor = getMostFrequentDivisor(divisors);
    
    most_frequent_divisor = poundedDivisor(divisors, most_frequent_divisor);

    cout << "Possible key length: " << most_frequent_divisor << endl;

    return most_frequent_divisor;
}

//Funcao que divide a cifra em varias partes n (tamanho da chave).
//ABCDEFGHIJ, key_length = 3
//divided_cipher = ADGJ, BEH, CFI
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
        letter_frequencies[entry.first] = (entry.second / text.length())*100;
    }
    // se não tiver a letra no texto, a frequencia é 0
    for (int i = 0; i < 26; i++) {
        if (letter_frequencies.find('a'+i) == letter_frequencies.end()) {
            letter_frequencies['a'+i] = 0;
        }
    }

    return letter_frequencies;
}

//Funcao que calcula a diferenca entre as frequencias das letras do texto cifrado e as frequencias das letras em portugues
char keyGuess (map<char,float> cipher_letter_frequencies) {
    vector<float> differences;
    
    for (int i = 0; i < 26; i++) {
        map<char,float> cipher_shifted = shiftValues(cipher_letter_frequencies, i);
        float difference = diff(cipher_shifted, portuguese_letter_frequencies);
        //cout << "Diferenca " << char('a'+ i) << ": " << difference << endl;
        differences.push_back(difference);
    }
    // find the index of the minimum element
    int min_index = min_element(differences.begin(), differences.end()) - differences.begin();
    return char('a' + min_index);
}
