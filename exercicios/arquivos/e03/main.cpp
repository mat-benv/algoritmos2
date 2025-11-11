/*Escreva um programa que leia um arquivo texto e imprima na tela 20 linhas por vez – a cada 20 linhas
impressas, o programa só deverá imprimir as próximas após o usuário pressionar <ENTER>. O arquivo
de entrada deve ser informado pelo usuário.*/

#include <iostream>
#include <fstream>

void print_twenty(std::string fileName){
    std::string line;
    int i = 1;
    std::ifstream file(fileName.c_str());
    while(std::getline(file, line)){
        std::cout << line;
        i++;
        if(i == 20){
            std::cin.get();
            i = 1;
        }
    }
    file.close();
}

int main(){
    print_twenty("../texto.txt");
    return 0;
}