#include "enc-dec.hpp"

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
char keyGuess (map<char,float> cipher_letter_frequencies, int language) {
    vector<float> differences;
     map <char,float> default_letter_frequencies;

    if (language == 1) default_letter_frequencies = portuguese_letter_frequencies;
    else if (language == 2) default_letter_frequencies = english_letter_frequencies;
    
    for (int i = 0; i < 26; i++) {
        map<char,float> cipher_shifted = shiftValues(cipher_letter_frequencies, i);
        float difference = diff(cipher_shifted, default_letter_frequencies);
        //cout << "Diferenca " << char('a'+ i) << ": " << difference << endl;
        differences.push_back(difference);
    }
    // find the index of the minimum element
    int min_index = min_element(differences.begin(), differences.end()) - differences.begin();
    return char('a' + min_index);
}
