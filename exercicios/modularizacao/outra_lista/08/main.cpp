/*O número 3025 tem a seguinte característica
30 + 25 = 55
552 = 3025
Faça um programa que imprima todos os números de 4 algarismos que apresentam tal característica.*/

#include <iostream>
#include <cmath>
using std::cout;

bool sumSquaredEqualsItself(unsigned);


bool sumSquaredEqualsItself(unsigned n /*4 digit integer*/){

    unsigned rightHalf = n/100;
    unsigned leftHalf = n - (rightHalf*100);
    unsigned sum = rightHalf + leftHalf;

    if(pow(sum, 2) == n) return true; else return false;

}

int main(){

    for(unsigned i = 1000; i < 10000; i++){
        if(sumSquaredEqualsItself(i)){
            cout << i << '\n';
        }
    }

    return 0;
}