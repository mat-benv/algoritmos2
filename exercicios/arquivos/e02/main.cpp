/*Escreva um programa que leia um programa fonte C++ e verifique se o número de chaves esquerdas e
direitas são iguais. O arquivo de entrada deve ser informado pelo usuário.*/

#include <iostream>
#include <fstream>

bool check_brackets(std::string fileName){
    char ch;
    int count = 0;
    std::ifstream file(fileName.c_str());
    while(file.get(ch)){
        if(ch == '{') count++;
        if(ch == '}') count--;
    }
    if(count == 0) return true;
    else return false;
    file.close();
}

int main(){

    std::cout << check_brackets("../main.cpp");
    
    return 0;
}