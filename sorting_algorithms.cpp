#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <sstream>
#include <random>
#include <chrono>

// -- Function declaration
//

void insertionSort(std::vector<int> &data);
void mergesort(std::vector<int> &A);
int partition(std::vector<int> &data, int low, int high);
void r_quickSort(std::vector<int> &data, int low, int high);
void quickSort(std::vector<int> &data);
void heapSort(std::vector<int> &data);

void readFile(std::string &fname, std::vector<int> &data);
void writeFile(std::string &fname, std::vector<int> &data);

// -- Main --

int main(int argc, char** argv){

    std::string sorting_type;
    std::string input_file;
    std::string output_file;

    std::cout << "Choose your sorting type: ";
    std::cin >>  sorting_type;
    std::cout << std::endl;

    std::cout << "Choose the input file you want to use: ";
    std::cin >> input_file; 
    std::cout << std::endl;

    std::cout << "Choose which output file you want to print to: ";
    std::cin >> output_file;
    std::cout << std::endl;


    std::vector<int> data;
    readFile(input_file, data);

    if (sorting_type == "insertion" || sorting_type == "Insertion" || sorting_type == "insert" || sorting_type == "Insert"){
        // Start timer
        std::chrono::system_clock::time_point start = std::chrono::high_resolution_clock::now();

        insertionSort(data);

        // Stop timer
        std::chrono::system_clock::time_point stop = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;
        writeFile(output_file, data);
    }
    else if (sorting_type == "merge" || sorting_type == "Merge"){
       // Start timer
        std::chrono::system_clock::time_point start = std::chrono::high_resolution_clock::now();

        mergesort(data);

        // Stop timer
        std::chrono::system_clock::time_point stop = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;
        writeFile(output_file, data);
    }
    else if (sorting_type == "quick" || sorting_type == "Quick"){
        // Start timer
        std::chrono::system_clock::time_point start = std::chrono::high_resolution_clock::now();

        quickSort(data);

        // Stop timer
        std::chrono::system_clock::time_point stop = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;
        writeFile(output_file, data);
    }
    else if (sorting_type == "heap" || sorting_type == "Heap"){
        // Start timer
        std::chrono::system_clock::time_point start = std::chrono::high_resolution_clock::now();
        
        int n = sizeof(data) / sizeof(data[0]);
        heapSort(data);

        // Stop timer
        std::chrono::system_clock::time_point stop = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;
        writeFile(output_file, data);
    }
    else {
        std::cout << "Did not select valid sorting algorithm.\n";
    }
}

// -- Functions --

// Read in text file
void readFile(std::string &fname, std::vector<int> &data){
    std::string line;
    std::ifstream file(fname);

    if(file.is_open()){
        while(getline(file, line, ',')){
            std::istringstream iss(line);
            int token;
            while(iss >> token){
                data.push_back(token);
            }
        }
        file.close();
    }
    else{
        std::cout << "Unable to open file" << std::endl;
    }
}

// Write out sorted file contents
void writeFile(std::string &fname, std::vector<int> &data){
    std::ofstream outFile(fname);
    unsigned int lastNumIndex = data.size()-1;

    if(outFile.is_open()){
        for(unsigned int i = 0; i < data.size(); i++){
            int num = data[i];

            if(i == lastNumIndex){
                outFile << num;
            }else{
                outFile << num << " ";
            }
        }
    }else{
        std::cout << "ERROR!\n";
    }
    outFile.close();
}

// -- Sorting Algorithms --

void insertionSort(std::vector<int> &data){
    for (unsigned int i = 0; i < data.size(); i++){
        for (unsigned int j = i; j > 0; j--){
            // inserts data[j] into the sorted section
            if (data[j] < data[j - 1]){
                std::swap(data[j], data[j - 1]);
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
    int i=lo, j= mid +1;
    for (int k= lo ; k<= hi; k++){
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

void mergesort(std::vector<int> &A){
    int n = A.size();
    int *aux = new int[n];
    r_mergesort (&A[0], aux, 0, n-1) ;
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
    // Create random device
    std::random_device rand_dev;
    // mt19937 = mersenne_twister_engine
    std::mt19937 g(rand_dev());
    // random_shuffle is no longer available changed to shuffle
    std::shuffle(data.begin(), data.begin() + n, g);
    r_quickSort(data, 0, n - 1);
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(std::vector<int> &data, int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && data[l] > data[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && data[r] > data[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		std::swap(data[i], data[largest]);

		// Recursively heapify the affected sub-tree
		heapify(data, n, largest);
	}
}

// main function to do heap sort
void heapSort(std::vector<int> &data)
{
    int n = data.size();
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(data, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--) {
		// Move current root to end
		std::swap(data[0], data[i]);

		// call max heapify on the reduced heap
		heapify(data, i, 0);
	}
}
