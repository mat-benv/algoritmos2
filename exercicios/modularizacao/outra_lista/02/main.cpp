#include <iostream>
#include <cstring>
using std::cin, std::cout, std::string;

/*Faça um programa que leia x pares de valores (n, r) e escreva, para cada par de valor, a combinação
de n elementos agrupados r a r. Defina uma função para calcular a combinação de n elementos
agrupados r a r utilizando a fórmula abaixo:*/

bool isPositiveInt(string);
unsigned input(string);
unsigned long long combination(unsigned, unsigned, unsigned);
unsigned long long factorial(unsigned);

bool isPositiveInt(string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

unsigned input(string msg){ //change type as needed, useful parameters can also be passed
   string s;
   do{
      cout << msg << "\n"; getline(cin, s);
      if(not isPositiveInt(s)) cout << "Not a valid input. Try again. \n";
   }while(not isPositiveInt(s));
   return atof(s.c_str());
}

unsigned long long factorial(unsigned n){
   unsigned long long fact = n;
   if(n == 0 or n == 1) return 1;
   for(unsigned i = n-1; i > 1; i--){
      fact *= i;
   }
   return fact;
}

unsigned long long combination(unsigned n, unsigned r, unsigned q){
   
   unsigned long long dem = n;
   
   for(unsigned i = n-1; i > r; i--){
      dem *= i;
   }

   return dem/factorial(q);
}

int main(){

   unsigned x, n, r, nMenosR;
   unsigned long long c;

   x = input("How many value pairs: ");

   for(unsigned i = 0; i < x; i++){
      do{
         n = input("Input the first element of the pair: ");
         r = input("Input the second element of the pair: ");
      if(n < r) cout << "The first element can not be smaller than the second. \n";
      if(n == 0 or r == 0) cout << "No element can be 0\n";
      }while(n < r or n == 0 or r == 0);
      nMenosR = n - r;
      if(r > nMenosR){
         c = combination(n, r, nMenosR);
      } else {
         c = combination(n, nMenosR, r);
      }
      cout << "The combination is " << c << "\n";
   }

   return 0;
}