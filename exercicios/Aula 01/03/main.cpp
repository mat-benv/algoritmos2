#include <iostream>

using namespace std;

#define max 10

int main(){

    int vec[max];

    for(int i = 0; i < max; i++){

        cout << "Digite o " << i+1 << "o valor: " << endl;

        do{
            cin >> vec[i]; 
        }while(vec[i] < 0);

    }

    cout << "Valores pares: " << endl;

    for(int i = 0;i < max; i++){
        if(vec[i] % 2 == 0){
            cout << "Posicao " << i + 1 << ": [" << vec[i] << "]" << endl; 
        }
    }

    return 0;
}