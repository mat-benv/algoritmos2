/*O algoritmo de Euclides é utilizado para determinar o máximo divisor comum entre dois
números. Elabore uma função recursiva para calcular o MDC.*/

#include <iostream>
using std::cout;

unsigned mcd(unsigned m, unsigned n){
   if(n > m) return mcd(n,m);
   else if(n == 0) return m;
   else if(n > 0) return mcd(n, m%n);
   else return 0;
}

int main(){
   cout << mcd(930, 27) << '\n';
   return 0;
}