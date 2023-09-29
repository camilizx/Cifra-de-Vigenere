#include "enc-dec.hpp"

using namespace std;

int main () {

    frequencies();

    int blockSize = 3;
    
    string key = "xycabacadabrastardewvalley";
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
    
    //string format_text = "minhaviagemparsaopauloassistiraoshowdoghostemcomnossosamigosfoisimplesmenteincrivelfoiumaexperienciaqueguardareicomcarinhonamemoriapormuitosanosaempolgacaocomecoumuitoantesdodiadaviagemplanejamostudonosminimosdetalhesdesdeacompradosingressosateaescolhadohotelpareciaqueestavamospreparandoumaaventuraepicaeaansiedadesoaumentavamedidaquedataseaproximavafinalmenteograndediachegounosreunimosnoaeroportocomnossosamigostodoscomcamisetasdabandaeaquelebrilhonosolhosquesoosfasdemusicaentendemoshowemsifoisimplesmenteespetacularogostnaodecepcionouentregandoumaperformancecheiadeenergiaefeitosvisuaisdeslumbranteseclarosuasmusicasincriveiscantamosdancamosenosemocionamosjuntoscompartilhandoessemomentoespecialcomnossosamigosdepoisdoshowvoltamosaohotelexaustosmascomsorrisosenormesnosrostospassamoshorasrelembrandoosmelhoresmomentosdanochecompartilhandonossasmusicasfavoritaseplanejandonossaproximaaventuramusicaleugosteimuitodoshowsdoghostporquefoimuitolegaleuadorei";
    string format_text = "minhaviagemparsaopauloassistiraoshowdoghostemcomnossosamigosfoisimplesmenteincrivelfoiumaexperienciaqueguardareicomcarinhonamemoriapormuitosanosaempolgacaocomecoumuitoantesdodiadaviagemplanejamostudonosminimosdetalhesdesdeacompradosingressosateaescolhadohotelpareciaqueestavamospreparandoumaaventuraepicaeaansiedadesoaumentavamedidaquedataseaproximavafinalmenteograndediachegounosreunimosnoaeroportocomnossosamigostodoscomcamisetasdabandaeaquelebrilhonosolhosquesoosfasdemusicaentendemoshowemsifoisimplesmenteespetacularogostnaodecepcionouentregandoumaperformancecheiadeenergiaefeitosvisuaisdeslumbranteseclarosuasmusicasincriveiscantamosdancamosenosemocionamosjuntoscompartilh";


    string cipher = encode(format_text, key);
    cout << "Cifra: " << endl << cipher << endl;

    int key_length = keyLength(cipher);

    vector<string> teste = divideCipher(cipher, key_length);

    // Isso aqui vai ser um for que vai rodar 3 vezes (tamanho da chave)
    string guessed_key = "";
    for (int i = 0; i < key_length; i++) {
        map<char, float> letter_freq = calculateLetterFrequencies(teste[i]);
        guessed_key += keyGuess(letter_freq);
    }

    cout << "A chave eh: " << guessed_key << endl;

   return 0;
}