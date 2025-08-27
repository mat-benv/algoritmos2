/*Dois ímpares consecutivos e primos são chamados primos gêmeos. Faça um programa que escreva
os primos gêmeos menores que 1000.*/

#include <iostream>
using std::cout;

bool isPrime(unsigned n){
    for (unsigned i = 2; i < n/2; i++){
        if(n%i == 0) return false;
    }
    return true;
}

void isTwinPrimes(unsigned n){ //range

   for(unsigned i = 5; i <= n; i += 2){
      if(isPrime(i) and isPrime(i-2)){
         cout << i-2 << " and " << i << '\n';
      }
   }

}

int main(){

   isTwinPrimes(1000);

   return 0;
}