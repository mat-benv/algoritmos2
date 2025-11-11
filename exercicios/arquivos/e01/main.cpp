/*Escreva um programa que numere as linhas de um arquivo texto. O arquivo de entrada deve ser
informado pelo usuário. O programa deve mostrar cada linha do arquivo de entrada precedida do seu
número e um espaço.*/

#include <iostream>
#include <fstream>

void count_lines(){
    std::string linha;
    int i = 1;
    std::ofstream outfile("teste2.txt");
    std::ifstream file("teste.txt");
    while(std::getline(file, linha)){
        outfile << i << ' ' << linha << '\n';
        i++;
    }
    file.close();
    outfile.close();
}

int main(){
    count_lines();
    return 0;
}