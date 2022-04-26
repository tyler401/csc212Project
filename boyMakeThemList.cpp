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
// -- Function declaration
//
// -- Main --

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


int main(){
std::string out = "100kRev.txt";
int size;
int pos = 0;



std::cin >> size;
std::vector<int> data(size);
for(int i = size;i>0;i--){
data[pos] = i;
pos+=1;
}

writeFile(out,data);

}