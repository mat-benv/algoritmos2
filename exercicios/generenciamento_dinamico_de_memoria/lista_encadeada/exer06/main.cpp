/*Admita que os dados (matrícula, nome e salário) sobre os empregados de uma determinada empresa
devam ser armazenados em uma lista encadeada. Faça um algoritmo para ler os dados dos
empregados e criar a lista. Depois de criada, a lista deverá ser desmembrada em duas, a primeira
conterá somente as informações dos empregados que recebem salários até R$ 1.000,00 e a segunda,
com as informações daqueles que têm salários superiores a R$ 1.000,00.*/

#include <iostream>

typedef struct Node{
    std::string nome, matr;
    double sal;
    struct Node *prox;
} Pessoa;

void insere_empregado(Pessoa* &ptrlista, std::string nome, std::string matr, double sal){
    Pessoa* novo = new Pessoa;
    novo->matr = matr;
    novo->nome = nome;
    novo->sal = sal;
    novo->prox = ptrlista;
    ptrlista = novo;
}

/*void ler_empregados(Pessoa* &ptrlista){
    //digita nome, salario, mtr, valida e passa para insere_empregado
}*/

void desmembra_lista(Pessoa* &l, Pessoa* &lb, Pessoa* &la){
    Pessoa *aux;
    while(l != NULL){
        aux = l;
        l = l->prox;
        if(aux->sal <= 1000.0){
            aux->prox = lb; lb = aux;
        } else {
            aux->prox = la; la = aux;
        }
    }
}

int main(){

    //Pessoa *lista = NULL, *listaBaixo = NULL, *listaAlto = NULL;

    return 0;
}