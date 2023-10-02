/*
        Universidade de Brasilia - Departamento de Ciencia da Computacao
        Seguranca Computacional 2023/02 - Turma T02
        Alunos: Camila Frealdo Fraga - 17/0007561
                Jose Roberto Interaminense Soares - 19/0130008
*/


#include "./src/headers.hpp"

using namespace std;

int main () {
    int op, language;
    string text, cipher, key;

    while (true) {
        text = readFile("plaintext.txt");
        cipher = readFile("ciphertext.txt");
        key = readFile("key.txt");

        cout << endl << "IMPORTANTE: Se voce deseja realizar as operacoes 1 ou 2, verifique se os arquivos txt estao preenchidos com o texto/cifra e a chave!" << endl;
        cout << endl << "Digite o numero da operacao que deseja realizar: " << endl;
        cout << "1 - Cifrar" << endl;
        cout << "2 - Decifrar" << endl;
        cout << "3 - Ataque" << endl;
        cin >> op;

        switch (op) {
        case 1:
            cout << "Texto a ser cifrado: " << endl;
            cout << text << endl;
            cout << "Chave utilizada: " << endl;
            cout << key << endl;
            cipher = encode(text, key);
            cout << "Texto cifrado: " << endl << cipher << endl;
            break;
        case 2:
            cout << "Texto a ser decifrado: " << endl;
            cout << cipher << endl;
            cout << "Chave utilizada: " << endl;
            cout << key << endl;
            text = decode(cipher, key);
            cout << "Texto decifrado: " << endl << text << endl;
            break;
        case 3:
            cout << "Texto a ser decifrado: " << endl;
            cout << cipher << endl;
            cout << "Defina o idioma do texto: " << endl;
            cout << "1 - Portugues" << endl;
            cout << "2 - Ingles" << endl;
            cin >> language;
            cout << endl << "A SUA CHAVE SERA DESCOBERTA E O TEXTO REVELADO *O*" << "\n\n";
            string discovered_key = attack(cipher, language);
            cout << endl << "Chave descoberta: " << endl << discovered_key << endl;
            text = decode(cipher, discovered_key);
            cout << endl << "Texto revelado: " << endl << text << endl;
            break;
        }
        cout << "Deseja realizar outra operacao? (1 - Sim, 0 - Nao)" << endl;
        cin >> op;

        if (op == 0) {
            cout<< "Adeus!" << endl;
            break;
        }
    }
    
   return 0;
}