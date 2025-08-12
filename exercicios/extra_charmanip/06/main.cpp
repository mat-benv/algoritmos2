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
    char alpha[29]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C'};

    do{
        cout << "Input a sentence: \n"; getline(cin, phrase);
    }while(phrase.empty());

    for(unsigned i = 0; i < phrase.length(); i++){
        for(unsigned j = 0; j < 29; j++){
            if(toupper(phrase[i]) == alpha[j]){
                code = code + alpha[j + 3];
                break;
            }
        }
    }

    cout << code;

    return 0;
}