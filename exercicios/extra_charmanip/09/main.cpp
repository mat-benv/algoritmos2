#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

/*Faça um programa que leia uma string no formato “DD/MM/AAAA” e copie o dia,
mês e ano para 3 variáveis inteiras. Antes disso, verifique se as barras estão no lugar
certo, e se DD, MM e AAAA são numéricos.*/

#define dateStringLength 10

bool validString(string d){
    if(d.length() != dateStringLength){
        return false;
    } else {
        for(unsigned i = 0; i < dateStringLength; i++){
            if(i == 2 or i == 5){
                if(d[i] != '/') return false;
            } else if(not isdigit(d[i])) return false;
        }
    }
    return true;
}

bool isLeapYear(int y){
    if(y % 4 != 0){
        return false;
    } else if(y % 100 == 0 and y % 400 != 0){
        return false;
    }
    return true;
}

bool validDate(int d, int m, int y){
    int shortMonths[5]{2, 4, 6, 9, 11};

    if(m < 1 or m > 12) return false;
    if(y < 0) return false;
    if(d < 1 or d > 31){
        return false;
    } else if(d == 31){
        for(unsigned i = 0; i < 5; i++){
            if(m == shortMonths[i]) return false;
        }
    }
    if(m == 2 and d > 29){
        return false;
    } else if((not isLeapYear(y)) and d == 29){
        return false;
    }
    return true;
}

int main(){

    string date;
    int day, month, year;

    do{
        cout << "Input a date: \n"; getline(cin, date);
        if(not validString(date)) cout << "Data inválida. \n";
    }while(not validString(date));

    day = atoi((date.substr(0, 2)).c_str());
    month = atoi((date.substr(3, 2)).c_str());
    year = atoi((date.substr(6, 4)).c_str());

    if(not validDate(day, month, year)){
        cout << "Data inválida. \n";
    } else {
        if(day < 10) cout << "0";
        cout << day << "/"; 
        if(month < 10) cout << "0";
        cout << month << "/";
        if(year < 1000){
            cout << "0";
            if(year < 100){
                cout << "0";
                if(year < 10){
                    cout << "0";
                }
            }
        }
        cout << year << "\n";
    }


    return 0;
}