/*Escreva um programa que leia um programa fonte C++ e retire os comentários deste programa fonte. O
novo arquivo deve ser gravado com o mesmo nome, porém com extensão xxx. O arquivo de entrada
deve ser informado pelo usuário.*/

#include <iostream>
#include <fstream>

//TODO

std::string get_name(std::string infileName){
    std::string outfileName = "";
    int i = 0;
    while(infileName[i] != '.'){
        outfileName += infileName[i];
        i++;
    }
    return outfileName + ".xxx";
}

void remove_comment(std::string fileName){
    char ch;
    std::string outfileName = get_name(fileName);
    std::ifstream fin(fileName.c_str());
    std::ofstream fout(outfileName.c_str());
    while(fin.get(ch)){
        if(ch == '/'){

        }
    }
}