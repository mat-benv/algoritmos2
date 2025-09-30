/*Dado um conjunto de n (1 n 10) números reais, faça um programa que escreva a
localização (índice) do primeiro elemento negativo, caso exista. Desenvolva uma função para
retornar a referida localização. Na hipótese de não existir elemento negativo, retornar -1
(considerando que este índice não existe em um vetor).*/

#include <iostream>
#include <cstring>
using namespace std;

bool isFloat(string &);
double finput(string);
bool isPositiveInt(string);
unsigned iinput(string);
string ordinal_suffix(unsigned);
unsigned readVectorSize(string, unsigned, unsigned);
void readFloatVecValues(unsigned, double[]);
void printFloatVector(unsigned, double[], string);
int scry4Negative_floatArray(unsigned, double[]);

#define LMIN 1
#define LMAX 10

int main(){
   unsigned n;
   int x;
   double array[LMAX];

   n = readVectorSize("How many elements: ", LMIN, LMAX);
   readFloatVecValues(n, array);
   x = scry4Negative_floatArray(n, array);
   if(x == -1) cout << "No negative number in array. \n";
   else cout << "First negative number in position " << x + 1 << '\n';
   return 0;
}

int scry4Negative_floatArray(unsigned n, double array[]){
   for(unsigned i = 0; i < n; i++){
      if(array[i] < 0) return i;
   }
   return -1;
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