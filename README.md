# README - Projeto de Segurança Computacional

## Cifra de Vigenère

Este é o README para o projeto de Segurança Computacional desenvolvido pelos alunos da Universidade de Brasília, Camila Frealdo Fraga (17/0007561) e José Roberto Interaminense Soares (19/0130008), como parte da disciplina de Segurança Computacional, no segundo semestre de 2023.

## Descrição do Projeto

O projeto consiste em um programa que oferece funcionalidades de cifrar, decifrar e um ataque para a quebra da cifra de Vigenère. Ele utiliza diferentes métodos e técnicas de segurança computacional para alcançar essas funcionalidades.

## Funcionalidades

O programa oferece as seguintes funcionalidades:

### 1. Cifragem de Texto

Esta opção permite ao usuário cifrar um texto usando uma chave fornecida. O texto a ser cifrado é lido de um arquivo chamado "plaintext.txt", e a chave é lida de um arquivo chamado "key.txt". O texto cifrado é exibido na saída padrão.

### 2. Decifragem de Texto

Esta opção permite ao usuário descriptografar um texto cifrado usando uma chave fornecida. O texto cifrado é lido de um arquivo chamado "ciphertext.txt", e a chave é lida de um arquivo chamado "key.txt". O texto descriptografado é exibido na saída padrão.

### 3. Ataque

Esta opção é utilizada para tentar descobrir a chave usada para cifrar um texto, conhecido como ataque de força bruta. O texto cifrado é lido de um arquivo chamado "ciphertext.txt", e o usuário precisa escolher o idioma do texto original (português ou inglês). O programa tentará encontrar a chave e exibir o texto original.

## Instruções de Uso

**Importante:** Antes de usar as opções 1 ou 2, verifique se os arquivos "plaintext.txt", "key.txt" e "ciphertext.txt" estão preenchidos com o texto,cifra e a chave apropriados.

**Caso tenha o makefile instalado**

1. Compile o programa utilizando o Makefile fornecido com o seguinte comando:
   make
2. Prossiga com a execução do programa como indicado no terminal.

**Caso não tenha o makefile instalado**
Rode o seguinte comando no terminal:
```g++ main.cpp src/utilities.cpp src/attack.cpp src/enc-dec.cpp src/freqanalysis.cpp src/keylength.cpp -o trabalho ```
Em seguida, execute o programa com o seguinte comando:
```./trabalho ```

## Descrição da Implementação
A descrição do projeto pode ser encontrada no relatório, disponível no arquivo "Relatório.pdf".

