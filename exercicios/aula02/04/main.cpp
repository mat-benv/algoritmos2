#include <iostream>
#include <cstring>

using namespace std;

/*Uma palavra palíndrome é uma cadeia de caracteres cuja leitura tem o mesmo sentido se feita da
direita para a esquerda ou vice-versa. Por exemplo, OSSO, OVO, RADAR, ... Ler n cadeias de
caracteres e determinar quais delas são palíndromes.*/


int main(){

    string pal, lap;
    char opt;

    do{
        do{
            
            cout << "Digite uma palavra ou frase: \n";
            getline(cin, pal);

        }while(pal.empty());

        for(unsigned int i = 0; i < pal.size(); i++){
            
        }

    }while(toupper(opt) != 'N');



    return 0;
}