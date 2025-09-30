/*Implemente um programa para ler os dados de vários funcionários (matrícula, nome,
cargo, departamento, data de admissão e salário) de uma empresa e gerar uma
relação daqueles que têm salários superiores à média geral de salários. O algoritmo
deve apresentar a seguinte mensagem: “Mais um funcionário: s(SIM) / n(NÃO)?”
antes de prosseguir com a entrada de dados.*/

#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 10

typedef struct{
   string name, position, department, admissionDate;
   unsigned idNum;
   double pay;
} Worker;

bool continue_task(string);
Worker get_worker_data(unsigned &);
string get_name(unsigned );
string ordinal_suffix(unsigned);
unsigned get_id(unsigned);
string get_position(unsigned);
string get_department(unsigned);
string get_admission_date(unsigned);
double get_pay(unsigned);
double avg_pay(unsigned, Worker []);
void print_worker_data(Worker);

int main(){
   unsigned count=0;
   Worker workers[MAX];
   double avgPay;
   
   do{
      cout << count + 1 << ordinal_suffix(count +1) << " worker's data: \n";
      workers[count] = get_worker_data(count);
   }while(continue_task("Another worker? Y/N"));

   avgPay = avg_pay(count, workers);

   cout << "Workers with higher than average pay: \n";

   for(unsigned i = 0; i < count+1; i++){
      if(workers[i].pay > avgPay) print_worker_data(workers[i]);
   }

   return 0;
}

bool continue_task(string msg){
   char o;
   do{
      cout << msg;
      cin >> o;
      if(toupper(o)!='Y' and toupper(o)!='N') cout << "Invalid input. \n";
   }while(toupper(o) != 'Y' and toupper(o) != 'N');
   if(toupper(o) == 'Y') return true;
   //else
   return false;
}

Worker get_worker_data(unsigned &i){
   Worker w;
   w.idNum = get_id(i);
   w.name = get_name(i);
   w.position = get_position(i);
   w.department = get_department(i);
   w.admissionDate = get_admission_date(i);
   w.pay = get_pay(i);
   i++;
   return w;
}

string get_name(unsigned i){
   string name;
   cin.ignore();
   std::cout << "Input the "<< i+1 << ordinal_suffix((unsigned)i+1) << " worker's name: \n";
   getline(std::cin, name);
   //validation goes here
   return name;
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

unsigned get_id(unsigned i){
   //set id criteria according to specs
   unsigned id;
   cout << "Input the " << i+1 <<ordinal_suffix(i+1) << " worker's id number: \n";
   cin >> id;
   //validation goes here
   return id;
}

string get_position(unsigned i){
   string pos;
   std::cout << "Input the "<< i+1 << ordinal_suffix((unsigned)i+1) << " worker's position: \n";
   getline(std::cin, pos);
   //validation goes here
   return pos;
}

string get_department(unsigned i){
   string dep;
   std::cout << "Input the "<< i+1 << ordinal_suffix((unsigned)i+1) << " worker's department: \n";
   getline(std::cin, dep);
   //validation goes here
   return dep;
}

string get_admission_date(unsigned i){
   string date;
   std::cout << "Input the "<< i+1 << ordinal_suffix((unsigned)i+1) << " worker's admission date: \n";
   getline(std::cin, date);
   //validation goes here
   return date;
}

double get_pay(unsigned i){
   double pay;
   std::cout << "Input the "<< i+1 << ordinal_suffix((unsigned)i+1) << " worker's pay: \n";
   cin >> pay;
   //validation goes here
   return pay;
}

double avg_pay(unsigned count, Worker v[]){
   double avgPay = 0.0;
   for(unsigned i = 0; i < count+1; i++){
      avgPay += v[i].pay;
   }
   return avgPay/((float)count);
}

void print_worker_data(Worker w){
   cout << "ID: " << w.idNum << '\n'
      << "Name: " << w.name << '\n'
      << "Position: " << w.position << '\n'
      << "Department: " << w.department << '\n'
      << "Date of admission: " << w.admissionDate << '\n'
      << "Pay: " << setprecision(2) << w.pay << "\n\n";
}