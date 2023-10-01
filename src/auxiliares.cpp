#include "enc-dec.hpp"

map<char, float> english_letter_frequencies;
map<char, float> portuguese_letter_frequencies;

// lista de english_letter_frequencies e portuguese_letter_frequencies de cada letra em ingles e portugues utilizando vector (estão em porcentagem)
void frequencies () {
    english_letter_frequencies['a'] = 8.167;
    english_letter_frequencies['b'] = 1.492;
    english_letter_frequencies['c'] = 2.782;
    english_letter_frequencies['d'] = 4.253;
    english_letter_frequencies['e'] = 12.702;
    english_letter_frequencies['f'] = 2.228;
    english_letter_frequencies['g'] = 2.015;
    english_letter_frequencies['h'] = 6.094;
    english_letter_frequencies['i'] = 6.966;
    english_letter_frequencies['j'] = 0.153;
    english_letter_frequencies['k'] = 0.772;
    english_letter_frequencies['l'] = 4.025;
    english_letter_frequencies['m'] = 2.406;
    english_letter_frequencies['n'] = 6.749;
    english_letter_frequencies['o'] = 7.507;
    english_letter_frequencies['p'] = 1.929;
    english_letter_frequencies['q'] = 0.095;
    english_letter_frequencies['r'] = 5.987;
    english_letter_frequencies['s'] = 6.327;
    english_letter_frequencies['t'] = 9.056;
    english_letter_frequencies['u'] = 2.758;
    english_letter_frequencies['v'] = 0.978;
    english_letter_frequencies['w'] = 2.360;
    english_letter_frequencies['x'] = 0.150;
    english_letter_frequencies['y'] = 1.974;
    english_letter_frequencies['z'] = 0.074;

    portuguese_letter_frequencies['a'] = 14.63;
    portuguese_letter_frequencies['b'] = 1.04;
    portuguese_letter_frequencies['c'] = 3.88;
    portuguese_letter_frequencies['d'] = 4.99;
    portuguese_letter_frequencies['e'] = 12.57;
    portuguese_letter_frequencies['f'] = 1.02;
    portuguese_letter_frequencies['g'] = 1.30;
    portuguese_letter_frequencies['h'] = 1.28;
    portuguese_letter_frequencies['i'] = 6.18;
    portuguese_letter_frequencies['j'] = 0.40;
    portuguese_letter_frequencies['k'] = 0.02;
    portuguese_letter_frequencies['l'] = 2.78;
    portuguese_letter_frequencies['m'] = 4.74;
    portuguese_letter_frequencies['n'] = 5.05;
    portuguese_letter_frequencies['o'] = 10.73;
    portuguese_letter_frequencies['p'] = 2.52;
    portuguese_letter_frequencies['q'] = 1.20;
    portuguese_letter_frequencies['r'] = 6.53;
    portuguese_letter_frequencies['s'] = 7.81;
    portuguese_letter_frequencies['t'] = 4.34;
    portuguese_letter_frequencies['u'] = 4.63;
    portuguese_letter_frequencies['v'] = 1.67;
    portuguese_letter_frequencies['w'] = 0.01;
    portuguese_letter_frequencies['x'] = 0.21;
    portuguese_letter_frequencies['y'] = 0.01;
    portuguese_letter_frequencies['z'] = 0.47;
}

// Funcao que remove os caracteres especiais e deixa apenas letras minusculas
string cleanText (string text) {
    string newText;
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i]) != 0) {
            newText += tolower(text[i]);
        }
    }
    return newText;
}

// Le arquivo e salva numa string
string readFile(string fileName) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return ""; // Ou outra ação de tratamento de erro apropriada.
    }

    string content;
    string line;
    while (getline(inputFile, line)) {
        content += line + "\n"; // Concatenar cada linha ao conteúdo.
    }

    inputFile.close();

    return content;
}



void print_multimap(multimap<int, string, greater<int>> MM) {
    for (auto& it : MM) {
        cout << it.second << ' ' << it.first << endl;
    }
}

void print_map(map<string, int> M) {
    for (auto& it : M) {
        cout << it.first << ' ' << it.second << endl;
    }
}

multimap<int, string, greater<int>> sort(map<string, int>& M) {
    // Declare a multimap
    multimap<int, string, greater<int>> MM;
    // Insert every (key-value) pairs from map M to multimap MM as (value-key) pairs
    for (auto& it : M) {
        MM.insert({ it.second, it.first });
    }
    return MM;
}

// Funcao que faz a diferenca entre dois maps de char, float e retorna
// a soma das diferencas absolutas de cada letra
float diff(map<char, float> M1, map<char, float> M2) {
    float sum = 0;
    for (auto& it : M1) {
        float freq1 = it.second;
        float freq2 = M2[it.first];
        sum += ((freq1 - freq2) * (freq1 - freq2));
    }
    return sum;
}

// Função para deslocar os values do mapa em 'deslocamento' posições
map<char, float> shiftValues(map<char, float> original, int deslocamento) {
    map<char, float> newMap;

    // Obtém as keys e values do mapa original
    vector<char> keys;
    vector<float> values;
    for (const auto &par : original) {
        keys.push_back(par.first);
        values.push_back(par.second);
    }

    // Calcula o tamanho do mapa
    int tamanho = keys.size();

    // Desloca os values e preenche o novo mapa
    for (int i = 0; i < tamanho; ++i) {
        int novaPosicao = (i + deslocamento) % tamanho;
        newMap[keys[i]] = values[novaPosicao];
    }
    return newMap;
}




