#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/*Faça um programa recebe uma string A e duas letras L1 e L2, e troque todas as
ocorrências da letra L1 pela letra L2. Ao final mostre a string A atualizada.*/

int main(){

    string stringA;
    char l1=' ', l2=' ';
    bool valid;

    do{
        valid = true;
        cout << "Input a sentence: \n"; getline(cin, stringA);
        if(stringA == "") valid = false;
    }while(not valid);

    do{
        valid = true;
        cout << "Input the letter to be replaced: \n";
        cin >> l1;
        if(not isalpha(l1)) valid = false;
        if(not valid) cout << "Invalid input, try again.\n";
    }while(not valid);

    do{
        valid = true;
        cout << "Input the letter to replace " << l1 << ": \n";
        cin >> l2;
        if(not isalpha(l2)) valid = false;
        if(not valid) cout << "Invalid input, try again.\n";
    }while(not valid);

    for(unsigned int i = 0; i < stringA.length(); i++){
        if(toupper(stringA[i]) == toupper(l1)) stringA[i] = l2;
    }

    cout << stringA;

    return 0;
}