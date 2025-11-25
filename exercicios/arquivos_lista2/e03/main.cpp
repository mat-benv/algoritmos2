/*Faça um programa que leia um arquivo de acesso sequencial onde cada linha tem no
máximo 80 caracteres e formate este arquivo de modo que cada linha seja
centralizada*/
#include <iostream>
#include <fstream>

std::string get_name(std::string infileName){
    std::string outfileName = "";
    int i = 0;
    while(infileName[i] != '.' or (infileName[i] == '.' and ((infileName[i+1] == '.') or (infileName[i-1] == '.')))){
        outfileName += infileName[i];
        i++;
    }
    return outfileName + ".xxx";
}

void center_lines(std::string filename){
    rename(filename.c_str(), "temp.xxx");
    std::string line, spaces = "";
    std::ifstream fin("temp.xxx");
    std::ofstream fout(filename.c_str());
    int size;
    while(getline(fin, line)){
        size = (80 - line.length())/2;
        for(int i = 0; i < size; i++){
            spaces = spaces + ' ';
        }
        fout << spaces + line + '\n';
        spaces.clear();
    }
    fin.close();
    fout.close();
    remove("temp.xxx");
}

int main(){
    center_lines("texto.txt");
    return 0;
}