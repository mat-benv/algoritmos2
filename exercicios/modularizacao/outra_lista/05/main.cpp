/*Faça um programa que calcule a média dos números primos entre 92 e 1478. Defina uma função
para retornar VERDADEIRO, se o parâmetro for um número primo, e FALSO, caso contrário.*/

#include <iostream>
#include <cstring>
using std::cout, std::cin, std::string;

bool isPrime(unsigned n){
    for (unsigned i = 2; i < n/2; i++){
        if(n%i == 0) return false;
    }
    return true;
}

double positiveIntegerConditionalAverage(unsigned a, unsigned b){ //primes between a and b
   double result, amount=0;
   for(unsigned i = a+1; i < b; i++){
      if(isPrime(i)){
         cout << i << " ";
         result += i;
         amount++;
      }
   }
   return result/amount;
}


int main(){

   unsigned result;

   result = positiveIntegerConditionalAverage(92, 1478);

   cout << '\n' << result << '\n';

   return 0;
}