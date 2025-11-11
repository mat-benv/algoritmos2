#include <iostream>

typedef struct Node{
    std::string nome;
    double peso;
    struct Node *next;
} NomeePeso;

typedef struct Nodo{
    int valor;
    struct Nodo *next;
} ValorInteiro;

NomeePeso* endereco_nome(NomeePeso* lista, std::string n){ //2
    while (lista != NULL){
        if(lista->nome == n) return lista;
        lista = lista->next;
    }
    return NULL;
}

void insert_after_80(ValorInteiro* p, int a){ //3
    while(p !=NULL and p->valor != 80){
        p = p->next;
    }
    if(p != NULL){
        ValorInteiro *novo = new ValorInteiro;
        if(novo == NULL){
            std::cout << "Sem memória.\n";
            std::cin.get();
            exit(0);
        }
        novo->valor = a;
        novo->next = p->next;
        p->next = novo;
        std::cout << "Valor inserido. \n";
        return;
    }
    std::cout << "80 não encontrado.\n";
}

void delete_first_occurence(ValorInteiro* &ptrlista, int a){ //4
    ValorInteiro *aux = ptrlista, *ptrAnt = ptrlista;
    if(aux->valor == a){
        ptrlista = aux->next;
        delete aux;
        return;
    }
    while(aux != NULL and aux->valor != a){
        ptrAnt = aux;
        aux = aux->next;
    }
    if(aux != NULL){
        ptrAnt->next = aux->next;
        delete aux;
        return;
    }
}

int main(){
    
    return 0;
}