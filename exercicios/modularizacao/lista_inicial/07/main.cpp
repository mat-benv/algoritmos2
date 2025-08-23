#include <iostream>
#include <cstring>
using std::string, std::cout, std::cin;
/*Escreva um procedimento que receba um número inteiro e o imprima na forma extensa (p.ex. para 1 a saída
desejada é “Um”). O código deve gerar o extenso dos números de 0 até 10, inclusive. Caso um número não
compatível seja recebido, deve-se mostrar uma mensagem de erro. Crie também um programa que leia um valor
inteiro e chame o procedimento criado para mostrar o número extenso*/

bool isPositiveInt(string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

string numberName(unsigned n){
    string list[11]{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
    return list[n];
}

int main(){

    string numberName(unsigned), nS;
    bool isPositiveInt(string);
    int n;

    do{
        cout << "Input an integer from 0 to 10: \n"; getline(cin, nS);
        if(not isPositiveInt(nS)){
            cout << "Not a positive integer. \n";
            continue;
        }
        n = atoi(nS.c_str());
        if(n > 10) cout << "Input larger than 10 \n";
    }while(n > 10);

    nS = numberName(n);

    cout << nS << "\n";

    return 0;
}