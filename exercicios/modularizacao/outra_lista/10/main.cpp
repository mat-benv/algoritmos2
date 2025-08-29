/*Segundo a conjectura de Goldbach, qualquer número par maior que 2 pode ser escrito como a
soma de dois números primos (por definição matemática, o número 1 não é primo). Por exemplo,
8 = 3 + 5 12 = 5 + 7 16 = 3 + 13
Faça um programa que leia vários números inteiros positivos e devolva o par de números primos cuja
soma seja igual ao próprio número.*/

#include <iostream>
using std::cout, std::string, std::cin;
unsigned iinput(string);
bool isPositiveInt(string);
void primeSum(unsigned, unsigned &, unsigned &);
bool isPrime(unsigned);
bool continueLoop();

unsigned iinput(string msg){ //change type as needed, useful parameters can also be passed
   string s;
   do{
      cout << msg; getline(cin, s);
      if(not isPositiveInt(s)) cout << "Not a valid input. Try again. \n";
   }while(not isPositiveInt(s));
   return atoi(s.c_str());
}

bool isPositiveInt(string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

void primeSum(unsigned n, unsigned &firstTerm, unsigned &secondTerm){
    if(n == 4){ firstTerm = 2; secondTerm = 2;
    }else{
        for(unsigned i = 3; i < n/2; i++){
            if(isPrime(i) and isPrime(n - i)){
                firstTerm = i;
                secondTerm = n-i;
                break;
            }
        }
    }
}

bool isPrime(unsigned n){
    if(n < 2) return false;
    if(n == 2) return true;
    for (unsigned i = 2; i < n/2; i++){
        if(n%i == 0) return false;
    }
    return true;
}

bool continueLoop(){
   string s;
   char c;
   do{
      do{
         cout << "Continue? Y/N \n"; getline(cin, s);
      }while(s.length() > 1 or s.empty());
      c = toupper(s[0]);
   }while(c != 'Y' and c != 'N');
   if(c == 'N') return false; else return true;
}

int main(){
    unsigned n, x, y;
    bool opt;

    do{
        do{
            n = iinput("Input an even number and get its prime terms: ");
            if(n%2 != 0) cout << "Input is odd.\n";
            if(n < 4) cout << "Input is lower than 4. \n";
        }while(n%2 != 0 or n < 4);

        primeSum(n, x, y);

        cout << x << " + " << y << " = " << n << '\n';

        opt = continueLoop();
    }while(opt);

    return 0;
}