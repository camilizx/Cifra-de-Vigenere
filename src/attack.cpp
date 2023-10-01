#include "enc-dec.hpp"

string attack (string cipher, int language) {
    frequencies();
    cout << "Texto cifrado: " << cipher << endl;

    cipher = cleanText(cipher);

    int key_length = keyLength(cipher);

    vector<string> divided_cipher = divideCipher(cipher, key_length);

    string guessed_key = "";

    for (int i = 0; i < key_length; i++) {
        map<char, float> letter_freq = calculateLetterFrequencies(divided_cipher[i]);
        guessed_key += keyGuess(letter_freq, language);
    }
    
    return guessed_key;
    
}