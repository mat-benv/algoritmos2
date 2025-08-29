/*Faça um programa que leia valores para (a, q, n), onde a é o elemento inicial, q a razão de uma
progressão geométrica e n o número desejado de elementos. Faça um procedimento que escreva os n
primeiros termos de cada progressão geométrica (P.G.), sendo 1º elemento: a, 2º elemento: a * q, 3º
elemento: a * q * q, ...*/

#include <iostream>
#include <cstring>
using std::string, std::cout, std::cin;

void geoProgression(double, double, unsigned);
double finput(string);
unsigned iinput(string);
bool isPositiveInt(string);
bool isFloat(string &);

void geoProgression(double a, double q, unsigned n){

    cout << a;
    for(unsigned i = 1; i < n; i++){
        a *= q;
        cout << ", " << a;
    }
    cout << '\n';

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

int main(){
    double a, q;
    unsigned n;

    a = finput("Input value for a: ");
    q = finput("Input value for q: ");
    n = iinput("How many elements: ");

    geoProgression(a, q, n);

}