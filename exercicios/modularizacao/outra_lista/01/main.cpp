#include <iostream>
#include <cstring>
using std:: cout, std::cin, std::string;

/*Faça um programa que leia um número inteiro n maior ou igual a zero e calcule o fatorial de n
(usualmente escrito como n!). O fatorial é calculado como o produto n * (n -1) * (n - 2) * ... * 2 * 1. Isto
nada mais é do que uma série de multiplicações repetidas, onde o multiplicador é reduzido de 1 antes
de cada multiplicação. Defina uma função para calcular o fatorial.*/

bool isPositiveInt(string);
unsigned long long factorial(unsigned long long);
unsigned long long input();

bool isPositiveInt(string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

unsigned long long factorial(unsigned long long n){
   unsigned long long fact = n;
   for(unsigned i = n-1; i > 1; i--){
      fact *= i;
   }
   return fact;
}

unsigned long long input(){ //change type as needed, useful parameters can also be passed
   string s;
   do{
      cout << "Input a positive integer: \n"; getline(cin, s);
      if(not isPositiveInt(s)) cout << "Not a valid input. Try again. \n"; //chage function call as needed
   }while(not isPositiveInt(s));
   return strtoull(s.c_str(), nullptr, 10);
}

int main(){
   unsigned long long n, fact;

   n = input();

   fact = factorial(n);

   cout << fact << "\n";


   return 0;
}