#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

void insertionSort(std::vector<int> &data);
void mergeSort(std::vector<int> &data);
int partition(std::vector<int> &data, int low, int high);
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
    for (unsigned int i = 0; i < data.size(); i++){
        for (unsigned int j = i; j > 0; j--){
            // inserts data[j] into the sorted section
            if (data[j] < data[j - 1]){
                std::swap(data[i], data[j - 1]);
            } else {
                break;
            }
        }
    }
}

void merge(int *A, int *aux, int lo, int mid, int hi) {
// copy array
    std::memcpy(aux+lo, A+lo, (hi-lo+1) * sizeof(int));
// merge
    int i=lo,j= mid +1;
    for (int k= lo ; k<= hi: k++){
        if (i > mid) A[k]= aux[j++];
        else if (j > hi) A[k] = aux[i++];
        else if (aux[j] < aux[i]) A[k]= aux[j++];
        else A[k]= aux[i++];
        }
}

void r_mergesort(int *A, int *aux, int lo, int hi){
// base case (single element or empty list)
     if (hi<= lo) return;
    int mid = lo + (hi-lo) / 2;
    // recursively sort halves
    r_mergesort(A, aux, lo, mid);
    r_mergesort (A, aux, mid+1, hi);
// merge results
    merge(A, aux, lo, mid, hi);
}

void mergesort (int *A, int n){
    int *aux = new int[n];
    r_mergesort (A, aux, 0, n-1) ;
    delete [] aux;
}

int partition(std::vector<int> &data, int low, int high){
    int i = low;
    int j = high + 1;
    while (1) {
        // while data[i] is less than the pivot, increase i
        while (data[++i] < data[low]){
            if (i == high){
                break;
            }
        }
        // while data[i] is greater than the pivot, decrease j
        while (data[low] < data[--j]){
            if (j == low){
                break;
            }
        }
        // if i and j cross, break
        if (i >= j){
            break;
        } 
        std::swap(data[i], data[j]);
    }
    // swap the pivot with data[j]
    std::swap(data[low], data[j]);
    // return the pivot's location
    return j;
}
void r_quickSort(std::vector<int> &data, int low, int high){
    if (high <= low){
        return;
    }
    int p = partition(data, low, high);
    r_quickSort(data, low, p - 1);
    r_quickSort(data, p + 1, high);
}

void quickSort(std::vector<int> &data){
    int n = data.size();
    std::random_shuffle(data.begin(), data.begin() + n);
    r_quickSort(data, 0, n - 1);
}

void heapSort(std::vector<int> &data){

}
