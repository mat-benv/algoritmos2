#include <iostream>
#include <cstring>

using namespace std;

int main(){
  
   string sA, sB;
   unsigned int n;

   cout << "Digite uma palavra: \n";
   getline(cin, sA);
   cout << "Repetir quantas vezes? \n";
   cin >> n;

   sB = sA;

   for(unsigned int i = 1; i < n; i++){
      sB = sB + " " + sA;
   }

   cout << sB << '\n';

   return 0;
}
