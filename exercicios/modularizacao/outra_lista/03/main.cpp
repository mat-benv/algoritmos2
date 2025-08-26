#include <iostream>
#include <cstring>
using std::cout, std::cin, std::string;

/*Faça um programa que calcule o valor de "E" usando a série abaixo. O programa deve escrever os
termos na tela e ao final a soma calculada.*/

unsigned long long factorial(unsigned);
double eSum(unsigned);
unsigned input(string);
bool isPositiveInt(string);

unsigned long long factorial(unsigned n){
   unsigned long long fact = n;
   if(n == 0 or n == 1) return 1;
   for(unsigned i = n-1; i > 1; i--){
      fact *= i;
   }
   return fact;
}

double eSum(unsigned n){
   double e = 2;
   if(n < 2) return e;
   for(unsigned i = 2; i <= n-1; i++){
      e += 1.0/factorial(i);
   }
   return e;
}

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
   return atoi(s.c_str());
}

int main(){

   unsigned n;
   double e;
   do{
      n = input("Input value for series: ");
      if(n == 0) cout << "Value can't be 0.\n";
   }while(n == 0);

   e = eSum(n);

   cout << "Result: " << e << "\n";

   return 0;
}
