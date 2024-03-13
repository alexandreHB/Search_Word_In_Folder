#include "wordList.hpp"
#include <iostream>
#include <fstream>
#include <cstring>  // for std::strcpy
#include <cctype>   //for ispunct

using namespace std;

wordList::wordList(const char* filename)
{
    size_t path_length = strlen(filename) + 1; // +1 for '\0'
    shared_ptr<char> f_name(new char[path_length], [](char* p) { delete[] p; });
    strcpy(f_name.get(), filename);
    
    length = 0;

    all_words_of_txt_file(filename);
}


wordList::~wordList()
{
    if (all_words != nullptr)
    {
        for(int i = 0; i < length; i++)
            delete[] all_words[i];
        delete[] all_words;
    }
}



// fill all_words attribute with all the words of the txt file given in path args
void wordList::all_words_of_txt_file(auto path)
{    
    ifstream myfile(path);

    if (!myfile.is_open()) //case where file couldn't be opened
    {
        cerr << "Error : Impossible to open the file " << endl;
        all_words = nullptr;
        return;
    }

    // Count amount of words in the file
    char wordBuffer[256];
    while (myfile >> wordBuffer)
        length++;

    all_words = new char*[length];

    // Reinitialize cursor to begining of the file
    myfile.clear();
    myfile.seekg(0, std::ios::beg);

    //fill all_words attribute
    for (int i = 0; i < length; ++i)
    {
        myfile >> wordBuffer;
        remove_punctuation(wordBuffer);
        all_words[i] = new char[strlen(wordBuffer) + 1];
        strcpy(all_words[i], wordBuffer);
    }
}




// display all the words of all_words attributes,
//thus, all the words of the txt file associated to the wordList Object
void wordList::display_all_words()
{
    if(all_words == nullptr)
        cout << "vide" << endl;
    
    else
    {
        cout << f_name << " : "  << endl;
        for(int i = 0; i < length; i++)
            cout << all_words[i] << " ";
        cout << endl;
    }
}

//check if word is contained in all_words
bool wordList::contains(const char* word)
{
    for(int i=0; i < length; i++)
        if(strcmp(all_words[i], word) == 0)
            return true;

    return false;
}


void remove_end_punctuation(char* word)
{   
    for (int i = strlen(word)-1; i >= 0; i--)
    {
        if (ispunct(word[i]))
            word[i] = '\0';
        else
            break;
    }
}
void remove_beg_punctuation(char* word)
{
    while (*word != '\0')
    {
        if (ispunct(*word))
            ++word;
        else
            break;
    }
}
void remove_punctuation(char* word)
{
    remove_end_punctuation(word);
    remove_beg_punctuation(word);
}