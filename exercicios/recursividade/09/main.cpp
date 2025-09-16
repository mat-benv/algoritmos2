/*Escreva uma função recursiva para verificar se dois vetores X e Y de n (1  n  10)
elementos inteiros são iguais, ou seja, xi = yi,  1  i  n.*/

#include <iostream>

bool equal_arrays(unsigned n, int x[], int y[]){
   if(n == 0){
      if(x[0] == y[0]) return true;
      else return false;
   } else {
      if(x[n-1] != y[n-1]) return false;
      else return equal_arrays(n-1, x, y);
   }
}

int main(){
   int x[3]{1,2,3}, y[3]{1,2,3};

   if(equal_arrays(3, x, y)) std::cout << "True.\n";
   else std::cout << "False.\n";
}