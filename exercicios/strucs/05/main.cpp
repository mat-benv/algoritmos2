/*Construa um programa que leia matrícula, nome e os dados dos dependentes de
vários sócios de um clube. Para cada dependente, leia nome e data de nascimento.
Na sequência, escreva o nome do sócio e os nomes de seus dependentes, para todos
os sócios que tiverem mais de 3 dependentes. Admita que cada sócio tenha no
máximo 5 dependentes.*/

#include <iostream>

#define MAXDEP 5
#define MAXSOCIOS 5

typedef struct{
   std::string nome;
   unsigned dn[3];
} Dependente;

typedef struct{
   std::string nome;
   unsigned matricula, ndep;
   Dependente deps[MAXDEP];
} Socio;

unsigned read_unsigned(std::string);
void read_socio(Socio &);
void read_dep(Socio &);
bool isUnsigned(std::string);
void print_data(Socio &);

int main(){
   unsigned n;
   Socio socios[MAXDEP];

   n = read_unsigned("Quantos sócios? ");

   for(unsigned i = 0; i < n; i++){
      read_socio(socios[i]);
   }
   for(unsigned i = 0; i < n; i++){
      if(socios[i].ndep > 2){
         print_data(socios[i]);
      }
   }
}

void print_data(Socio &s){
   std::cout << s.nome;
   std::cout << "\nDependentes: \n";
   for(unsigned i = 0; i < s.ndep; i++){
      std::cout << s.deps[i].nome << '\n';
   }
}

void read_dep(Socio &s, unsigned n){
   for(unsigned i = 0; i < n; i++){
      std::cout << "Nome do dependente " << i+1 << '\n'; getline(std::cin, s.deps[i].nome);
      std::cout << "Data de nascimento: \n";
      s.deps[i].dn[0] = read_unsigned("Dia:");
      s.deps[i].dn[1] = read_unsigned("Mês: ");
      s.deps[i].dn[2] = read_unsigned("Ano: ");
   }
}

void read_socio(Socio &s){
   s.matricula = read_unsigned("Digite a matrícula: ");
   std::cout << "Digite o nome: \n"; getline(std::cin, s.nome);
   do{
      s.ndep = read_unsigned("Quantos dependentes? ");
      if(s.ndep > 5) std::cout << "Não pode ser mais que 5.\n";
   }while(s.ndep > 5);
   read_dep(s, s.ndep);
}

unsigned read_unsigned(std::string msg){
   std::string s;
   do{
      std::cout << msg << "\n"; getline(std::cin, s);
      if(not isUnsigned(s)) std::cout << "Not a valid input. Try again. \n";
   }while(not isUnsigned(s));
   return atoi(s.c_str());
}

bool isUnsigned(std::string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}