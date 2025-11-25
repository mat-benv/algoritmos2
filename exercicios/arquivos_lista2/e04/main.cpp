/*Faça um programa para criar um arquivo de acesso direto chamado NUMEROS.BIN
que armazene valores inteiros lidos a partir do teclado. Considere como flag para
encerrar a leitura dos dados o valor –1, que não deve ser incluído no arquivo*/
#include <iostream>
#include <fstream>

void save_integers(){
    std::ofstream arq("NUMEROS.BIN", std::ios::binary);
    int n;
    while(true){
        std::cin >> n;
        if(n != -1){
            arq.write((const char*) &n, sizeof(int));
        } else {
            arq.close();
            return;
        }
    }
}

/*Elabore uma subrotina que leia o arquivo anterior e escreva os valores armazenados*/

void print_integers(){
    int n;
    std::ifstream arq("NUMEROS.BIN", std::ios::binary);
    while(arq.peek() != EOF){
        arq.read((char*) (&n), sizeof(int));
        std::cout << n << ' ';
    }
    arq.close();
}

/*Elabore uma subrotina para anexar um novo valor ao final do arquivo anterior.*/

void add_value(){
    std::fstream arq("NUMEROS.BIN", std::ios::binary | std::ios::app);
    int n;
     while(true){
        std::cin >> n;
        if(n != -1){
            arq.write((const char*) &n, sizeof(int));
        } else {
            arq.close();
            return;
        }
    }
}

/*Elabore uma subrotina para ler um arquivo de acesso direto em sua ordem inversa*/

void print_backwards(){
    int n;
    std::ifstream arq("NUMEROS.BIN", std::ios::binary);
    arq.seekg(-sizeof(int), std::ios::end);
    while(arq.tellg() != 0){
        arq.read((char*) (&n), sizeof(int));
        std::cout << n << ' ';
        arq.seekg(-2*sizeof(int), std::ios::cur);
    }
    arq.read((char*) (&n), sizeof(int));
    std::cout << n;
    arq.close();
}

/*Elabore uma subrotina para inverter o arquivo anterior, isto é, o primeiro registro deve
passar a ser o último, o segundo deve passar a ser o penúltimo e assim por diante.
Não utilize nenhuma estrutura auxiliar (nem vector, list, ou arquivo auxiliar).*/

void invert_file(){ // TODO
    std::fstream arq("NUMEROS.BIN", std::ios::binary);
    int size, buffer, n, m;
    arq.seekg(0, std::ios::end);
    size = arq.tellg()/sizeof(int);
    for(int i = 1; i <= size/2; i++){
        
    }
}

int main(){

    save_integers();
    print_integers();
    add_value();
    print_backwards();

    return 0;
}