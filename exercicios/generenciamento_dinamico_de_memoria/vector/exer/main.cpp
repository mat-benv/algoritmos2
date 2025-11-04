#include <iostream>
#include <vector>
using std::vector;

//1
double scalar_product(vector<double> a, vector<double> b){
    if(a.size() != b.size()){
        std::cout << "Vectors have different sizes.\n";
        return 0.0;
    }
    if(a.empty() or b.empty()) return 0.0;

    double x = 0.0;

    for(unsigned i = 0; i < a.size(); i++){
        x += a[i]*b[i];
    }
    return x;
}
//2
int alternated_sum(vector<int> a){
    if(a.empty()) return 0;
    int x = a[0];
    for(unsigned i = 1; i < a.size(); i++){
        if(i%2 == 0) x -= a[i];
        else x += a[i];
    }
    return x;
}
//3
void reverse(vector<int> &a){
    for(unsigned i = 0; i < a.size()/2; i++){
        std::swap(a[i], a[a.size()-1-i]);
    }
}
//4
vector<int> append(vector<int> a, vector<int> b){
    vector<int> c = a;
    for(vector<int>::iterator i = b.begin(); i != b.end(); i++){
        c.push_back((*i));
    }
    return c;
}
//5
vector<int> merge(vector<int> a, vector<int> b){
    vector<int> c;
    unsigned i = 0, j = 0;
    while(true){
        if(i == a.size() and j == b.size()) break;
        if(i < a.size()){
            c.push_back(a[i]);
            i++;
        }
        if(j < b.size()){
            c.push_back(b[j]);
            j++;
        }
    }
    return c;
}
//6
vector<int> merge_sorted(vector<int> a, vector<int> b){
    vector<int> c;
    unsigned i = 0, j = 0;
    while(true){
        if(i == a.size() and j == b.size()) break;
        if((i < a.size() and a[i] <= b[j]) or j == b.size()){
            c.push_back(a[i]);
            i++;
        }
        else if(j < b.size() and b[j] <= a[i]){
            c.push_back(b[j]);
            j++;
        }
    }
    return c; 
}
//7
bool equals(vector<int> a, vector<int> b){
    if(a.size() != b.size()) return false;
    for(unsigned i = 0; i < a.size(); i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}
//8

//TODO 8, 9, 10

int main(){

    vector<double> a{1.0, 2.0, 3.0}, b{4.0, 5.0, 6.0};
    vector<int> c{1,4,6,2,3}, d{0,8,5}, g{1,2,3,5,9}, h{2,4,5,7};

    std::cout << scalar_product(a, b);
    std::cout << std::endl;
    std::cout << alternated_sum(c) << std::endl;
    reverse(c);
    for(vector<int>::iterator i = c.begin(); i != c.end(); i++){
        std::cout << *i;
    }
    std::cout << std::endl;
    vector<int> f = append(c, d);
    for(vector<int>::iterator i = f.begin(); i != f.end(); i++){
        std::cout << *i;
    }
    std::cout << std::endl;
    f = merge(c, d);
    for(vector<int>::iterator i = f.begin(); i != f.end(); i++){
        std::cout << *i;
    }
    std::cout << std::endl;
    f = merge_sorted(g, h);
    for(vector<int>::iterator i = f.begin(); i != f.end(); i++){
        std::cout << *i;
    }
    std::cout << std::endl;
    std::cout << equals(c, g) << std::endl;

    return 0;
}