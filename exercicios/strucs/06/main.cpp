/*Uma empresa possui vários vendedores. Para cada vendedor é conhecido o nome, a
quantidade vendida, o valor da venda e o salário fixo. Os vendedores recebem
comissão de acordo com a quantidade vendida:
 10% do valor da venda se quantidade vendida < 15
 22% do valor da venda se 15 <= quantidade vendida < 30
 30% do valor da venda se quantidade vendida >= 30
Construa um algoritmo que escreva o nome do vendedor, a quantidade vendida, o
valor da venda, o salário fixo, a comissão e o total recebido. Os nomes dos
vendedores devem ser relacionados em ordem alfabética.*/

/* NÃO TERMINADO */

#include <iostream>

typedef struct {
   std::string nome;
   unsigned qtdVendida;
   double valorVenda, salarioFixo, comissao, pagamentoTotal;
} Vendedor;

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
   v.pagamentoTotal = v.salarioFixo + v.comissao;
}

void imprime_vendedores(Vendedor v[]){

}

int main(){

   Vendedor vendedores[5]{{"Ana Silva", 12, 5000.00},
      {"Carlos Santos", 20, 8000.00}, 
      {"Bruno Costa", 35, 12000.00},
      {"Diana Oliveira", 8, 3500.00},
      {"Eduardo Lima", 25, 9500.00}
   };

   return 0;
}