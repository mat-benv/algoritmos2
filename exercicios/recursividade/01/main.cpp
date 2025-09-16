/*Desenvolva uma função recursiva para calcular o fatorial de um número inteiro.*/

#include <iostream>
using std::cout;

unsigned long long recursive_factorial(unsigned n){
   if(n == 1) return 1;
   if(n == 0) return 1;
   return n*recursive_factorial(n-1);
}

int main(){
   cout << recursive_factorial(5) << '\n';
   return 0;
}