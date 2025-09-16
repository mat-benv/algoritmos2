/*Escreva uma função recursiva que calcule o valor do polinômio
pn(x) = anxn + an-1xn-1 + an-2xn-2 + ... + a1x + a0*/

#include <iostream>
#include <cmath>
using std::cout;

unsigned long long p(unsigned n, unsigned x){
   double a;
   cout << "Input a" << n << ": "; std::cin >> a;
   if(n == 0) return a;
   return a*pow(x, n) + p(n-1, x);
}

int main(){
   unsigned long long y;
   y = p(5, 2);
   cout << y << '\n';
   return 0;
}