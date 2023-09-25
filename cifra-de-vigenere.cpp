#include "enc-dec.hpp"
using namespace std;

int main () {
    string key = "biscoito";
    string text = "A viagem para Sao Paulo para ver o show do Ghost foi muito legal Xeiraz!";

    cout << encode(text, key) << endl;
}