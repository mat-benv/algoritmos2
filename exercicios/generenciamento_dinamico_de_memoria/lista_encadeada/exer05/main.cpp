/*Suponha a existência de uma lista encadeada com as matrículas de um conjunto de funcionários.
Admita também que exista outra lista encadeada onde cada nodo contenha matrícula do funcionário e
nome do seu dependente. Faça um procedimento que escreva, para cada funcionário, o nome do
seu(s) dependente(s).*/

#include <iostream>

typedef struct Node{
    std::string nome, matr;
    struct Node* prox;
} Pessoa;

void insere_dep(Pessoa* &dep, std::string matFunc){
    Pessoa *novo = new Pessoa;
    std::string s;
    if(novo == NULL){
        std::cout << "Sem memória.\n";
        std::cin.get();
        exit(0);
    }
    novo->matr = matFunc;
    std::cout << "Insira o nome do dependente: \n";
    getline(std::cin, s);
    novo->nome = s;
    novo->prox = dep;
    dep = novo;
}

Pessoa* encontra_pessoa(Pessoa* ptrlista, std::string mat){
    while(ptrlista != NULL){
        if(ptrlista->matr == mat) return ptrlista;
        ptrlista =  ptrlista->prox;
    }
    return NULL;
}

void cadastro_dep(Pessoa* &func, Pessoa* &dep){
    std::string n;
    Pessoa *cad = new Pessoa;
    std::cout << "Insira a matrícula do funcionário: \n";
    getline(std::cin, n);
    if(encontra_pessoa(func, n) == NULL){
        std::cout << "Funcionário não encontrado.\n";
        return;
    } else {
        insere_dep(dep, n);
    }
}

void relatorio(Pessoa* func, Pessoa* dep){
    Pessoa *paux = dep; 
    bool achou;
    while(func != NULL){
        std::cout << func->nome << std::endl;
        achou = false;
        while(dep != NULL){
            if(func->matr == dep->matr){
                std::cout << "\t" << dep->nome << std::endl;
                achou = true;
            }
            dep = dep->prox;
        }
        if(not achou){
            std::cout << "Sem dependentes.\n";
        }
        func = func ->prox;
        dep = paux;
    }
}

int main(){

    Pessoa *func = NULL, *dep;

    return 0;
}