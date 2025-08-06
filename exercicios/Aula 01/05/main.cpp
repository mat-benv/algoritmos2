#include <iostream>

using namespace std;


#define min 1
#define max 10

int main(){

   float vec[max] = {1, -48, 56, 59, 88, 12, 7, 9, 5, 0}, buffer;
   int n;

   cout << "Quantos elementos: ";

   do{
      cin >> n;
   }while(n < min || n > max);

   for(int i = 0; i < n; i++){
      cout << "Digite o  " << i + 1 << "o valor: ";
      cin >> vec[i]; 
   }

   for(int i = 0; i < n-1; i++){
      for(int j = i+1; j < n; j++){
        if(vec[i] > vec[j]){
            buffer = vec[i];
            vec[i] = vec[j];
            vec[j] = buffer;
         }
      }
   }

   for(int i = 0; i < n; i++){
      cout << "[" << vec[i] << "] ";
   }


   return 0;
}