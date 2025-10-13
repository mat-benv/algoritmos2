/*
Mateus Pereira Benvenutti
Algoritmos 2
*/

#include <iostream>
#include <cstring>
using namespace std;

//2. Verifique o que as funções recursivas abaixo mostram e retornam:
//a)
void func1(int n){
    if (n==0) cout << "fim";
    else{
        cout << n << " ";
        func1(n-1);
    }
}
//b)
void func2(int n){
    if(n==0) cout << "fim";
    else{
        func2(n-1);
        cout << n << " ";
    }
}
//c)
void func3(int n){
    if(n==0) cout << "fim";
    else{
        cout<<n << " ";
        func3(n-1);
        cout<<n << " ";
    }
}
//d)
void func4(int n){
    if(n==0){cout<<"fim";}
    else{
        func4(n-1);
        cout<<n << " ";
        func4(n-1);
    }
}

//3)
unsigned custom_mod(int x, int y){
    if(x > y) return custom_mod(x-y, y);
    if(x < y) return x;
    return 0;
}
//4)
void inverte_vetor(unsigned n, int v[], unsigned i = 0){
    if(n <= i) return;
    swap(v[i], v[n-1]);
    inverte_vetor(n-1,v,i+1);
}

//5)
string base10_para_base2(int x, string s = ""){
    if(s.empty()){
        if(x < 0){
            s = s + '1';
            x *= -1;
        } else {
            s = s + '0';
        }
    }
    s = s + to_string(x%2);
    x = x/2;
    if(x == 0) return s;
    return base10_para_base2(x, s);
}

//6)
//a)
unsigned sequencia_f(unsigned n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    return 2*sequencia_f(n-1) + 3*sequencia_f(n-2);
}
//b)
unsigned sequencia_ackerman(int m, int n){
   if(m == 0) return n+1;
   if(n == 0) return sequencia_ackerman(m-1, 1);
   return sequencia_ackerman(m-1, sequencia_ackerman(m, n-1));
}
//c
bool eh_palindromo(string s, unsigned i = 0){
    if(i >= s.length()/2) return true;
    if(s[i] != s[s.length()-i-1]) return false;
    return eh_palindromo(s, i+1);
}

int main(){
    int n = 5, v[3]{1,2,3};
    func1(n);
    cout << '\n';
    func2(n);
        cout << '\n';
    func3(n);
        cout << '\n';
    func4(n);
        cout << '\n';
    cout << custom_mod(10,3);
    inverte_vetor(3, v);
        cout << '\n';
    cout << v[0] << v[1] << v[2];
        cout << '\n';
    cout << base10_para_base2(-5);
        cout << '\n';
    cout << sequencia_f(5);
        cout << '\n';
    cout << sequencia_ackerman(3,2);
        cout << '\n';
    cout << eh_palindromo("boia");
        cout << '\n';
    cout << eh_palindromo("elele");
        cout << '\n';
    return 0;
}