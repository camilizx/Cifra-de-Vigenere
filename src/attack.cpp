#include "headers.hpp"

string attack (string cipher, int language) {
    cipher = cleanText(cipher);                             // Remove caracteres especiais e numeros do texto cifrado
    int key_length = keyLength(cipher, language);           // Calcula o tamanho da chave
    string key = keyFinder(cipher, key_length, language);   // Encontra a chave do texto cifrado 
    return key;
}