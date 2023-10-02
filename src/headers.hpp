#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <cmath>

#define MAX_KEY_LEN 20

using namespace std;

//Funcoes que guardam frequencias de letras (ingles e portugues)
extern map<char, float> english_letter_frequencies;
extern map<char, float> portuguese_letter_frequencies;
void frequencies ();

//Funcoes que codificam e decodificam uma mensagem
string encode (string msg, string key);
string decode (string cript, string key);

//Funcoes que quebram a cifra
string attack (string cipher, int language);
int keyLength(string cipher, int language);                     
string keyFinder (string cipher, int key_length, int language);      

//Funcoes auxiliares
string readFile (string fileName);
void print_map(map<string, int> M);
void print_multimap(multimap<int, string, greater<int>> MM);
multimap<int, string, greater<int>> sort(map<string, int>& M);
multimap<int, string, greater<int>> map_sort(map<string, int>& M);
float diff(map<char, float> M1, map<char, float> M2);
map<char, float> shiftValues(map<char, float> original, int deslocamento);
string cleanText (string text);
string isPasswordRepeatedWords(const string& password);



