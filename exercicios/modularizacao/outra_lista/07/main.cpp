/*Faça um programa que leia n números inteiros. Para cada número lido, se for primo, encontre o
próximo número primo.*/

#include <iostream>
#include <cstring>
using std::cout, std::cin, std::string;
bool isPrime(unsigned);
bool isPositiveInt(string);
unsigned iinput(string);
unsigned nextPrime(unsigned);
string ordinalSuffix(unsigned);

bool isPrime(unsigned n){
    if(n < 2) return false;
    if(n == 2) return true;
    for (unsigned i = 2; i < n/2; i++){
        if(n%i == 0) return false;
    }
    return true;
}

bool isPositiveInt(string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}

unsigned iinput(string msg){ //change type as needed, useful parameters can also be passed
   string s;
   do{
      cout << msg; getline(cin, s);
      if(not isPositiveInt(s)) cout << "Not a valid input. Try again. \n";
   }while(not isPositiveInt(s));
   return atoi(s.c_str());
}

unsigned nextPrime(unsigned n){

    if(n == 2) return 3;
    unsigned long long i = n+2;
    while (true){
        if(isPrime(i)) return i;
        else i += 2;
    }
}

string ordinalSuffix(unsigned n){
    switch(n){
        case 1: return "st";
            break;
        case 2: return "nd";
            break;
        case 3: return "rd";
            break;
        case 0: return "";
            break;
        default: return "th";
    }
}

int main(){

    unsigned n, x, y;
    string msg;

    n = iinput("How many numbers: ");
    for(unsigned i = 0; i < n; i++){
        cout << "Input "<< i + 1 << ordinalSuffix(i + 1) << " number: \n";
        x = iinput("");
        if(isPrime(x)){
            y = nextPrime(x);
            cout << x << " is prime, and the next prime is " << y << '\n';
        } else cout << x << " is not prime.\n";
    }

    return 0;
}