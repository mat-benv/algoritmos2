/*Durante um período contínuo de 14 dias (2 semanas), foi anotada a temperatura diária em
uma cidade e os dados estão armazenados em uma matriz 2x7. Faça um programa que:
 leia os valores das temperaturas;
 calcule, para cada semana, a temperatura média, a máxima e a mínima;
 determine o dia mais quente e o dia mais frio do período observado;
 ao final, apresente os resultados.*/

#include <iostream>
#include <cstring>
using namespace std;

#define weeks 2
#define days 7

bool isFloat(string &);
double finput(string);
void readTemps(unsigned, unsigned, double[][days]);
void printMatrix_float(unsigned, unsigned, double[][days]);
unsigned dayCalc(unsigned, unsigned);
double weekAvg(unsigned, double[][days]);
double weekHigh(unsigned, double[][days]);
double weekLow(unsigned, double[][days]);
double periodHigh(unsigned, double[][days]);
double periodLow(unsigned, double[][days]);
void weekReport(unsigned, double[][days]);

int main(){
    double temps[weeks][days]{0.0};

    readTemps(weeks, days, temps);
    for(unsigned i = 0; i < weeks; i++){
        weekReport(i, temps);
    }

    cout << "Total period: " << "\t\n"
    << "Hottest day: " << periodHigh(weeks, temps) << "\t\n"
    << "Coldest day: " << periodHigh(weeks, temps) << "\t\n";

}

void weekReport(unsigned week, double temps[][days]){
    cout << "Week " << week << "\t\n"
    << "Average temperature: " << weekAvg(week, temps) << "\t\n"
    << "Hottest day: " << weekHigh(week, temps) + 1 << "\t\n"
    << "Coldest day: " << weekLow(week, temps) + 1 << "\t\n";
}

double periodLow(unsigned n, double temps[][days]){
    double lowTemp = temps[0][0];
    unsigned coldestDay;
    for(unsigned i = 0; i < n; i++){
        for(unsigned j = 0; j < days; j++){
            if(temps[i][j] < lowTemp){
                lowTemp = temps[i][j];
                coldestDay = dayCalc(i, j);
            }
        }
    }
    return coldestDay;
}

double periodHigh(unsigned n, double temps[][days]){
    double highTemp = temps[0][0];
    unsigned hottestDay;
    for(unsigned i = 0; i < n; i++){
        for(unsigned j = 0; j < days; j++){
            if(temps[i][j] > highTemp){
                highTemp = temps[i][j];
                hottestDay = dayCalc(i, j);
            }
        }
    }
    return hottestDay;
}

double weekAvg(unsigned week, double temps[][days]){
    double avg;
    for(unsigned i = 0; i < days; i++){
        avg += temps[week][i];
    }
    return avg/float(days);
}

double weekHigh(unsigned week, double temps[][days]){
    double highTemp = temps[week][0];
    for(unsigned i = 1; i < days; i++){
        if(temps[week][i] > highTemp) highTemp = temps[week][i];
    }
    return highTemp;
}

double weekLow(unsigned week, double temps[][days]){
    double lowTemp = temps[week][0];
    for(unsigned i = 1; i < days; i++){
        if(temps[week][i] < lowTemp) lowTemp = temps[week][i];
    }
    return lowTemp;
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

void readTemps(unsigned n, unsigned m, double mat[][days]){
   for(unsigned i = 0; i < n; i++){
      for(unsigned j = 0; j < m; j++){
        cout << "Input temperature for day " << dayCalc(i, j) << ": ";
        mat[i][j] = finput("");
      }
   }
}

void printMatrix_float(unsigned n, unsigned m, double mat[][days]){
   for(unsigned i = 0; i < n; i++){
      cout << "|";
      for(unsigned j = 0; j < m; j++){
         cout << " " << mat[i][j];
      }
      cout << " |\n";
   }
}

unsigned dayCalc(unsigned i, unsigned j){
    if(i == 1) j = j + 7;
    return j + 1;
}