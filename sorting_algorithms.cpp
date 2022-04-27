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
#include <iomanip>
#include <ctime>

// -- Function declarations --

// - Sort declarations -

void insertionSort(std::vector<int> &data);
void mergesort(std::vector<int> &A);
int partition(std::vector<int> &data, int low, int high);
void r_quickSort(std::vector<int> &data, int low, int high);
void quickSort(std::vector<int> &data);
void heapSort(std::vector<int> &data);

// - File access declarations -

void readFile(std::string &fname, std::vector<int> &data);
void writeFile(std::string &fname, std::vector<int> &data);
void writeLog(std::chrono::milliseconds duration, std::string sorting_type, std::string input_file, std::string output_file);

// -- Main --

int main(int argc, char** argv){

    // Create strings for the user inputs
    std::string sorting_type;
    std::string input_file;
    std::string output_file;

    // Request sort type from user
    std::cout << std::endl;
    std::cout << "Choose your sorting type (inserion, merge, quick, heap): ";
    std::cin >>  sorting_type;
    std::cout << std::endl;

    // Request input file from user
    std::cout << "Choose the input file you want to use: ";
    std::cin >> input_file; 
    std::cout << std::endl;

    // Request a custom output file name from user
    std::cout << "Choose the file name of your sorted output: ";
    std::cin >> output_file;
    std::cout << std::endl;

    // Call readFile on the chosen input file
    std::vector<int> data;
    readFile(input_file, data);

    // -- if statments for each possible user-input sort --

    if (sorting_type == "insertion" || sorting_type == "Insertion" || sorting_type == "insert" || sorting_type == "Insert"){
        // Start timer
           std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

        insertionSort(data);

        // Stop timer
        std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        writeFile(output_file, data);
        writeLog(duration, sorting_type, input_file, output_file);
    }
    else if (sorting_type == "merge" || sorting_type == "Merge"){
       // Start timer
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

        mergesort(data);

        // Stop timer
        std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        writeFile(output_file, data);
        writeLog(duration, sorting_type, input_file, output_file);
    }
    else if (sorting_type == "quick" || sorting_type == "Quick"){
        // Start timer
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

        quickSort(data);

        // Stop timer
        std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        writeFile(output_file, data);
        writeLog(duration, sorting_type, input_file, output_file);
    }
    else if (sorting_type == "heap" || sorting_type == "Heap"){
        // Start timer
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
        
        int n = sizeof(data) / sizeof(data[0]);
        heapSort(data);

        // Stop timer
        std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        writeFile(output_file, data);
        writeLog(duration, sorting_type, input_file, output_file);
    }
    // If no valid sort is input output error message
    else {
        std::cout << "Did not select valid sorting algorithm.\n";
    }
}

// -- Functions --

// Read in text file
void readFile(std::string &fname, std::vector<int> &data){
    std::string line;
    std::ifstream file(fname);

    // Read in the array from the file (accounting for commas)
    if(file.is_open()){
        while(getline(file, line, ',')){
            std::istringstream iss(line);
            int token;
            while(iss >> token){
                data.push_back(token);
            }
        }
        // Close input file after reading is complete
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

// Write out time log
void writeLog(std::chrono::milliseconds duration, std::string sorting_type, std::string input_file, std::string output_file){
    std::string fname = "timeLog.txt";
    std::ofstream logFile(fname, std::ofstream::app);

    // Cout message for the time taken for specific sort on specific file
    if(logFile.is_open()){
        logFile <<"Time taken to " << sorting_type << " sort " << input_file << " into " << output_file << " was: " << duration.count() << " milliseconds \n";
    }else{
        std::cout << "ERROR!\n";
    }
    // Close file after each individual sort
    logFile.close();
}

// -- Sorting Algorithms --

// - Insertion Sort -

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

// - Merge Sort -

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

// - Quick Sort -

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

// - Heap Sort -

// Function to create the heap from an array
void heapify(std::vector<int> &data, int n, int i)
{
    // Set largest as root
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < n && data[l] > data[largest])
		largest = l;

	// If right child is larger than the current largest
	if (r < n && data[r] > data[largest])
		largest = r;

	// If largest is not root swap it
	if (largest != i) {
		std::swap(data[i], data[largest]);

		// Repeat the heapify process
		heapify(data, n, largest);
	}
}

// Main function to sort the heap
void heapSort(std::vector<int> &data)
{
    int n = data.size();
	// Construct heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(data, n, i);

	// One by one extract element from heap
	for (int i = n - 1; i >= 0; i--) {
		// Move current root to end
		std::swap(data[0], data[i]);

		// call heapify on the reduced heap
		heapify(data, i, 0);
	}
}