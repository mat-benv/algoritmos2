/*Construa um procedimento recursivo para verificar a existência de determinado valor y
em um vetor X de n (1  n  10) elementos inteiros*/

#include <iostream>

void in_vector(int y, unsigned n, int x[]){
   if(n != 0){
      in_vector(y, n-1, x);
      if(y == x[n-1]) std::cout << "In position " << n << '\n';
   } else {
      if(y == x[0]) std::cout << "In position 1.\n";
      std::cout << "End of search.\n";
      }
   }

int main(){
   int x[10]{0,1,2,3,4,3,5,6,9,3};
   in_vector(3, 10, x);
   return 0;
}