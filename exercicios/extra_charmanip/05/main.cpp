#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/*Escreva um programa que recebe do usuário uma string S, um caractere C e uma
posição I, e mostra o índice da primeira ocorrência do caracter C procurado a partir
da posição I.*/

int main(){

    string stringS;
    char c;
    unsigned int i;

    do{
        cout << "Input a sentence: \n"; getline(cin, stringS);
        if(stringS.empty()) cout << "Invalid input, try again.\n";
    }while(stringS.empty());

    const long unsigned int max = stringS.length()-1;
    
    cout << "Input a character to find: \n"; cin >> c;

    do{
        cout << "Input a position to search from: \n"; cin >> i;
        if(i > max) cout << "Position is greater than sentence length. Try again.\n";
    }while(i > max);

    for(; i <= max; i++){
        if(toupper(stringS[i]) == toupper(c)){
            cout << "Índice: " << i;
            break;
        }
    }

    return 0;
}