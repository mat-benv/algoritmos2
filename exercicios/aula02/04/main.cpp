#include <iostream>
#include <cstring>

using namespace std;

/*Uma palavra palíndrome é uma cadeia de caracteres cuja leitura tem o mesmo sentido se feita da
direita para a esquerda ou vice-versa. Por exemplo, OSSO, OVO, RADAR, ... Ler n cadeias de
caracteres e determinar quais delas são palíndromes.*/


int main(){

    string pal;
    char opt;
    bool isPalin;

    do{
        do{
            
            cout << "Digite uma palavra ou frase: \n";
            getline(cin, pal);

        }while(pal.empty());

        unsigned long length = pal.length();
        isPalin = true;

        for(unsigned i = 0; i < length/2; i++){
            if(toupper(pal[i]) != toupper(pal[length-1-i])){
                isPalin = false;
                break;
            }
        }

        if(isPalin){
            cout << pal << " é um palíndromo.\n";
        } else {
            cout << pal << " não é palíndromo.\n";
        }

        do{
            cout << "Continuar? S/N \n";
            cin >> opt;
        }while(toupper(opt) != 'S' && toupper(opt) != 'N');

        cin.ignore();

    }while(toupper(opt) != 'N');



    return 0;
}