#include <iostream>

/*Criar uma função que determine se um caractere, recebido como parâmetro, é ou não uma letra do alfabeto. A
função deve retornar 1 caso positivo e 0 em caso contrário. Crie também um programa para testar tal função.*/

bool isAlpha(char c){
    if(toupper(c) > 64 and toupper(c) < 91) return 1; else return 0;
}

int main(){
    char c;
    bool isAlpha(char);

    c = std::cin.get();

    if(isAlpha(c)) std::cout << c << " is in the alphabet.\n";
    else std::cout << c << " is not in the alphabet. \n";

    return 0;
}