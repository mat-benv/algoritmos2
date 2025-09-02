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
void matrixMultiplication_integer(unsigned, unsigned, int[][MAX], int[][MAX], int[][MAX]);

//TODO
void matrixMultiplication_integer(unsigned n, unsigned m, unsigned p, int matA[][MAX], int matB[][MAX], int matC[][MAX]){
    for(unsigned i = 0; i < n; i++){

    }
}

void readMatrixSize(unsigned &n, unsigned &m){
   do{
      n = iinput("How many lines: ", true);
      if(n < MIN or n > MAX) cout << "Value out of accepted range. Try between " << MIN << " and " << MAX << ". \n";
   }while(n < MIN or n > MAX);
   do{
      m = iinput("How many columns: ", true);
      if(m < MIN or m > MAX) cout << "Value out of accepted range. Try between " << MIN << " and " << MAX << ". \n";
   }while(m < MIN or m > MAX);
}

void printMatrix_integer(unsigned m, unsigned n, int mat[][MAX]){
   for(unsigned i = 0; i < m; i++){
      cout << "|";
      for(unsigned j = 0; j < n; j++){
         cout << " " << mat[i][j];
      }
      cout << " |\n";
   }
}

void readMatrix_integer(unsigned m, unsigned n, int mat[][MAX]){
   for(unsigned i = 0; i < m; i++){
      for(unsigned j = 0; j < n; j++){
         cout << "Input element " << i+1 << "," << j+1 << ": ";
         mat[i][j] = iinput("", true);
      }
   }
}

bool isInt(string s, bool acceptNegative=true){
   if(acceptNegative){
      if(not isdigit(s[0]) and s[0] != '-') return false;
   }
   for(unsigned i = 1; i < s.length(); i++){
      if(not isdigit(s[i])) return false;
   }
   return true;
}

unsigned iinput(string msg, bool acceptNegative=true){
   string s;
   do{
      cout << msg; getline(cin, s);
      if(not isInt(s, acceptNegative)) cout << "Not a valid input. Try again. \n";
   }while(not isInt(s, acceptNegative));
   return atoi(s.c_str());
}