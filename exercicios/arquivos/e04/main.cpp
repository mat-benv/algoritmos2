/*Escreva um programa que leia um programa fonte C++ e retire os comentários deste programa fonte. O
novo arquivo deve ser gravado com o mesmo nome, porém com extensão xxx. O arquivo de entrada
deve ser informado pelo usuário.*/

#include <iostream>
#include <fstream>

std::string get_name(std::string infileName){
    std::string outfileName = "";
    int i = 0;
    while(infileName[i] != '.'){
        outfileName += infileName[i];
        i++;
    }
    return outfileName + ".xxx";
}

void remove_comment(std::string fileName)
{
    char ch;
    std::string outfileName = get_name(fileName);
    std::ifstream fin(fileName.c_str());
    std::ofstream fout(outfileName.c_str());
    bool quotes = false, slash = false, longComment = false, lineComment = false, star = false;
    while(fin.get(ch))
    {
        if(lineComment) //comentario de linha
        {
            if(ch == '\n') // fim de linha
            {
                lineComment = false;
                fout << ch;
                continue;
            } else continue;
        }
        else if(longComment) // comentario /* */
        {
            if(star) // se *
            {
                if(ch == '/') //fecha comentario
                {
                    longComment = false;
                    star = false;
                    continue;
                }
                else
                {
                    star = false; 
                    fout << '*' << ch;
                    continue;
                }
            }
            else
            {
                if(ch == '*')
                {
                    star = true;
                    continue;
                }
                else
                {
                    continue;
                }
            }
        }
        else if(quotes)
        {
            if(ch == '"')
            {
                fout << ch;
                quotes = false;
                continue;
            }
            else
            {
                fout << ch;
                continue;
            }
        }
        else
        {
            if(slash)
            {
                slash = false;
                if(ch == '/')
                {
                    lineComment = true;
                    continue;
                }
                else if(ch == '*')
                {
                    longComment = true;
                    continue;
                }
                else
                {
                    fout << '/' << ch;
                    continue;
                }
            }
            else
            {
                switch (ch)
                {
                case '/':
                    slash = true;
                    break;
                case '"':
                    fout << ch;
                    quotes = true;
                    break;
                default:
                    fout << ch;
                    break;
                }
            }
        }
    }
    fin.close();
    fout.close();
}

int main(){
    remove_comment("../main.cpp");
    return 0;
}