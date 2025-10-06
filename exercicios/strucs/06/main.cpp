/*Uma empresa possui vários vendedores. Para cada vendedor é conhecido o nome, a
quantidade vendida, o valor da venda e o salário fixo. Os vendedores recebem
comissão de acordo com a quantidade vendida:
 10% do valor da venda se quantidade vendida < 15
 22% do valor da venda se 15 <= quantidade vendida < 30
 30% do valor da venda se quantidade vendida >= 30
Construa um algoritmo que escreva o nome do vendedor, a quantidade vendida, o
valor da venda, o salário fixo, a comissão e o total recebido. Os nomes dos
vendedores devem ser relacionados em ordem alfabética.*/

#include <iostream>

typedef struct {
   std::string nome;
   unsigned qtdVendida;
   double valorVenda, salarioFixo, comissao=0.0, pagamentoTotal=0.0;
} Vendedor;

#define QTDVEND 5

void cacular_comissao(Vendedor &v){
   if(v.qtdVendida < 15){
      v.comissao = v.valorVenda*0.1;
   } else if(v.qtdVendida >= 30) {
      v.comissao = v.valorVenda*0.3;
   } else {
      v.comissao = v.valorVenda*0.22;
   }
}

void cacular_pagamento(Vendedor &v){
   cacular_comissao(v);
   v.pagamentoTotal = v.salarioFixo + v.comissao;
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
      cacular_pagamento(v[i]);
      std::cout << v[i].nome << ": \nQtd. Vendida: " << v[i].qtdVendida
         << "\nValor das vendas: " << v[i].valorVenda << "\nSalário: " << v[i].salarioFixo
         << "\nComissão: " << v[i].comissao << "\nPagamento total: " << v[i].pagamentoTotal
         <<"\n\n";
   }
}

int main(){

   Vendedor vendedores[QTDVEND]{
      {"Carlos Santos", 20, 8000.00, 1500.00}, 
      {"Bruno Costa", 35, 12000.00, 1500.00},
      {"Eduardo Lima", 25, 9500.00, 1500.00},
      {"Diana Oliveira", 8, 3500.00, 1500.00},
      {"Ana Silva", 12, 5000.00, 1500.00}
   };

   imprime_vendedores(QTDVEND, vendedores);

   return 0;
}