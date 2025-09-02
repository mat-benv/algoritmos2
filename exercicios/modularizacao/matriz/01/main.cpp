/*Escreva um programa que, para uma matriz quadrada A de ordem n (2 n 10) de inteiros,
faça:
a) leia a matriz
b) some os elementos da 2ª coluna
c) multiplique os elementos de cada linha e armazene-os em um vetor
d) permute os elementos das linhas p e q e mostre novamente a matriz
e) verifique se a matriz A é simétrica (matriz quadrada e aji = aij)
f) determine a posição do maior elemento da matriz*/

#include <iostream>
#include <cstring>
using namespace std;

#define LMIN 2
#define LMAX 10

bool isInt(string, bool);
unsigned iinput(string, bool);
void readMatrixSize_integer(unsigned &, unsigned &);
void readMatrix_integer(unsigned, unsigned, int[][LMAX]);
int matrixColumnSum_integer(unsigned, unsigned, int[][LMAX]);
void linesProduct2Vector_integer(unsigned, unsigned, int[][LMAX], int[]);
void swapLines_integer(unsigned, unsigned, int[][LMAX]);
bool isSimetrical_integer(unsigned, unsigned, int[][LMAX]);
void biggestValuePositionMatrix_integer(unsigned, unsigned, int[][LMAX], unsigned &, unsigned &);
void printMatrix_integer(unsigned, unsigned, int[][LMAX]);
void printIntVector(unsigned, int[], string);

int main(){

   unsigned m, n, biggestPos, smallestPos;
   int mat[LMAX][LMAX]{0}, columnSum = 0, vec[LMAX]{0};

   readMatrixSize_integer(m, n);
   readMatrix_integer(m, n, mat[][LMAX]);

   columnSum = matrixColumnSum_integer(m, n, mat[][LMAX]);
   cout << "Soma da coluna: " << columnSum;

   linesProduct2Vector_integer(m, n, mat[][LMAX], vec[]);
   printIntVector(n, vec[]);

   swapLines_integer(m, n, mat[][LMAX]);
   printMatrix_integer(m, n, mat[][LMAX]);

   biggestValuePositionMatrix_integer(m, n, mat[][LMAX], biggestPos, smallestPos);
   cout << "Biggest: " << biggestPos << " Smallest: " << smallestPos;

   return 0;
}

void printIntVector(unsigned n, int vec[], string msg=""){
   cout << msg << '\n';
   for(unsigned i = 0; i < n; i++){
      cout << "[" << vec[i] << "] ";
   }
   cout << '\n';
}

void printMatrix_integer(unsigned m, unsigned n, int mat[][LMAX]){
   for(unsigned i = 0; i < m; i++){
      cout << "|";
      for(unsigned j = 0; j < n; j++){
         cout << " " << mat[i][j];
      }
      cout << " |\n";
   }
}

void biggestValuePositionMatrix_integer(unsigned m, unsigned n, int mat[][LMAX], unsigned &posM, unsigned &posN){
   int value = mat[0][0];
   for(unsigned i = 0; i < m; i++){
      for(unsigned j = 0; j < n; j++){
         if(mat[i][j] > value){
            value = mat[i][j];
            posM = i;
            posN = j;
         }
      }
   }
}

bool isSimetrical_integer(unsigned m, unsigned n, int mat[][LMAX]){
   if(m != n) return false;
   for(unsigned i = 0; i < m/2; i++){
      for(unsigned j = 0; j < n/2; j++){
         if(mat[i][j] != mat[j][i]) return false;
      }
   }
   return true;
}

void readMatrixSize_integer(unsigned &m, unsigned &n){
   do{
      m = iinput("How many lines: ", true);
      if(m < LMIN or m > LMAX) cout << "Value out of accepted range. Try between " << LMIN << " and " << LMAX << ". \n";
   }while(m < LMIN or m > LMAX);
   do{
      n = iinput("How many lines: ", true);
      if(n < LMIN or n > LMAX) cout << "Value out of accepted range. Try between " << LMIN << " and " << LMAX << ". \n";
   }while(n < LMIN or n > LMAX);
}

void readMatrix_integer(unsigned m, unsigned n, int mat[][LMAX]){
   for(unsigned i = 0; i < m; i++){
      for(unsigned j = 0; j < n; j++){
         cout << "Input element " << i+1 << "," << j+1 << ": ";
         mat[i][j] = iinput("", true);
      }
   }
}

int matrixColumnSum_integer(unsigned m, unsigned n, int mat[][LMAX]){
   int sum = 0;
   unsigned column;
   do{
      column = iinput("Which column to sum: ", false);
      if(column < 1 or column > n) cout << "Invalid input, out of range. \n";
   }while(column < 1 or column > n);
   for(unsigned i = 0; i < m; i++){
      sum += mat[i][column];
   }
   return sum;
}

void swapLines_integer(unsigned m, unsigned n, int mat[][LMAX]){
   unsigned a, b;
   int aux;
   do{
      a = iinput("Which lines to swap.\n First Line: ", false);
      if(a < 1 or a > m) cout << "Input out of range. \n";
   }while(a < 1 or a > m);
   do{
      b = iinput("Second Line: ", false);
      if(b < 1 or b > m) cout << "Input out of range. \n";
      if(b == a) cout << "Can't be the same as the first.\n";
   }while(b < 1 or b > m or b == a);

   for(unsigned i = 0; i < n; i++){
      aux = mat[a][i];
      mat[a][i] = mat[b][i];
      mat[b][i] = aux;
   }
}

void linesProduct2Vector_integer(unsigned n, unsigned m, int mat[][LMAX], int vec[]){
   for(unsigned i = 0; i < n; i++){
      vec[i] = 0;
      for(unsigned j = 0; j < m; j++){
         vec[i] += mat[i][j];
      }
   }
}

bool isInt(string s, bool acceptNegative = true){
   if(acceptNegative){
      if(not isdigit(s[0]) and s[0] != '-') return false;
   }
   for(unsigned i = 1; i < s.length(); i++){
      if(not isdigit(s[i])) return false;
   }
   return true;
}

unsigned iinput(string msg, bool acceptNegative = true){
   string s;
   do{
      cout << msg; getline(cin, s);
      if(not isInt(s, acceptNegative)) cout << "Not a valid input. Try again. \n";
   }while(not isInt(s, acceptNegative));
   return atoi(s.c_str());
}

