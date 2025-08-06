#include <iostream>

using namespace std;

#define max 10

int main(){

    int vec[max];

    for(int i = 1; i <= max; i++){
        vec[i-1] = 5*i;
        cout << "[" << vec[i-1] << "] ";
    }

    cout << endl;
    
    return 0;
}