#ifndef WORD_LIST_HPP
#define WORD_LIST_HPP

#include <memory>
using namespace std;

class wordList
{
    public : 
        shared_ptr<char> f_name;
        int length;
        char** all_words;

        wordList(const char* filename);
        ~wordList();

        //fill all_words attribute
        void all_words_of_txt_file(auto path);

        // display all words of a file
        void display_all_words();

        //check if word is contained in all_words
        bool contains(const char* word);
};

//remove puntuation at the beginin and at the end of a word , ; . ...  ) ( ] [
void remove_end_ponctuation(char* word);
void remove_beg_ponctuation(char* word);
void remove_punctuation(char* word);


#endif