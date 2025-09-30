/*01) Declare um tipo estruturado para representar um determinado aluno, contendo nome, notas de 4 provas e sua média.*/
/*02) Implemente um programa jque leia o nome e quatro notas de uma turma de 20 alunos. 
Após a entrada de dados, calcule a média dos alunos. 
Ao final, apresente na tela o nome e a média do aluno.*/

#include <iostream>
using std::string;

#define STUDENTAMOUNT 5 //for test, could change to 20 easily
#define GRADEAMOUNT 4

typedef struct{
   string name;
   float grades[GRADEAMOUNT], avg;
} Student;

void data_entry(int, Student[]);
string get_name(int);
string ordinal_suffix(unsigned);
float get_grade(unsigned);
float grade_avg(int, Student[]);
void print_class_data(Student[]);

int main(){
   Student students[STUDENTAMOUNT];
   
   for(unsigned i = 0; i < STUDENTAMOUNT; i++){
      data_entry(i, students);
      std::cin.ignore();
   }
   print_class_data(students);

   return 0;
}

void data_entry(int pos, Student v[]){
   v[pos].name = get_name(pos);
   for(unsigned i = 0; i < GRADEAMOUNT; i++){
      v[pos].grades[i] = get_grade(i);
   }
   v[pos].avg = grade_avg(pos, v);
}

string get_name(int pos){
   string name;
   std::cout << "Input the "<< pos+1 << ordinal_suffix((unsigned)pos+1) << " student's name: \n";
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

float get_grade(unsigned i){
   float grade;
   std::cout << "Input " << i+1 << ordinal_suffix(i+1) << " grade: \n";
   std::cin >> grade;
   //validation goes here
   return grade;
}

float grade_avg(int pos, Student v[]){
   float avg = 0;
   for(unsigned i = 0; i < GRADEAMOUNT; i++){
      avg += v[pos].grades[i];
   }
   return avg/GRADEAMOUNT;
}

void print_class_data(Student v[]){
   for(unsigned i = 0; i < STUDENTAMOUNT; i++){
      std::cout << v[i].name << ": \n";
      for(unsigned j = 0; j < GRADEAMOUNT; j++){
         std::cout << i+1 << ordinal_suffix(i+1) << " grade: " << v[i].grades[j] << '\n';
      }
      std::cout << "Grade average: " << v[i].avg << ". \n";
   }
}