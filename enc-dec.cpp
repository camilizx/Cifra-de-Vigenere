//mensagem : A viagem para São Paulo para ver o show do Ghost foi muito legal!!!
//chave: abc - aaa = [0,1,2]

#include "enc-dec.hpp"

string encode (string msg, string key) {

    string encoded = "";
    int j = 0; // Itera no vetor key
    // Chave maiuscula 
    for (int i = 0; i < key.length(); i++) {
        key[i] = toupper(key[i]);
    }
    for (int i = 0; i < msg.length(); i++) {
        // Verifica se é uma letra
        if (isalpha(msg[i]) != 0) {
            int shift = key[j] - 'A'; // Shift é um número entre 0 e 25
            
            // Se a letra for minuscula
            if (islower(msg[i])) {
                encoded += (char)((msg[i] + shift - 'a') % 26 + 'a');
            }
            // Se a letra for maiuscula
            else {
                encoded += (char)((msg[i] + shift - 'A') % 26 + 'A');
            }
            j++;
            if (j == key.length()) j = 0;
        }
        else {
            encoded += msg[i];
        }
    }

    return encoded;
}

string decode (string cript, string key) {
    string decoded = "";
    int j = 0; // Itera no vetor key
    // Chave maiuscula 
    for (int i = 0; i < key.length(); i++) {
        key[i] = toupper(key[i]);
    }
    for (int i = 0; i < cript.length(); i++) {
        // Verifica se é uma letra
        if (isalpha(cript[i]) != 0) {
            int shift = key[j] - 'A'; // Shift é um número entre 0 e 25
            
            // Se a letra for minuscula
            if (islower(cript[i])) {
                decoded += (char)((cript[i] - shift - 'a' + 26) % 26 + 'a');
            }
            // Se a letra for maiuscula
            else {
                decoded += (char)((cript[i] - shift - 'A' + 26) % 26 + 'A');
            }
            j++;
            if (j == key.length()) j = 0;
        }
        else {
            decoded += cript[i];
        }
    }
    return decoded;
}
