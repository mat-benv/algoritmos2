/*Faça um programa que leia n (1 n 10) números reais e armazene-os em um vetor. Elabore
uma função para ordenar o vetor. Mostre o vetor após a ordenação.*/

#include <iostream>
#include <cstring>
using namespace std;

#define LMIN 1
#define LMAX 10

bool isFloat(string &);
double finput(string);
bool isPositiveInt(string);
unsigned iinput(string);
string ordinal_suffix(unsigned);
unsigned readVectorSize(string, unsigned, unsigned);
void readFloatVecValues(unsigned, double[]);
void floatDirectSelectionSort(unsigned, double[]);
void printFloatVector(unsigned, double[], string);
void swap_float(double &, double &);


int main(){
   
   double array[LMAX]{0.0};
   unsigned n;

   n = readVectorSize("How many values: ", LMIN, LMAX);
   readFloatVecValues(n, array);

   floatDirectSelectionSort(n, array);

   printFloatVector(n, array, "Sorted array: ");

   return 0;
}

void swap_float(double &x, double &y){
   double aux;
   aux = x;
   x = y;
   y = aux;
}

void floatDirectSelectionSort(unsigned n, double array[]){
   unsigned pos;
   for(unsigned i = 0; i < n-1; i++){
      pos = i;
      for(unsigned j = i+1; j < n; j++){
         if(array[j] < array[pos]){
            pos = j;
         }
      }
      swap_float(array[i], array[pos]);
   }
}

void printFloatVector(unsigned n, double vec[], string msg=""){
   cout << msg << '\n';
   for(unsigned i = 0; i < n; i++){
      cout << "[" << vec[i] << "] ";
   }
   cout << '\n';
}

string ordinal_suffix(unsigned n){
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
      cout << "Input " << i+1 << ordinal_suffix(i+1) << " value:";
      vec[i] = finput("");
   }
}