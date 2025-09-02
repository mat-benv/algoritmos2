/*Faça um programa que leia o nome e a nota da prova I de uma turma de n (1 n 20)
estudantes, e armazene as informações em vetores. Ao final apresente o nome dos
estudantes cuja nota é maior do que a média da turma e determine também quantos
estudantes obtiveram nota abaixo da média da turma.*/

#include <iostream>
#include <cstring>
using std::string, std::cout, std::cin;

#define LMAX 20
#define LMIN 1

bool isFloat(string &);
double finput(string);
bool isPositiveInt(string);
unsigned iinput(string);
void lerNomeENota(unsigned, string[], double[]);
string ordinalSuffix(unsigned);
double floatVectorValuesAvg(unsigned, double[]);
void studentsOverAndUnderClassAvg(unsigned, double, string[], double[]);

int main(){
   unsigned n;
   double avg, grades[LMAX];
   string names[LMAX];

   do{
      n = iinput("How many students to grade: ");
      if(n < LMIN or n > LMAX) cout << "Has to be between " << LMIN << " and " << LMAX << ". \n";
   }while(n < LMIN or n > LMAX);

   lerNomeENota(n, names, grades);
   avg = floatVectorValuesAvg(n, grades);
   studentsOverAndUnderClassAvg(n, avg, names, grades);

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


void lerNomeENota(unsigned n, string vecNomes[], double vecNotas[]){
   for(unsigned i = 0; i < n; i++){
      cout << "Input the " << i + 1 << ordinalSuffix(i+1) << " student's name: \n";
      getline(cin, vecNomes[i]);
      do{
         vecNotas[i] = finput("Input their grade: ");
         if(vecNotas[i] < 0.0 or vecNotas[i] > 10.0) cout << "Grade beyond accepted range. \n";
      }while(vecNotas[i] < 0.0 or vecNotas[i] > 10.0);
   }
}

double floatVectorValuesAvg(unsigned n, double vec[]){
   double avg = 0.0;
   for(unsigned i = 0; i < n; i++){
      avg += vec[i];
   }
   avg = avg/double(n);
   return avg;
}

void studentsOverAndUnderClassAvg(unsigned n, double avg, string nomes[], double notas[]){
   unsigned underAvgAmount = 0;
   for(unsigned i = 0; i< n; i++){
      if(notas[i] > avg){
         cout << nomes[i] << " is above average with a " << notas[i] << ".\n";
      } else if(notas[i] < avg){
         underAvgAmount++;
      }
   }
   cout << underAvgAmount << " student";
   if(underAvgAmount == 1) cout << 's'; 
   cout << " had a below average grade. \n";
}