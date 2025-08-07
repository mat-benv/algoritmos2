#include <iostream>
#include <cstring>

using namespace std;

int main(){
  
  string frase;
  char opt;
  int cont = 0;
  
  do{
    
    cout << "Digite uma frase de até 80 caracteres: " << '\n';
    getline(cin, frase);
  
    for(unsigned int i = 0; i < frase.size(); i++){
      if(frase[i] != ' ' && frase[i] != '.'){
        cout << frase[i];
        cont++;
      } else {
        cout << " " << cont << '\t';
        cont = 0;
      }
    }
    cout << '\n';

    do{
      cout << "Continuar? S/N" << "\n";
      cin >> opt;
      cin.ignore();
    }while(opt != 'S' && opt != 'N');
  }while(opt != 'N');

  return 0;
}
