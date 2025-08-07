#include <iostream>

using namespace std;

#define max 15

int main(){

    int fib[max] = {1, 1};

    for(int i = 2; i < max; i++){

        fib[i] = fib[i-1] + fib[i-2];

    }

    for(int i = 0; i < max; i++){
        cout << "[" << fib[i] << "] ";
    }

    cout << endl;

    return 0;
}