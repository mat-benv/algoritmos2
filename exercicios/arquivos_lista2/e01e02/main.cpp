#include <iostream>
#include <fstream>

std::string get_name(std::string infileName){
    std::string outfileName = "";
    int i = 0;
    while(infileName[i] != '.' or (infileName[i] == '.' and ((infileName[i+1] == '.') or (infileName[i-1] == '.')))){
        outfileName += infileName[i];
        i++;
    }
    return outfileName + ".bak";
}

void replace_file_for_arquivo(std::string filename){ // exer01
    rename(filename.c_str(), "TEXTO.BAK");
    char c;
    std::string word = "";
    std::ifstream fin("TEXTO.BAK");
    std::ofstream fout("TEXTO.TXT");
    while(fin.get(c)){
        if(c == ' ' or c == '\n'){
            if(word == "file"){
                fout << "arquivo" << c;
                word = "";
            } else {
                fout << word << c;
                word = "";
            }
        } else {
            word = word + c;
        }
    }
    fin.close();
    fout.close();
}

void delete_shorter_than_3(){ //exer02
    std::ifstream fin("TEXTO.TXT");
    std::ofstream fout("TEXTO2.TXT");
    char c;
    std::string word;

    while(fin.get(c)){
        if(c == ' ' or c == '\n'){
            if(word.length() < 3){
                fout << c;
                word.clear();
            } else {
                fout << word << c;
                word.clear();
            }
        } else {
            word = word + c;
        }
    }
    fin.close();
    fout.close();
}