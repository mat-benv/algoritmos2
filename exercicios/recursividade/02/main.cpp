/*Desenvolva uma função recursiva para calcular a soma dos números naturais de 1 a n.*/

#include <iostream>
using std::cout;

long long unsigned natural_numbers_sum(unsigned n){
   if(n == 1) return 1;
   return n+natural_numbers_sum(n-1);
}

int main(){
   cout << natural_numbers_sum(100) << '\n';
   return 0;
}