#include <iostream>

using namespace std;

#define min 3
#define max 10

int main(){

    int mat[max][max]{0}, transMat[max][max]{0}, n, diagSum = 0, upperSum = 0, lineProduct[max]{0}, columnSum[max]{0};

    cout << "Qual a ordem da matriz (entre 3 e 10): ";
    //pega ordem
    do{
        cin >> n;
        if(n < min || n > max){
            cout << "Valor invalido." << endl;
        }
    }while(n < min || n > max);

    //pega elementos
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "Digite o elemento (" << i+1 << "," << j+1 << "): ";
            cin >> mat[i][j];
        }
    }

    cout << "Matriz: " << endl;
    //imprime matriz
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "[" << mat[i][j] << "] ";
        }
        cout << endl;
    }

    // calcuma soma diagonal
    for(int i = 0; i < n; i++){
        diagSum += mat[i][i];
    }
    cout << "Soma da diagonal principal: " << diagSum << endl;

    //calcula soma elementos acima da diagonal
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i < j){
                upperSum += mat[i][j];
            };
        }
    }
    cout << "Soma dos elementos acima da diagonal principal: " << diagSum << endl;

    //calcula produto das linhas
    for(int i = 0; i < n; i++){

        lineProduct[i] = 1;

        for(int j = 0; j < n; j++){
                lineProduct[i] *= mat[i][j];
        }
    }

    cout << "Produtos dos elementos de cada linha: " << endl;

    for(int i = 0; i < n; i++){
        cout << "Linha " << i +1 << ": " << "[" << lineProduct[i] << "] " << endl;
    }

    //calcula soma das colunas
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
                columnSum[j] += mat[i][j];
        }
    }


    cout << "Soma dos elementos de cada coluna: " << endl;
    
    for(int i = 0; i < n; i++){
        cout << "Coluna " << i +1 << ": " << "[" << columnSum[i] << "] " << endl;
    }

    //faz matriz transposta
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            transMat[i][j] = mat[j][i];
        }
    }

    cout << "Matriz transposta: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "[" << transMat[i][j] << "] ";
        }
        cout << endl;
    }

    return 0;
}