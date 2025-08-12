#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/*Dadas duas palavras verificar se uma é permutação circular de outra. Para se obter uma
permutação circular dessa palavra transfere-se o primeiro caracter do início para o fim da mesma.
Para se obter todas as outras permutações circulares, repete-se esse mesmo processo para cada
permutação circular obtida até que o último caracter da palavra inicial torne-se o primeiro. Assim,
por exemplo a palavra AROMA tem as seguintes permutações circulares: ROMAA, OMAAR,
MAARO, AAROM, AROMA*/

bool isWord(string s){
    if(s.empty()){
        return false;
    }
    for(unsigned i = 0; i < s.length(); i++){
        if(not isalpha(s[i])){
            return false;
        }
    }

    return true;
}

int main(){

    string word1, word2;
    bool valid, isPerm=false;
    char aux;
    long unsigned length;

    do{
        cout << "Digite uma palavra: \n"; getline(cin, word1);
        valid = isWord(word1);
        if(not valid) cout << "Digite apenas uma palavra.\n";
    }while(not valid);

    

    do{
        cout << "Digite a palavra para comparar: \n"; getline(cin, word2);
        valid = isWord(word2);
        if(not valid) cout << "Digite apenas uma palavra. \n";
    }while(not valid);

    length = word1.length();

    if(word2.length() != length){
        cout << word2 << " não é permutação circular de " << word1 << ", porque as duas não tem o mesmo tamanho.\n";
    } else if (word1 == word2){
        isPerm = true;
    } else {

        for(unsigned i = 0; i < length; i++){
            aux = word2[0];
            for(unsigned j = 0; j < length-1; j++){
                word2[j] = word2[j+1];
            }
            word2[length-1] = aux;
            if(word1 == word2){
                isPerm = true;
                break;
            }
        }
    }

    if(isPerm){
        cout << "As palavras são permutações. \n";
    } else {
        cout << "As palavras não são permutações. \n";
    }


    return 0;
}