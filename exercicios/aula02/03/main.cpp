#include <iostream>
#include <cstring>

using namespace std;

int main(){

    string frase;
    char vogais[5]{'A', 'E', 'I', 'O', 'U'};
    unsigned int qVogais[5]{0}, n=0;

    cout << "Digite uma frase: \n";
    getline(cin, frase);
    for(unsigned int j = 0; j < frase.size(); j++){
        for(unsigned int k = 0; k < 5; k++){
            if(toupper(frase[j]) == vogais[k]){
                qVogais[k]++;
                break;
            }
        }
    }

    for(unsigned int j = 0; j < 5; j++) if(qVogais[j] > qVogais[n]) n = j;

    if(qVogais[n] == 0){
        cout << "Nenhuma vogal.\n";
    } else {
        cout << "A vogal com maior incidência é: " << vogais[n] << '\n';
    }
    return 0;
}