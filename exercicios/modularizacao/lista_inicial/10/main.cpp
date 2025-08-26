#include <iostream>
#include <cstring>
using std::cin, std::cout, std::string;

/*Elabore uma função que recebe três valores inteiros e devolve por referência o maior e o menor valor desses três.
Deve ser criado um programa para utilizar tal função lendo os valores e escrevendo o maior e o menor valor
computado*/

void smallest_and_biggest(int a, int b, int c, int &smallest, int &biggest){
   int v[2]{b, c};
   smallest = a;
   biggest = a;
   for(unsigned i = 0; i < 2; i++){
      if(v[i] > biggest) biggest = v[i];
      if(v[i] < smallest) smallest = v[i];
   }
}

bool isInt(string s){
   if(not isdigit(s[0]) and s[0] != '-') return false; 
   else{
      for(unsigned i = 1; i < s.length(); i++){
         if(not isdigit(s[i])) return false;
      }
      return true;
   }
}

int input(char ch){
   string s;
   do{
      cout << "Input integer " << ch << ": \n"; getline(cin, s);
      if(not isInt(s)) cout << "Not a valid integer. Try again. \n";
   }while(not isInt(s));
   return atoi(s.c_str());
}

int main(){
   int a, b, c, smallest, biggest;
   char ch = 'A';

   a = input(ch); ch++;
   b = input(ch); ch++;
   c = input(ch);

   smallest_and_biggest(a, b, c, smallest, biggest);

   cout << "Smallest: " << smallest << ".\n Biggest: " << biggest << ". \n";

   return 0;
}