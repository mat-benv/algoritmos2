/*Faça um programa que leia uma matriz AnXm (2  n  3, 4  m  10) de números reais e após,
gere e mostre uma matriz B que seja a matriz transposta de A*/

#include <iostream>
#include <cstring>
using namespace std;

#define MIN_N 2
#define MAX_N 3
#define MIN_M 4
#define MAX_M 10
#define MAX_NM 10 //to correctly pass parameters, should be equal to highest MAX constant

bool isFloat(string &);
double finput(string);
bool isInt(string, bool);
int iinput(string, bool);
void readMatrixSize(unsigned &, unsigned &);
void readMatrix_float(unsigned, unsigned, double[][MAX_NM]);
void transposeMatrix_float(unsigned, unsigned, double[][MAX_NM], double[][MAX_NM]);
void printMatrix_float(unsigned, unsigned, double[][MAX_NM]);

int main(){

    unsigned n, m;
    double mat[MAX_N][MAX_NM]{0.0}, mat_t[MAX_M][MAX_NM]{0.0};

    readMatrixSize(n, m);
    readMatrix_float(n, m, mat);
    
    transposeMatrix_float(n, m, mat, mat_t);

    cout << "Original matrix: \n";
    printMatrix_float(n, m, mat);
    cout << "Transposed matrix: \n";
    printMatrix_float(m, n, mat_t);

    return 0;
}

bool isFloat(string &n){
   bool point = false;
   if(n.empty()){
      return false;
   } else if(not isdigit(n[0]) and n[0] != '-'){
      return false;
   } else {
      for(unsigned i = 1; i < n.length(); i++){
         if(not isdigit(n[i])){
            if(not point){
               if(n[i] == '.' or n[i] == ','){
                  point = true;
                  if(n[i] == ',') n[i] = '.';
               } else return false;
            } else return false;
         }
      }
   }
   return true;
}

double finput(string msg){ //change type as needed, useful parameters can also be passed
   string s;
   do{
      cout << msg << "\n"; getline(cin, s);
      if(not isFloat(s)) cout << "Not a valid input. Try again. \n";
   }while(not isFloat(s));
   return atof(s.c_str());
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

int iinput(string msg, bool acceptNegative = true){
   string s;
   do{
      cout << msg; getline(cin, s);
      if(not isInt(s, acceptNegative)) cout << "Not a valid input. Try again. \n";
   }while(not isInt(s, acceptNegative));
   return atoi(s.c_str());
}

void readMatrixSize(unsigned &n, unsigned &m){
   do{
      n = iinput("How many lines: ", true);
      if(n < MIN_N or n > MAX_N) cout << "Value out of accepted range. Try between " << MIN_N << " and " << MAX_N << ". \n";
   }while(n < MIN_N or n > MAX_N);
   do{
      m = iinput("How many columns: ", true);
      if(m < MIN_M or m > MAX_M) cout << "Value out of accepted range. Try between " << MIN_M << " and " << MAX_M << ". \n";
   }while(m < MIN_M or m > MAX_M);
}

void readMatrix_float(unsigned n, unsigned m, double mat[][MAX_NM]){
   for(unsigned i = 0; i < n; i++){
      for(unsigned j = 0; j < m; j++){
         cout << "Input element " << i+1 << "," << j+1 << ": ";
         mat[i][j] = finput("");
      }
   }
}

void transposeMatrix_float(unsigned n, unsigned m, double mat[][MAX_NM], double mat_t[][MAX_NM]){
    for(unsigned i = 0; i < n; i++){
        for(unsigned j = 0; j < m; j++){
            mat_t[j][i] = mat[i][j];
        }
    }
}

void printMatrix_float(unsigned n, unsigned m, double mat[][MAX_NM]){
   for(unsigned i = 0; i < n; i++){
      cout << "|";
      for(unsigned j = 0; j < m; j++){
         cout << " " << mat[i][j];
      }
      cout << " |\n";
   }
}