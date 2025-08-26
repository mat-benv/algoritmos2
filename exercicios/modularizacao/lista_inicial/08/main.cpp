#include <iostream>
#include <cstring>
using std::cout, std::cin, std::string;

/*Crie um procedimento que gere um cabeçalho para um relatório. Esse procedimento deve receber um nome como
parâmetro. O cabeçalho tem a seguinte forma:
============================================
UNIVALI – POLITECNICA – Ciência da Computação
Disciplina Algoritmo e Programação 2per
Nome: Fulano de Tal
============================================
onde Fulano de Tal corresponde ao parâmetro passado.*/


void cabecalho(string nome){
   cout << "=============================================\n";
   cout << "UNIVALI - POLITECNICA - Ciência da Computação\n";
   cout << "Disciplina Algoritmo e Programação 2per\n";
   cout << "Nome: " << nome << "\n";
   cout << "=============================================\n";
}

int main(){

   string nome;
   void cabecalho(string);

   do{
      cout << "Digite seu nome: \n"; getline(cin, nome);
   }while(nome.empty());

   cabecalho(nome);

   return 0;
}