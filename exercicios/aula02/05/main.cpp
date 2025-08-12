#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/*Dada uma cadeia de caracteres, verifique se é ou não um identificador (nome de variável) válido.
Um identificador válido é uma cadeia de caracteres cujo primeiro caracter deve ser uma letra e os
demais devem ser dígitos, letras ou o underscore ( _ ). Exemplos: casa_azul, conjunto1, umValor.*/

int main(){

    string varID;
    bool valid=true;

    do{
        cout << "Input variable name: \n"; getline(cin, varID);
    }while(varID.empty());

    if(not isalpha(varID[0])){
        valid = false;
    } else {
        for(unsigned i = 1; i < varID.length(); i++){
            if(not isalnum(varID[i]) && varID[i] != '_'){
                valid = false;
                break;
            }
        }
    }

    if(valid){
        cout << "Valid ID.\n";
    } else {
        cout << "Invalid ID. \n";
    }

    return 0;
}
