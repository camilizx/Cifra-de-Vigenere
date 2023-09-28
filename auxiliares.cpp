#include "enc-dec.hpp"

map<char, float> english_freq;
map<char, float> portuguese_freq;

// lista de english_freq e portuguese_freq de cada letra em ingles e portugues utilizando vector (estão em porcentagem)
void frequencies () {
    english_freq['e'] = 12.702;
    english_freq['t'] = 9.056;
    english_freq['a'] = 8.167;
    english_freq['o'] = 7.507;
    english_freq['i'] = 6.966;
    english_freq['n'] = 6.749;
    english_freq['s'] = 6.327;
    english_freq['h'] = 6.094;
    english_freq['r'] = 5.987;
    english_freq['d'] = 4.253;
    english_freq['l'] = 4.025;
    english_freq['c'] = 2.782;
    english_freq['u'] = 2.758;
    english_freq['m'] = 2.406;
    english_freq['w'] = 2.360;
    english_freq['f'] = 2.228;
    english_freq['g'] = 2.015;
    english_freq['y'] = 1.974;
    english_freq['p'] = 1.929;
    english_freq['b'] = 1.492;
    english_freq['v'] = 0.978;
    english_freq['k'] = 0.772;
    english_freq['j'] = 0.153;
    english_freq['x'] = 0.150;
    english_freq['q'] = 0.095;
    english_freq['z'] = 0.074;

    portuguese_freq['a'] = 14.63;
    portuguese_freq['e'] = 12.57;
    portuguese_freq['o'] = 10.73;
    portuguese_freq['s'] = 7.81;
    portuguese_freq['r'] = 6.53;
    portuguese_freq['i'] = 6.18;
    portuguese_freq['n'] = 5.05;
    portuguese_freq['d'] = 4.99;
    portuguese_freq['m'] = 4.74;
    portuguese_freq['u'] = 4.63;
    portuguese_freq['t'] = 4.34;
    portuguese_freq['c'] = 3.88;
    portuguese_freq['l'] = 2.78;
    portuguese_freq['p'] = 2.52;
    portuguese_freq['v'] = 1.67;
    portuguese_freq['g'] = 1.30;
    portuguese_freq['h'] = 1.28;
    portuguese_freq['q'] = 1.20;
    portuguese_freq['b'] = 1.04;
    portuguese_freq['f'] = 1.02;
    portuguese_freq['z'] = 0.47;
    portuguese_freq['j'] = 0.40;
    portuguese_freq['x'] = 0.21;
    portuguese_freq['k'] = 0.02;
    portuguese_freq['w'] = 0.01;
    portuguese_freq['y'] = 0.01;
}

void print_multimap(multimap<int, string, greater<int>> MM) {
    for (auto& it : MM) {
        cout << it.second << ' ' << it.first << endl;
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
