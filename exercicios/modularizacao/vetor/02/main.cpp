/*Faça um programa que leia dois vetores V e W, ambos com n (1 n 15) números reais.
Determine os vetores resultantes da soma de V e W e da multiplicação de V e W, elemento a
elemento. Determine também o produto escalar de V e W, definido como:  (vi * wi) = v1 * w1 +
v2 * w2 + ...+ vn * wn. Caso o produto escalar calculado seja igual a zero, deve-se informar que
os vetores são ORTOGONAIS.*/

#include <iostream>
#include <cstring>
using namespace std;

#define LMIN 1
#define LMAX 15

bool isFloat(string &);
double finput(string);
bool isPositiveInt(string);
unsigned iinput(string);
string ordinalSuffix(unsigned);
unsigned readVectorSize(string, unsigned, unsigned);
void readFloatVecValues(unsigned, double[]);
void floatValue2ValueSum(unsigned, double[], double[], double[]);
void floatValue2ValueProduct(unsigned, double[], double[], double[]);
double floatScalarProduct(unsigned, double[], double[]);
void printFloatVector(unsigned, double[], string);

int main(){

   unsigned n;
   double vecV[LMAX], vecW[LMAX], sumVec[LMAX], productVec[LMAX], x;

   n = readVectorSize("Input amount of values to read: ", LMIN, LMAX);

   cout << "Vector V: \n";
   readFloatVecValues(n, vecV);

   cout << "Vector W: \n";
   readFloatVecValues(n, vecW);

   floatValue2ValueSum(n, vecV, vecW, sumVec);
   printFloatVector(n, sumVec, "Sum vector: ");

   floatValue2ValueProduct(n, vecV, vecW, productVec);
   printFloatVector(n, productVec, "Product vector: ");

   x = floatScalarProduct(n, vecV, vecW);
   cout << "Scalar Product: " << x << '\n';

   return 0;
}

string ordinalSuffix(unsigned n){
    switch(n){
        case 1: return "st";
            break;
        case 2: return "nd";
            break;
        case 3: return "rd";
            break;
        case 0: return "";
            break;
        default: return "th";
    }
}

bool isPositiveInt(string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

unsigned iinput(string msg){ //change type as needed, useful parameters can also be passed
   string s;
   do{
      cout << msg; getline(cin, s);
      if(not isPositiveInt(s)) cout << "Not a valid input. Try again. \n";
   }while(not isPositiveInt(s));
   return atoi(s.c_str());
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

unsigned readVectorSize(string msg, unsigned min, unsigned max){
   unsigned n;
   while(true){
      n = iinput(msg);
      if(n >= min and n <= max) return n;
      else cout << "Invalid input, try between " << min << " and " << max << ". \n";
   }
}

void readFloatVecValues(unsigned n, double vec[]){
   for(unsigned i = 0; i < n; i++){
      cout << "Input " << i+1 << ordinalSuffix(i+1) << " value:";
      vec[i] = finput("");
   }
}

void floatValue2ValueSum(unsigned n, double vecV[], double vecW[], double sumVec[]){
   for(unsigned i = 0; i < n; i++){
      sumVec[i] = vecV[i] + vecW[i];
   }
}

void floatValue2ValueProduct(unsigned n, double vecV[], double vecW[], double productVec[]){
   for(unsigned i = 0; i < n; i++){
      productVec[i] = vecV[i] * vecW[i];
   }
}

double floatScalarProduct(unsigned n, double vecV[], double vecW[]){
   double productVec[n], scalarProduct = 0.0;
   floatValue2ValueProduct(n, vecV, vecW, productVec);
   for(unsigned i = 0; i < n; i++) scalarProduct += productVec[i];
   return scalarProduct;
}

void printFloatVector(unsigned n, double vec[], string msg){
   cout << msg << '\n';
   for(unsigned i = 0; i < n; i++){
      cout << "[" << vec[i] << "] ";
   }
   cout << '\n';
}