#include <iostream>

int partition(int vector[], int low, int high){
   int pivot = vector[high];
   int i = low -1;
   for(int j = low; j < high; j++){
      if(vector[j] <= pivot){
         i++;
         std::swap(vector[i], vector[j]);
      }
   }
   std::swap(vector[i+1], vector[high]);

   return i+1;
}

void quicksort(int vector[], int low, int high){

   if(low < high){
      int pi = partition(vector, low, high);
      quicksort(vector, low, pi-1);
      quicksort(vector, pi+1, high);
   }

}

int main(){

   int vector[5]{5,1,2,9,4};

   quicksort(vector, 0, 4);

   for(unsigned i = 0; i < 5; i++){
      std::cout << " " << vector[i];
   }

   return 0;
}