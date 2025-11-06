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

bool contains(vector<int> a, vector<int> b){
    bool check;
    for(vector<int>::iterator i = b.begin(); i != b.end(); i++){
        check = false;
        for(vector<int>::iterator j = a.begin(); j != a.end(); j++){
            if(*i == *j){
                check = true;
                break;
            }
        }
        if(not check) return false;
    }
    return true;
}

bool same_set(vector<int> a, vector<int> b){
    return contains(a,b) and contains(b,a);
}

int partition(vector<int> &a, int low, int high){
   int pivot = a[high];
   int i = low -1;
   for(int j = low; j < high; j++){
      if(a[j] <= pivot){
         i++;
         std::swap(a[i], a[j]);
      }
   }
   std::swap(a[i+1], a[high]);

   return i+1;
}

void quicksort(vector<int> &a, int low, int high){

   if(low < high){
      int pi = partition(a, low, high);
      quicksort(a, low, pi-1);
      quicksort(a, pi+1, high);
   }

}

//9
bool same_elements(vector<int> a, vector<int> b){
    if(a.size() != b.size()) return false;
    int high = a.size() - 1;
    quicksort(a, 0, high);
    quicksort(b, 0, high);
    return equals(a, b);
}

//10
void remove_duplicates(vector<int> &a){
    for(unsigned i = 0; i < a.size(); i++){
        for(unsigned j = a.size() - 1; j > i; j--){
            if(a[i] == a[j]) a.erase(a.begin()+j);
        }
    }
}

int main(){

    vector<double> a{1.0, 2.0, 3.0}, b{4.0, 5.0, 6.0};
    vector<int> c{1,4,6,2,3}, d{0,8,5}, g{1,2,3,5,9}, h{2,4,5,7},
                m{1,2,3,4}, n{3,2,4,1}, p{3,3,4,3,2,1,2};
    std::cout << "Produto escalar: \n" << scalar_product(a, b); //1
    std::cout << std::endl;
    std::cout << "Soma alternada\n" << alternated_sum(c) << std::endl; //2
    std::cout << "Inverter: \n"; //3
    reverse(c);
    for(vector<int>::iterator i = c.begin(); i != c.end(); i++){
        std::cout << *i;
    }
    std::cout << std::endl << "Append: \n"; //4
    vector<int> f = append(c, d);
    for(vector<int>::iterator i = f.begin(); i != f.end(); i++){
        std::cout << *i;
    }
    std::cout << std::endl << "Merge: \n"; //5
    f = merge(c, d);
    for(vector<int>::iterator i = f.begin(); i != f.end(); i++){
        std::cout << *i;
    }
    std::cout << std::endl << "Merge sorted: \n"; //6
    f = merge_sorted(g, h);
    for(vector<int>::iterator i = f.begin(); i != f.end(); i++){
        std::cout << *i;
    }
    std::cout << std::endl << "Equals: \n"; //7
    std::cout << equals(c, g) << std::endl << "Same set: \n"; //8
    std::cout << same_set(m, p) << std::endl << "Same elements: \n"; //9
    std::cout << same_elements(m,n) << std::endl << "Remove duplicates: \n"; //10
    remove_duplicates(p);
    for(vector<int>::iterator i = p.begin(); i != p.end(); i++){
        std::cout << *i;
    }
    return 0;
}