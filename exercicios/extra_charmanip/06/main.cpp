#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/*O código de César é uma das mais simples e conhecidas técnicas de criptografia. É
um tipo de substituição na qual cada letra do texto é substituída por outra, que se
apresenta no alfabeto abaixo dela um número fixo de vezes. OU seja, com uma
troca de três posições ‘A’ seria substituído por ‘D’, ‘B’ se tornaria ‘E’, e assim por
diante.
Implemente um programa que leia uma string e gere outra string codificada,
fazendo uso desse Código de César (3 posições). Ex.:
ENTRADA: a ligeira raposa marrom saltou sobre o cachorro cansado
SAÍDA: D OLJHLUD UDSRVD PDUURP VDOWRX VREUH R FDFKRUUR FDQVDGR*/

int main(){

    string phrase, code;
    char codeChar;

    do{
        cout << "Input a sentence: \n"; getline(cin, phrase);
    }while(phrase.empty());

    for(unsigned i = 0; i < phrase.length(); i++){
        if(isalpha(phrase[i])){
            if((phrase[i] > 87 and phrase[i] < 91) or (phrase[i] > 119 and phrase[i] < 123)){
                phrase[i] = phrase[i] - 23;
            } else {
                codeChar = phrase[i] + 3;
                code = code + codeChar;
            }
        } else {
            code = code + phrase[i];
        }
    }

    cout << code;

    return 0;
}