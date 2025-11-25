#include <iostream>
#include <fstream>
#include <vector>

typedef struct Node{
    char name[51]; //c_str
    int code, qtt;
    Node *next;
} ItemList;

typedef struct{
    char name[51];
    int code, qtt;
} Item;

void include_item(ItemList* &ptr_list, ItemList* x){
    if(ptr_list == NULL){
        ptr_list = x;
        x->next == NULL;
        return;
    }
    x->next = ptr_list;
    ptr_list = x;
}

void save_items(Item* ptr_list, std::string filename){

}