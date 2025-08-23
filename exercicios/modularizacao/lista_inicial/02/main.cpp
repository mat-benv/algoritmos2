#include <iostream>
#include <cstring>
#include <iomanip>

using std::cout;
using std::string;
using std::cin;

/*Elabore uma função que realize a conversão de Fahrenheit (F) para graus Celsius (C), onde F é passado como
parâmetro e C é retornado. Sabe-se que os pontos de fusão e ebulição nas escalas Celsius e Fahrenheit são: 0ºC
e 100ºC, e 32ºF e 212ºF, respectivamente. Crie também um programa para testar tal função.*/

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

double far2cel(double far){
   double cel;
   cel = (far-32)*5/9;
   return cel;
}

string dot2comma_2(double n){ //changes floating poing indicator to comma, for portuguese text
   string s = std::to_string(n);
   for (unsigned i = 1; i < s.length(); i++){
      if(s[i] == '.'){
         s[i] = ','; 
         return s.substr(0, i+3);
      }
   }
   return s;
}

int main(){

   bool isFloat(string &), valid = false;
   double far2cel(double), far, cel;
   string farString;

   do{
      cout << "Input a temperature in Fahrenheit: \n"; getline(cin, farString);
      if(isFloat(farString)) valid = true; else cout << "Invalid input, try again.\n";
   }while(not valid);
   far = atof(farString.c_str());
   cel = far2cel(far);

   cout << dot2comma_2(far) << "F is " << dot2comma_2(cel) << "C.\n";

   return 0;
}