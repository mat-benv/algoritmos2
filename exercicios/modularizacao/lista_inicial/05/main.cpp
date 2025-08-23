#include <iostream>
#include <cstring>
using std::string;

/*Faça uma função que verifique se um número é ou não é primo. Crie também um programa para testar tal função.*/

bool isPrime(unsigned n){
    for (unsigned i = 2; i < n/2; i++){
        if(n%i == 0) return false;
    }
    return true;
}

bool isPositiveInt(string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

int main(){

    string number;
    unsigned long n;

    do{
        getline(std::cin, number);
        if(not isPositiveInt(number)) std::cout << "Not a positive integer. \n";
    }while(not isPositiveInt(number));

    n = stol(number);

    if(isPrime(n) and n > 1) std::cout << n << " is prime.\n"; else std::cout << n << " is NOT prime.\n";
    
    return 0;
}