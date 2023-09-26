#include "enc-dec.hpp"

using namespace std;

struct comparador {
  bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
    return a.second < b.second;
  }
};

int main () {

    frequencies();
    
    string key = "bis";
    string text = "Minha viagem para Sao Paulo para assistir ao show do Ghost em 21/09/2023 com nossos amigos foi simplesmente incrivel!" 
                  " Foi uma experiencia que guardarei com carinho na memoria por muitos anos. A empolgacao comecou muito antes do dia da viagem."
                  " Planejamos tudo nos minimos detalhes, desde a compra dos ingressos ate a escolha do hotel."
                  " Parecia que estavamos preparando uma aventura epica, e a ansiedade so aumentava a medida que a data se aproximava." 
                  " Finalmente, o grande dia chegou. Nos reunimos no aeroporto com nossos amigos, todos com camisetas da banda e aquele" 
                  " brilho nos olhos que so os fas de musica entendem."
                  " O show em si foi simplesmente espetacular. O Ghost nao decepcionou, entregando uma performance cheia de energia, efeitos" 
                  " visuais deslumbrantes, e claro, suas musicas incriveis."
                  " Cantamos, dancamos e nos emocionamos juntos, compartilhando esse momento especial com nossos amigos."
                  " Depois do show, voltamos ao hotel, exaustos, mas com sorrisos enormes nos rostos. Passamos horas relembrando os melhores momentos da noite, "
                  " compartilhando nossas musicas favoritas e planejando nossa proxima aventura musical.";
    string crypt = encode(text, key);
    string test = "Alomeu ema, meumeumeudiaABC witterABCABCmeu Alooteste!";
    
    cout << encode(test, key) << "\n\n";
    //cout << decode(encode(text, key), key) << "\n\n";
    
    int blockSize = 3;

    map<string, int> frequency = calculateFrequencies(encode(test, key), blockSize);

    multimap<int, string, greater<int>> orderedMap = sort(frequency);

    print_map(orderedMap);

   return 0;
}