#ifndef MAIN_HPP
#define MAIN_HPP
#include <filesystem>
#include <string>
#include <stdlib.h>         //for malloc and realloc
#include <cstring>          //for strcpy
#include "wordList.hpp"



using namespace std;
namespace fs = std::filesystem;



/**
 * @brief Function that fill a char**  with all txt files that contains the desired word
 * 
 * 
 * @param path path of the folder we search in
 * @param word the desired word we search
 * @param txt_files The variable that will contains the names of every txt file that contain the desired word
 * @param size the size of txt_files, thus the number of txt file that contains the desired word
 * @return void, it modifies directly txt_files variable with reference
 */

void txt_files_containing_words(const char* path, auto word, char**& txt_files, int& size)
{
    txt_files = (char**)malloc(sizeof(char*));
    size = 0;

    for (const auto& entry : fs::recursive_directory_iterator(path))                        //run through all files of the folder
    {
        if(entry.is_regular_file() & entry.path().extension() == ".txt")                    //if the file is a txt file
        {
            wordList w = wordList(entry.path().lexically_normal().string().c_str());        //construct a worldList object associated to the running txt file

            if(w.contains(word))
            {
                size++;
                txt_files = (char**)realloc(txt_files, size * sizeof(char*));
                txt_files[size-1] = (char*)malloc((entry.path().filename().string().length() + 1) * sizeof(char));
                strcpy(txt_files[size-1], entry.path().filename().string().c_str());
            }
        }
    }
    
    if(size == 0) //no files contains the searched word
        txt_files = nullptr;
}

//display the content of txt_files, thus, all the txt files that contains the desired word
void display_files(char**& tab, int size)
{
    if(size == 0)
        cout << "no file with the desired word" << endl;
    else
    {
        for (int i = 0; i < size; i++) 
            cout << tab[i] << " ";
        cout << endl;
    }
}

#endif