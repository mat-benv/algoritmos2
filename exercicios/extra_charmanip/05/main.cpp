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
    bool valid;

    do{
        valid = true;
        cout << "Input a sentence: \n"; getline(cin, stringS);
        if(stringS == "") valid = false;
        if(not valid) cout << "Invalid input, try again.\n";
    }while(not valid);

    const long unsigned int max = stringS.length()-1;

    cout << "Input a character to find: \n"; cin >> c;

    do{
        valid = true;
        cout << "Input a position to search from: \n"; cin >> i;
        if(i > max) valid = false;
        if(not valid) cout << "Position is greater than sentence length. Try again.\n";

    }while(not valid);

    for(unsigned int j = i; j < max; j++){
        if(toupper(stringS[j]) == toupper(c)){
            cout << "Índice: " << j;
            break;
        }
    }

    return 0;
}