/*Considere esta experiência para determinar a aceleração da gravidade: deixou-se cair uma bola, a
partir do repouso, do alto de vários edifícios. O tempo gasto para atingir o solo foi registrado em cada
caso. Um total de n medidas foram feitas. Faça um programa que leia a altura (em metros) de cada
prédio e o tempo (em segundos) gasto para atingir o solo e calcule a aceleração gravitacional g, a partir
desses dados, utilizando a fórmula y = ½ g t2 onde y representa a distância percorrida pela bola e t o
tempo gasto. Cada um dos n casos determina um valor de g. O “melhor valor” de g deve ser escrito e é
dado pela média aritmética dessas medidas*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using std::cout, std::cin, std::string;

bool isPositiveInt(string);
unsigned iinput(string);
bool isFloat(string &);
double finput(string);
void gravMeasureForAvg(double, unsigned, double &);
string ordinal_suffix(unsigned);

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

void gravMeasureForAvg(double y, unsigned t, double &gSum){
    double tFloat = t, g;
    g = 2*y/pow(tFloat,2);
    gSum += g;
}

int main(){

    double y, gSum = 0.0, t, gAvg;
    unsigned n;

    n = iinput("How many measurements: ");
    for(unsigned i = 0; i < n; i++){
        cout << i + 1 << ordinal_suffix(i+1) << " measurement: \n";
        do{
            y = finput("How high was the building is meters: ");
            if(y <= 0.0) cout << "Height can't me zero or less.";
        }while(y <= 0.0);
        do{
            t = finput("How long was the fall in seconds: ");
            if(t <= 0.0) cout << "Time can't be zero or negative. \n";
        }while(t <= 0.0);
        gravMeasureForAvg(y, t, gSum);
    }

    gAvg = gSum/float(n);

    cout << "Best value for g: " << gAvg << '\n';

    return 0;
}