/*Faça um programa para calcular as raízes reais de n equações do 2º grau: ax2 + b x + c. Construa
um procedimento que calcule e devolva as raízes reais da equação.*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using std::cout, std::cin, std::string;

bool isFloat(string &);
double fInput(string);
bool isPositiveInt(string);
unsigned iinput(string);
void equationRoots(double, double, double, double &, double &, unsigned &);
void firstDegreeEquation(double, double, double &, double &);

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

unsigned iinput(string msg){ //change type as needed, useful parameters can also be passed
   string s;
   do{
      cout << msg; getline(cin, s);
      if(not isPositiveInt(s)) cout << "Not a valid input. Try again. \n";
   }while(not isPositiveInt(s));
   return atoi(s.c_str());
}

bool isPositiveInt(string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

void equationRoots(double a, double b, double c, double &x1, double &x2, unsigned &roots){
    double delta;
    if(a == 0 and b == 0){
        roots = 0;
    } else {
        delta = pow(b, 2) - 4*a*c;
        if(delta == 0){
            roots = 1;
            x1 = -b/2*a;
        } else {
            if(delta < 0){
                roots = 3;
            } else {
                roots = 2;
                x1 = (-b + sqrt(delta))/2*a;
                x2 = (-b - sqrt(delta))/2*a;
            }
        }
    }
}

void firstDegreeEquation(double b, double c, double &x1, unsigned &roots){
    x1 = -c/b;
    roots = 1;
}

int main(){

    cout << std::fixed << std::setprecision(2);

    unsigned n, roots;
    double a, b, c, x1, x2;

    n = iinput("How many equations: \n");
    for(unsigned i = 0; i < n; i++){
        a = finput("Input \"a\" value: ");
        b = finput("Input \"b\" value: ");
        c = finput("Input \"c\" value: ");
        if(a == 0 and b != 0){
            firstDegreeEquation(b, c, x1, roots);
        } else {
            equationRoots(a, b, c, x1, x2, roots);
        }
        switch (roots){
            case 0: cout << "The equation has no valid answer, as a and b are 0.\n";
            break;
            case 1: cout << "The equation has a single root: x = " << x1 << '\n';
            break;
            case 2: cout << "The equation has two values for x: " << x1 << " and " << x2 << '\n';
            break;
            case 3: cout << "The equation has no real answer. \n";
            break;
        }
    }

    return 0;
}