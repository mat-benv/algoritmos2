/*Elabore uma função sem retorno (procedimento) que receba um vetor X de n (1  n  10)
elementos inteiros e devolva um vetor Y contendo apenas os elementos primos de X. Crie um
programa para testar esta função.*/

#include <iostream>
#include <cstring>
using namespace std;

#define LMIN 1
#define LMAX 10

void printFloatVector(unsigned, double[], string);
void primeVector_float(unsigned, double[], double[]);
bool isPrime(unsigned);

int main(){
   unsigned n = LMAX;
   double arX[LMAX]{1,2,3,4,5,6,7,8,9,10}, arY[LMAX]{0.0};

   primeVector_float(n, arX, arY);

   printFloatVector(n, arY, "");

   return 0;
}

void primeVector_float(unsigned n, double arX[], double arY[]){
   for(unsigned i = 0, j = 0; i < n; i++){
      if(isPrime(arX[i])){
         arY[j] = arX[i];
         j++;
      }
   }
}

void printFloatVector(unsigned n, double vec[], string msg=""){
   cout << msg << '\n';
   for(unsigned i = 0; i < n; i++){
      cout << "[" << vec[i] << "] ";
   }
   cout << '\n';
}

bool isPrime(unsigned n){
    if(n < 2 or n == 4) return false;
    if(n == 2) return true;
    for (unsigned i = 2; i < n/2; i++){
        if(n%i == 0) return false;
    }
    return true;
}