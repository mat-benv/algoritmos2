#include <iostream>
#include <cstring>
using namespace std;

/*Leia duas strings A e B, e determine quantas vezes a string A ocorre na string B*/

int main(){

    string strA, strB;
    unsigned count=0;
    bool found;

    do{
        cout << "Input a sentence: \n"; getline(cin, strA);
    }while(strA.empty());

    do{
        cout << "Input another sentence: \n"; getline(cin, strB);
    }while(strB.empty());

    for(unsigned i = 0; i < strA.length(); i++){
        
        if(toupper(strA[i]) == toupper(strB[0])){
            found = true;
            for(unsigned j = 1; j < strB.length(); j++){
                if(toupper(strA[i+j]) != toupper(strB[j])){
                    found = false;
                    break;
                }
            }
            if(found) count++;
        }
    }

    cout << "The second string is repeated " << count << " times in the first string.\n";

    return 0;
}