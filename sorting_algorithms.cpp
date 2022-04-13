#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void insertionSort(std::vector<int> &data);
void mergeSort(std::vector<int> &data);
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
        mergeSort(data);
    }
    if (sorting_type == "quick"){
        quickSort(data);
    }
    if (sorting_type == "heap"){
        heapSort(data);
    } else {
        std::cout << "Did not select valid sorting algorithm.\n";
    }
}

void insertionSort(std::vector<int> &data){
    int temp;
    for (unsigned int i = 0; i < data.length(); i++){
        for (unsigned int j = i; j > 0; j--){
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

void mergeSort(std::vector<int> &data){

}

void quickSort(std::vector<int> &data){

}

void heapSort(std::vector<int> &data){

}