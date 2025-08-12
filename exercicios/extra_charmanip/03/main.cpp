#include <iostream>
#include <string>
using namespace std;

/*Faça um programa que recebe do usuário uma string A e monte uma nova string B
cujo conteúdo é a string A sem suas vogais. Mostre B ao final.*/

bool isVowel(char c){
    char vowels[5]{'A', 'E', 'I', 'O', 'U'};
    for(unsigned int i = 0; i < 5; i++){
        if(c == vowels[i]){
            return true;
            break;
        }
    }
    return false;
}

int main(){

    string stringA, stringB="";
    bool valid;

    do{
        valid = true;
        cout << "Input a sentence: \n"; getline(cin, stringA);
        if(stringA == "") valid = false;
    }while(not valid);

    for(unsigned int i = 0; i < stringA.length(); i++){
        if(not isVowel(stringA[i])) stringB = stringB + stringA[i];
    }

    cout << stringB;

    return 0;
}