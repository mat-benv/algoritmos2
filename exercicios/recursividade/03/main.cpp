/*Escreva uma função recursiva para calcular a soma dos múltiplos de 5 entre 0 e 1000.*/

#include <iostream>
using std::cout;

unsigned long multiples_of_5_sum(unsigned n = 0){
   if(n > 1000) return 0;
   if(n%5 == 0) return n+multiples_of_5_sum(n+5);
   else return multiples_of_5_sum(n+1);
}

int main(){
   cout << multiples_of_5_sum() << '\n';
   return 0;
}