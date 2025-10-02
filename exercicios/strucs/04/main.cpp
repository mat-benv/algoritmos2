/*Implemente um programa que leia n códigos de profissão e o respectivo nome da
profissão. Em seguida, leia um número indeterminado de códigos e informe, para
cada código lido, o nome da profissão correspondente. Elabore uma subrotina para
informar o nome da profissão.*/

#include <iostream>
using namespace std;

typedef struct{
   unsigned code;
   string name;
} profession;

#define MAX 5 //changeble

void print_profession(unsigned, profession [], unsigned);
bool continue_task(string);
bool check_profession_code(unsigned, profession [], unsigned);
profession get_profession(profession [], unsigned);
unsigned uinput(string);
bool isUnsigned(string);

int main(){

   profession professions[MAX];
   unsigned n, code;

   n = uinput("How many profession codes: ");
   for(unsigned i = 0; i < n; i++){
      cout << "Profession " << i+1 << '\n';
      professions[i] = get_profession(professions, n);
   }

   do{
      code = uinput("Input code to search: \n");
      if(check_profession_code(code, professions, n)){
         print_profession(code, professions, n);
      }
   }while(continue_task("Another check? Y/NS"));

   return 0;
}

void print_profession(unsigned code, profession list[], unsigned n){
   for(unsigned i = 0; i < n; i++){
      if(code == list[i].code){
         cout << list[i].name << '\n';
      }
   }
}

bool continue_task(string msg){
   char o;
   do{
      cout << msg;
      cin >> o;
      if(toupper(o)!='Y' and toupper(o)!='N') cout << "Invalid input. \n";
   }while(toupper(o) != 'Y' and toupper(o) != 'N');
   if(toupper(o) == 'Y') return true;
   //else
   return false;
}

bool check_profession_code(unsigned code, profession list[], unsigned n){
   for(unsigned i = 0; i < n; i++){
      if(code == list[i].code) return true;
   }
   return false;
}

profession get_profession(profession list[], unsigned n){
   profession p;
   do{
      p.code = uinput("Input code: ");
      if(check_profession_code(p.code, list, n)) cout << "Code in use.\n";
   }while(check_profession_code(p.code, list, n));
   cout << "Input name: \n";
   getline(cin, p.name);
   return p;
}

unsigned uinput(string msg){
   string s;
   do{
      cout << msg << "\n"; getline(cin, s);
      if(not isUnsigned(s)) cout << "Not a valid input. Try again. \n";
   }while(not isUnsigned(s));
   return atoi(s.c_str());
}

bool isUnsigned(string s){
    for(unsigned i = 0; i < s.length(); i++){
        if(not isdigit(s[i])) return false;
    }
    return true;
}