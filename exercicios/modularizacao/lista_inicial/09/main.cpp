#include <iostream>
#include <cstring>
using std::cin, std::cout, std::string;

/*Faça uma função que faça a rotação de valor entre três números passados como parâmetros, por referência. Por
exemplo, se a função receber os valores 5 8 e 9, nesta ordem, os valores de saída nessas variáveis serão 8, 9 e 5,
respectivamente.*/

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

void rotation(double &a, double &b, double &c){
   double buffer;
   buffer = a;
   a = b;
   b = c;
   c = buffer;
}

double input(char ch){
   string s;
   do{
      cout << "Input number " << ch << ": \n"; getline(cin, s);
      if(not isFloat(s)) cout << "Not a valid number. Try again. \n";
   }while(not isFloat(s));
   return atof(s.c_str());
}

void output(double a, double b, double c){
   cout << "New order: " << a << " " << b << " " << c << "\n";
}

int main(){

   double a, b, c;
   char ch = 'A';
   
   a = input(ch); ch++;
   b = input(ch); ch++;
   c = input(ch);

   rotation(a, b, c);
   output(a, b, c);

   return 0;
}