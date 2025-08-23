#include <iostream>
#include <cstring>
using std::string;
using std::cout, std::cin;
/*Elabore um procedimento que receba um número inteiro e escreva o mês correspondente ao número. Por
exemplo, 2 corresponde a “fevereiro”. Não aceitar valores inválidos. Faça um programa que leia um valor e
chame o procedimento criado.*/

string monthString(unsigned n){
    string monthVector[12]{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return monthVector[n-1];
}

bool isPositiveInt(string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

int main(){
    string monthString(unsigned), monthN, monthS;
    bool isPositiveInt(string);
    int monthInt;

    do{
        cout << "Input month number: \n"; getline(cin, monthN);
        if(not isPositiveInt(monthN)){
            cout << "Not a positive integer. \n"; 
            continue;
        }
        monthInt = atoi(monthN.c_str());
        if(monthInt > 12 or monthInt < 1) cout << "Invalid input, try again. \n";
    }while(monthInt > 12 or monthInt < 1);
    monthS = monthString(monthInt);
    cout << monthS << " \n";

    return 0;
}