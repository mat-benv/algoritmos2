/*Faça um programa que leia duas matrizes de inteiros AnXm e BmXp (2 n,m,p 10), calcule e
mostre a matriz resultante da multiplicação de AxB.*/

#include <iostream>
#include <cstring>
using namespace std;

#define MIN 2
#define MAX 10

bool isInt(string, bool=true);
unsigned iinput(string, bool=true);
void readMatrix_integer(unsigned, unsigned, int[][MAX]);
void printMatrix_integer(unsigned, unsigned, int[][MAX]);
void readMatrixSize(unsigned &, unsigned &);
void matrixMultiplication_integer(unsigned, unsigned, unsigned, int[][MAX], int[][MAX], int[][MAX]);
unsigned matBColumns();

int main(){
   unsigned n, m, p;
   int matA[MAX][MAX], matB[MAX][MAX], matC[MAX][MAX]{0};

   cout << "Matrix A: \n";
   readMatrixSize(n, m);

   readMatrix_integer(n, m, matA);

   p = matBColumns();
   readMatrix_integer(m, p, matB);

   matrixMultiplication_integer(n, m, p, matA, matB, matC);

   cout << "Matrix A: \n";
   printMatrix_integer(n, m, matA);
   cout << "Matrix B: \n";
   printMatrix_integer(m, p, matB);
   cout << "Product Matrix: \n";
   printMatrix_integer(n, p, matC);

   return 0;
}

void matrixMultiplication_integer(unsigned n, unsigned m, unsigned p, int matA[][MAX], int matB[][MAX], int matC[][MAX]){
   for(unsigned i = 0; i < n; i++){
      for(unsigned j = 0; j < p; j++){
         for(unsigned k = 0; k < m; k++){
            matC[i][j] += matA[i][k]*matB[k][j];
         }
      }
   }
}

unsigned matBColumns(){
   unsigned p;
   cout << "Matrix B has to have the same amount of lines as A has of columns so they can be multipliable.\n"
   << "Therefore, B line amount is set. Input how many columns B has: \n";
   do{
      p = iinput("", false);
      if(p < MIN or p > MAX) cout << "Value out of range.\n";
   }while(p < MIN or p > MAX);
   return p;
}

void readMatrixSize(unsigned &n, unsigned &m){
   do{
      n = iinput("How many lines: ", false);
      if(n < MIN or n > MAX) cout << "Value out of accepted range. Try between " << MIN << " and " << MAX << ". \n";
   }while(n < MIN or n > MAX);
   do{
      m = iinput("How many columns: ", false);
      if(m < MIN or m > MAX) cout << "Value out of accepted range. Try between " << MIN << " and " << MAX << ". \n";
   }while(m < MIN or m > MAX);
}

void printMatrix_integer(unsigned n, unsigned m, int mat[][MAX]){
   for(unsigned i = 0; i < n; i++){
      cout << "|";
      for(unsigned j = 0; j < m; j++){
         cout << " " << mat[i][j];
      }
      cout << " |\t\n";
   }
}

void readMatrix_integer(unsigned n, unsigned m, int mat[][MAX]){
   for(unsigned i = 0; i < n; i++){
      for(unsigned j = 0; j < m; j++){
         cout << "Input element " << i+1 << "," << j+1 << ": ";
         mat[i][j] = iinput("", true);
      }
   }
}

bool isInt(string s, bool acceptNegative){
   if(acceptNegative){
      if(not isdigit(s[0]) and s[0] != '-') return false;
   }
   for(unsigned i = 1; i < s.length(); i++){
      if(not isdigit(s[i])) return false;
   }
   return true;
}

unsigned iinput(string msg, bool acceptNegative){
   string s;
   do{
      cout << msg; getline(cin, s);
      if(not isInt(s, acceptNegative)) cout << "Not a valid input. Try again. \n";
   }while(not isInt(s, acceptNegative));
   return atoi(s.c_str());
}