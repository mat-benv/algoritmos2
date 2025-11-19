#include <iostream>
#include <fstream>

typedef struct Node{
    std::string name, course;
    double grade;
    Node *next;
} Student;

Student* register_students(std::string line){
    Student* s = new Student;
    std::string x;
    int j = 0;
    for(unsigned i = 0; i < line.length(); i++){
        switch(j){
            case 0:
                if(line[i] == ','){
                    j++;
                    break;
                }
                s->name += line[i];
                break;
            case 1:
                if(line[i] == ','){
                    j++;
                    break;
                }
                s->course += line[i];
                break;
            case 2:
                x += line[i];
                break;
        }
    }
    s->grade = atof(x.c_str());
    return s;
}

void get_students(Student* &ptrlist, std::string filename){
    std::ifstream fin;
    std::string line;
    int i = 0, j = 0;

    fin.open(filename.c_str());
    if(fin.fail()){
        std::cout << "Can't open file.\n";
    }
    while(getline(fin, line)){
        Student* n = new Student;
        if(n != NULL){
            std::cout << "No memory.";
            std::cin.get();
            exit(0);
        }
        n = register_students(line);
        order_students(ptrlist, n);
        n->next = ptrlist;
        ptrlist = n;
    }
    fin.close();
}

void order_students(Student* &ptrlist, Student* n){
    if(ptrlist == NULL){
        ptrlist == n;
        n->next == NULL;
        return;
    }
    Student* previous = new Student;
    if(previous == NULL){
        std::cout << "No memory.\n";
        std::cin.get();
        exit(0);
    }
    Student* aux = ptrlist;
    while(aux != NULL){
        previous = aux;
        aux = aux->next;
        if(n->name < aux->name){
            n->next = aux;
            previous->next = n;
        }
    }
}