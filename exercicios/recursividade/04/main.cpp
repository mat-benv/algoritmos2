/*4. Construa um procedimento recursivo para escrever os n primeiros termos da série
1 4 3 16 5 36 7 64 9 100 ...*/

#include <iostream>
#include <cmath>
using std::cout;

void squared_even_series(unsigned n){
   if(n > 1){
      squared_even_series(n-1);
      if(n%2 == 0) cout << pow(n,2);
      else cout << n;
      cout << ' ';
   } else {
      cout << 1 << ' ';
   }
}

int main(){
   squared_even_series(10);
   cout << '\n';
   return 0;
}