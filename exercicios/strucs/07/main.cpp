/*Uma loja de departamentos tem n vendedores. As vendas são registradas
diariamente e um determinado vendedor pode efetuar várias vendas por dia. Ao final
de cada dia, é emitido um relatório (em ordem alfabética) contendo o nome,
quantidade de vendas e total de vendas de cada um dos vendedores. Implemente um
programa que:
 leia o nome de cada um dos n vendedores;
 leia informações sobre as vendas diárias, quais sejam, nome do vendedor e valor
de venda;
 escreva, para cada vendedor, seu nome e valor total de vendas diárias efetuadas.
As informações sobre as vendas diárias não estão em sequência. O algoritmo deve
apresentar a seguinte mensagem: “mais uma venda: s(SIM) / n(NÃO)?” antes de
prosseguir com a entrada de dados.*/

#include <iostream>

#define QTDVENDS 5

typedef struct {
   std::string nome="";
   unsigned qtdVendas=0;
   double totalVendas=0.0;
} Vendedor;

void ordena_vendedores(unsigned, Vendedor []);
void imprime_vendedores(unsigned, Vendedor []);
bool continue_task(std::string);
char menu();
void adicionar_vendas(unsigned, Vendedor []);
int procura_vendedor(unsigned, std::string, Vendedor []);
void adiciona_vendedor(unsigned &, Vendedor []);

int main(){

   Vendedor vendedores[QTDVENDS];
   unsigned n=0;
   char o;
   do{
      o = menu();
      switch(o){
         case '1': adiciona_vendedor(n, vendedores);
         break;
         case '2': adicionar_vendas(n, vendedores);
         break;
         case '3': imprime_vendedores(n, vendedores);
         break;
         case '4': std::cout << "Saindo...\n";
         break;
         default: std::cout << "Opção inválida.";
      }
   }while(o != '4');

   return 0;
}

void ordena_vendedores(unsigned n, Vendedor v[]){
   unsigned pos;
   for(unsigned i = 0; i < n-1; i++){
      pos = i;
      for(unsigned j = i+1; j < n; j++){
         if(v[j].nome < v[pos].nome){
            pos = j;
         }
      }
      std::swap(v[i], v[pos]);
   }
}

void imprime_vendedores(unsigned n, Vendedor v[]){
   ordena_vendedores(n, v);
   for(unsigned i = 0; i < n; i++){
      std::cout << v[i].nome << ": \nQtd. Vendida: " << v[i].qtdVendas
         << "\nValor das vendas: " << v[i].totalVendas << "\n\n";
   }
}

bool continue_task(std::string msg){
   char o;
   do{
      std::cout << msg;
      std::cin >> o;
      if(toupper(o)!='S' and toupper(o)!='N') std::cout << "Opção inválida. \n";
   }while(toupper(o) != 'S' and toupper(o) != 'N');
   if(toupper(o) == 'S') return true;
   //else
   return false;
}

char menu(){
   char opt;
   std::cout << "---------MENU---------\n"
             << "1) Adicionar vendedor. \n"
             << "2) Adicionar vendas. \n"
             << "3) Mostrar dados. \n"
             << "4) Sair.\n";
   std::cin >> opt;
   return opt;
}

void adicionar_vendas(unsigned n, Vendedor v[]){
   std::string nome;
   int i;
   double valorVenda;
   bool o;

   std::cin.ignore();
   if(n == 0) {
      std::cout << "Nenhum vendedor cadastrado ainda.\n";
   } else {
      do{
         std::cout << "Digite o nome do vendedor: \n";
         getline(std::cin, nome);
         i = procura_vendedor(n, nome, v);
         if(i < 0) std::cout << "Vendedor não encontrado.\n";
      }while(i < 0);
      std::cout << "Cadastrando para " << nome << ": \n";
      do{
         std::cout << "Valor da venda: \n";
         std::cin >> valorVenda;
         v[i].totalVendas += valorVenda;
         v[i].qtdVendas++;
         o = continue_task("Mais uma venda? S/N\n");
      }while(o);
   }
}

int procura_vendedor(unsigned n, std::string nome, Vendedor v[]){
   for(unsigned i = 0; i < n; i++){
      if(nome == v[i].nome) return i;
   }
   return -1;
}

void adiciona_vendedor(unsigned &n, Vendedor v[]){
   int x;
   std::string nome;
   std::cin.ignore();
   do{
      std::cout << "Nome do vendedor: ";
      getline(std::cin, nome);
      x = procura_vendedor(n, nome, v);
      if(x > -1) std::cout << "Vendedor já cadastrado.\n";
   }while(x > -1);
   v[n].nome = nome;
   n++;
}