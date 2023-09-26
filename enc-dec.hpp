#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

extern map<char, float> english_freq;
extern map<char, float> portuguese_freq;

string encode (string msg, string key);
string decode (string cript, string key);

//string treatText (string text);

void frequencies ();
void print_map(multimap<int, string, greater<int>> MM);
multimap<int, string, greater<int>> sort(map<string, int>& M);


multimap<int, string, greater<int>> map_sort(map<string, int>& M);

map<string, int> calculateFrequencies(string text, int blockSize);