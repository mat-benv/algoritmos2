#include <iostream>
#include <cstring>
using std::string;
/*Um número é dito ser capicua quando lido da esquerda para a direita é o mesmo que quando lido da direita para
a esquerda. O ano 2002, por exemplo, é capicua. Então, elabore uma função para verificar se um número possui
essa característica. Considere apenas números com 4 dígitos. Caso o número seja capicua, a função deve retornar
1 e 0 em caso contrário. Crie também um programa para testar tal função.*/

#define correctLength 4

bool isCorrectLength(string s){
    if(s.length() == correctLength) return true; else return false;
}

bool isPositiveInt(string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

bool isCapicua(string s){
    for(unsigned i = 0, j = correctLength - 1; i < correctLength/2; i++, j--){
        if(s[i] != s[j]) return 0;
    }
    return 1;
}

int main(){

    string number;

    do{
        getline(std::cin, number);
        if(not isCorrectLength(number)) std::cout << "Incorrect length. \n";
        if(not isPositiveInt(number)) std:: cout << "Not a positive 4 digit integer. \n";
    }while(not isCorrectLength(number) or not isPositiveInt(number));

    if(isCapicua(number)) std::cout << number << " is capicua. \n";
    else std::cout << number << " is NOT capicua. \n";

    return 0;
}