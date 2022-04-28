#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
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
#include <thread>  
#include <iostream>

#include <sstream>
#include <string>
#include <vector>
#include <algorithm> 
// -- Function declaration
//

 sf::Text text;

int sizeOfList;
std::vector<std::string> collection;


void insertionSort(std::vector<int> &data);
void mainer();
void readFile(std::string &fname, std::vector<int> &data);
void writeFile(std::string &fname, std::vector<int> &data);
void writeLog(std::chrono::milliseconds duration, std::string sorting_type, std::string input_file, std::string output_file);


std::string *arrayOfNums = nullptr;
std::string int_array_to_string(std::vector<int> &int_array) {
    std::stringstream result;
    copy(int_array.begin(),int_array.end(), std::ostream_iterator<int>(result, " "));
   std::string n = result.str();
   return n;
}
// -- Main --

void mainer(){
    
    std::string sorting_type;
    std::string input_file;
    std::string output_file;

    std::cout << "Choose the input file you want to use: ";
    std::cin >> input_file; 
    std::cout << std::endl;

    std::cout << "Choose the file name of your sorted output: ";
    std::cin >> output_file;
    std::cout << std::endl;


    std::vector<int> data;
    readFile(input_file, data);
    
        // Start timer
           std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

        insertionSort(data);

        // Stop timer
        std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        writeFile(output_file, data);
        writeLog(duration, sorting_type, input_file, output_file);
   


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

// Write out log
void writeLog(std::chrono::milliseconds duration, std::string sorting_type, std::string input_file, std::string output_file){
    std::string fname = "timeLog.txt";
    std::ofstream logFile(fname, std::ofstream::app);

    if(logFile.is_open()){
        logFile <<"Time taken to " << sorting_type << " sort " << input_file << " into " << output_file << " was: " << duration.count() << " milliseconds \n";
    }else{
        std::cout << "ERROR!\n";
    }
    logFile.close();
}

// -- Sorting Algorithms --

void insertionSort(std::vector<int> &data){
    for (unsigned int i = 0; i < data.size(); i++){
        for (unsigned int j = i; j > 0; j--){
            // inserts data[j] into the sorted section
            collection.push_back(int_array_to_string(data));
            if (data[j] < data[j - 1]){
                std::swap(data[j], data[j - 1]);
            } else {
                break;
            }
        }
    }
 
}



int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 300), "Super Insertion Displayer V1.0");
   window.setVisible(true);
   mainer();    

    window.setActive();

    
      sf::Font font;
        if (!font.loadFromFile("arial.ttf"))
        {
            // error...
        }

    // run the program as long as the window is open
    while(window.isOpen())
    {
         
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
             
         for(int i = 0;i<collection.size();i++){
                sf::Text text;
            
            // select the font
            text.setFont(font); // font is a sf::Font

            // set the string to display
            text.setString(collection[i]);

            // set the character size
            text.setCharacterSize(24); // in pixels, not points!

            // set the color
            text.setFillColor(sf::Color::Red);

            // set the text style
            text.setStyle(sf::Text::Bold | sf::Text::Underlined);

            
            

            // inside the main loop, between window.clear() and window.display()
            window.draw(text);
            window.display();
            if(collection.size()>1000){
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            window.clear();
    }std::this_thread::sleep_for(std::chrono::milliseconds(7000));
    window.close();


            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;


}