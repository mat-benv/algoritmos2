#include <iostream>

using namespace std;

#define min 1
#define max 10

int main(){

    int vec[max]{0}, n, query;
    bool present = false;

    cout << "Quantos elementos: ";

    do{
        cin >> n;
    }while(n < min || n > max);

    for(int i = 0; i < n; i++){
        cout << "Digite o " << i + 1 << "o elemento: ";
        cin >> vec[i];
    }

    while(true){

        present = false;

        cout << "Digite um numero para procurar: ";
        cin >> query;

        for(int i = 0; i < n; i++){
            if(query == vec[i]){
                cout << query << " encontrado na posicao " << i+1 << '.' << endl;
                present = true;
            }
        }

        if(!present){
            cout << query << " nao foi encontrado. " << endl;
        }

    }

    return 0;
}