#include <iostream>
#include <cstring>
using namespace std;

int main(){
   /*Faça um programa que receba uma frase e imprima esta frase de maneira invertida,
trocando também as letras A por *.*/

   string frase;
   bool valid;

   do{
      valid = true;
      cout << "Input a sentence: \n"; getline(cin, frase);
    
      if(frase == "") valid = false;

   }while(not valid);

   for(long unsigned i = frase.length() ; i > 0; i--){
      if(
         toupper(frase[i-1]) == 'A'){
            cout << '*';
         } else {
            cout << frase[i-1];
         }
   }

   return 0;
}
