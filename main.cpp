#include <iostream>
#include <fstream>
#include <stdexcept> 
#include "main.hpp"


using namespace std;

int main(int argc, char** argv)
{
    
    if(argv[1] == nullptr) //if no path given
        throw logic_error("folder path required !");
    auto path = argv[1];

    if(fs::is_empty(path))
        throw logic_error("folder is empty !");

    

    string input;
    char** txt_files;
    int txt_files_size = 0;
    do
    {
        cout << "What word are tou looking for? Only the first word would be treated ('quit' to quit): ";
        cin >> input;
        
        // allow to deal with only 1st word written in input
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (input != "quit")
        {
            txt_files_containing_words(path, input.c_str(), txt_files, txt_files_size);
            display_files(txt_files, txt_files_size);
        }
    } while (input != "quit");
    

    return 0;
}