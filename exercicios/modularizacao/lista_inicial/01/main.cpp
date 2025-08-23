#include <iostream>
#include <iomanip>
#include <cstring>
using  std::cout;
using std::setprecision;
using std::string;

/*Crie uma função que realize a conversão de Polegadas (pol) para Centímetros (cm), onde pol é passado como
parâmetro e cm é retornado. Sabe-se que 1 polegada está para 2,54 centímetros. Crie também um programa para
testar tal função.*/

double pol2cm(double pol){
   return pol*2.54;
}

bool isPositiveFloat(string &n){
   bool point = false;
   if(n.empty()){
      return false;
   } else if(not isdigit(n[0])){
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

int main(){
   double pol2cm(double);
   bool isPositiveFloat(string &), valid = false;
   string polString;
   double pol, cm;

   do{
      cout << "Input a measurement in inches: \n"; getline(std::cin, polString);
      if(isPositiveFloat(polString)){
         valid = true;
      } else cout << "Invalid input.\n";
   }while(not valid);
   pol = atof(polString.c_str());
   cm = pol2cm(pol);
   cout << polString << " inches in cm is " << setprecision(3) << cm << ".\n";
   return 0;
}