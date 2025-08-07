#include <iostream>

using namespace std;

#define min 1
#define max 10


int main(){

    float vec[max] = {0}, lowest, highest;
    int n, lowpos = 0, highpos = 0;

    cout << "Qual o tamanho do vetor: " << endl;
    do{
        cin >> n;
    }while(n < min || n > max);

    for(int i = 0; i < n; i++){

        cout << "Digite o " << i + 1 << "o numero real: " << endl;
        cin >> vec[i];

    }

    lowest = vec[0];
    highest = vec[0];

    for(int i = 1; i < n; i++){
        if(vec[i] < lowest){
            lowest = vec[i];
            lowpos = i;
        }
    }

    cout << "O menor valor é " << lowest << " na posicao " << lowpos + 1 << endl;

    for(int i = 1; i < n; i++){
        if(vec[i] > highest){
            highest = vec[i];
            highpos = i;
        }
    }

    cout << "O maior valor é " << highest << " na posicao " << highpos + 1 << endl;

    return 0;
}