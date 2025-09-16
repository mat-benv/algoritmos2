/*Escreva uma função recursiva para calcular o produto escalar entre dois vetores
quaisquer X [ x1, x2, ..., xn ] e Y [ y1, y2, ..., yn ], de tamanho n (1  n  10).
produto escalar = x1 * y1 + x2 * y2 + ... + xn * yn*/

#include <iostream>

double scalar_product(unsigned n, double v[], double w[]){
   if(n == 0) return v[0]*w[0];
   else{
      return v[n-1]*w[n-1] + scalar_product(n-1, v, w);
   }
}

int main(){
   double v[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
   w[10]{9,8,7,6,5,4,3,2,1,0};

   std::cout << scalar_product(10, v, w) << '\n';
   return 0;
}