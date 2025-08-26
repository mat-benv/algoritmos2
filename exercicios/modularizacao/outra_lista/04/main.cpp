/*Faça um programa que leia vários valores para x e y e calcule, para cada par, o valor de x^y. Defina
uma função para efetuar o cálculo solicitado, sem utilizar nenhuma função pré-definida. Considere que y
sempre é um número inteiro e positivo.*/

#include <iostream>
#include <string>
using std::cout, std::cin, std::string;

double power(double x, unsigned y){
   if(y == 0) return 1;
   if(y == 1) return x;
   double result = 1;
   for(unsigned i = 0; i < y; i++){
      result *= x;
   }
   return result;
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

bool isPositiveInt(string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
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

unsigned iinput(string msg){ //change type as needed, useful parameters can also be passed
   string s;
   do{
      cout << msg << "\n"; getline(cin, s);
      if(not isPositiveInt(s)) cout << "Not a valid input. Try again. \n";
   }while(not isPositiveInt(s));
   return atoi(s.c_str());
}

bool continueLoop(){
   string s;
   char c;
   do{
      do{
         cout << "Continue? Y/N \n"; getline(cin, s);
      }while(s.length() > 1 or s.empty());
      c = toupper(s[0]);
   }while(c != 'Y' and c != 'N');
   if(c == 'Y') return true; else return false;
}

int main(){

   double x, result;
   unsigned y;
   bool opt;

   do{

      x = finput("Input a value for x: ");
      y = iinput("Input a value for the exponent: ");
      result = power(x, y);

      cout << "Result: " << result << '\n';

      opt = continueLoop();
   }while(opt);

   return 0;
}