#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void insertionSort(std::vector<int> &data);
void mergeSort(std::vector<int> &data);
void partition(std::vector<int> &data, int low, int high);
void r_quickSort(std::vector<int> &data, int low, int high);
void quickSort(std::vector<int> &data);
void heapSort(std::vector<int> &data);

int main(int argc, char** argv){
    std::string sorting_type = argv[1];
    std::string input_file = argv[2];
    std::string output_file = argv[3];

    std::vector<int> data;

    if (sorting_type == "insertion"){
        insertionSort(data);
    }
    if (sorting_type == "merge"){
        //mergeSort(data);
    }
    if (sorting_type == "quick"){
       // quickSort(data);
    }
    if (sorting_type == "heap"){
       // heapSort(data);
    } else {
        std::cout << "Did not select valid sorting algorithm.\n";
    }
}

void insertionSort(std::vector<int> &data){
    // temp variable for swapping later
    int temp;
    for (unsigned int i = 0; i < data.size(); i++){
        for (unsigned int j = i; j > 0; j--){
            // inserts data[j] into the sorted section
            if (data[j] < data[j - 1]){
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
            } else {
                break;
            }
        }
    }
}

void mege(std::vector<int> &data, int left,int middle, int right){
    std::vector<int> rec(data.begin() + left, data.begin() + right + 1);


}

void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;

   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
 
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
  
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {      
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
 
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

void partition(std::vector<int> &data, int low, int high){
    int i = low;
    int j = high + 1;
    while (1) {
        while (A[++i] < A[low])
    }
}
void r_quickSort(std::vector<int> &data, int low, int high){

}
void quickSort(std::vector<int> &data){

}

void heapSort(std::vector<int> &data){

}
