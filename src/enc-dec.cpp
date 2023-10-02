#include "headers.hpp"

string encode (string msg, string key) {
    string encoded = "";
    key = cleanText(key);  // Remove espaços da chave caso o arquivo tenha sido preenchido com espaços no final
    int j = 0; 
    
    for (int i = 0; i < msg.length(); i++) {
        // Verifica se é uma letra
        if (isalpha(msg[i]) != 0) {         
            int shift = key[j] - 'a'; // Shift é um número entre 0 e 25 que representa quantos caracteres a letra deve ser deslocada
            // Se a letra for minuscula
            if (islower(msg[i])) {
                encoded += (char)((msg[i] + shift - 'a') % 26 + 'a');
            }
            // Se a letra for maiuscula
            else {
                encoded += (char)((msg[i] + shift - 'A') % 26 + 'A');                  
            }
            // j representa as letras da chave. Caso chegue na última letra, volta pra primeira letra da chave.
            j++;
            if (j == key.length()) j = 0;
        }
        // Se nao for uma letra, apenas ignora o caractere
        else {
            encoded += msg[i];
        }
    }
    return encoded;
}

string decode (string cript, string key) {
    string decoded = "";
    key = cleanText(key);   // Remove espaços da chave caso o arquivo tenha sido preenchido com espaços no final
    int j = 0; 

    for (int i = 0; i < cript.length(); i++) {
        // Verifica se é uma letra
        if (isalpha(cript[i]) != 0) {
            int shift = key[j] - 'a'; // Shift é um número entre 0 e 25 que representa quantos caracteres a letra deve ser deslocada
            
            // Se a letra for minuscula
            if (islower(cript[i])) {
                decoded += (char)((cript[i] - shift - 'a' + 26) % 26 + 'a');
            }
            // Se a letra for maiuscula
            else {
                decoded += (char)((cript[i] - shift - 'A' + 26) % 26 + 'A');
            }
            // j representa as letras da chave. Caso chegue na última letra, volta pra primeira letra da chave.
            j++;
            if (j == key.length()) j = 0;
        }
        // Se nao for uma letra, apenas ignora o caractere
        else {
            decoded += cript[i];
        }
    }
    return decoded;
}
