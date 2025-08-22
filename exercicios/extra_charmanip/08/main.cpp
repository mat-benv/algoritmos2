#include <iostream>
#include <cstring>
using namespace std;

/*Faça um programa que leia duas strings e verifique se a segunda string está contida
no final da primeira, retornando o resultado da verificação.*/

int main(){

    string strA, strB;
    bool contains=true;
    long unsigned sizeA, sizeB;

    do{
        cout << "Input a string: \n"; getline(cin, strA);
    }while(strA.empty());

    do{
        cout << "Input another string: \n"; getline(cin, strB);
    }while(strB.empty());

    sizeA = strA.length();
    sizeB = strB.length();

    if(sizeA < sizeB){
        cout << "The first string can't contain the second because it's shorter. \n";
    } else if(strA == strB){
        cout << "The strings are equal. \n";
    } else {
        for(long unsigned i = 0; i < sizeB; i++){
            if(strA[sizeA - 1 - i] != strB[sizeB - 1 - i]){
                contains = false;
                break;
            }
        }
        if(contains){
            cout << "The first string contains the second at it's end. \n";
        } else {
            cout << "The first string does NOT contain the second at it's end. \n";
        }
    }

    return 0;
}