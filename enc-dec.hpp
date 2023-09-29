#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

#define MAX_KEY_LEN 30

using namespace std;

extern map<char, float> english_letter_frequencies;
extern map<char, float> portuguese_letter_frequencies;

string encode (string msg, string key);
string decode (string cript, string key);

void frequencies ();
void print_map(map<string, int> M);
void print_multimap(multimap<int, string, greater<int>> MM);

multimap<int, string, greater<int>> sort(map<string, int>& M);
multimap<int, string, greater<int>> map_sort(map<string, int>& M);
map<string, int> calculateFrequencies(string text, int blockSize);

int keyLength (string cipher);

map<int, int> calculateDivisors(vector<int> distances);
int getMostFrequentDivisor(map<int, int> divisors);

vector<string> divideCipher(string cipher, int key_length);
map<char, float> calculateLetterFrequencies(string text);

float diff(map<char, float> M1, map<char, float> M2);
map<char, float> shiftValues(map<char, float> original, int deslocamento);

char keyGuess (map<char,float> cipher_letter_frequencies);