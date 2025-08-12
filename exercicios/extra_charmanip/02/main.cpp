#include <iostream>
#include <cstring>
using namespace std;

/*Faça um programa que recebe uma string A e inteiros positivos I e J e mostre o
segmento A[I..J].*/

int main(){

    string stringA;
    unsigned int i, j;
    bool valid;

    do{
        valid = true;
        cout << "Input a sentence: \n"; getline(cin, stringA);
        if(stringA == "") valid = false;
    }while(valid == false);

    const long unsigned int max = stringA.length() - 1;

    do{
        valid = true;
        cout << "Input two positive integers: \n";
        cin >> i >> j;
        if(j > max) valid = false;
        if(not valid) cout << "Second value is greater than sentence length.\n";
    }while(not valid);

    for(unsigned int k = i; k <= j; k++){
        cout << stringA[k];
    }

    return 0;
}