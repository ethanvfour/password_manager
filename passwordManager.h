#ifndef PASSWORD_HEADER
#define PASSWORD_HEADER

#include <iostream>
#include <fstream>
#include <iomanip>
#include "linkedLists.h"

/*
This function will take in a string and use the ror implication in assembly to encrypt each byte
String is passed by ref
*/
extern "C" void encryptString(char * str, int length);

/*
This function will take in a string and use the rol implication in assembly to decrypt each byte
String is passed by ref
*/
extern "C" void decryptString(char * str, int length);

/*
Will be in charge of opening a text file and outputting the text file
*/
class passwordManager
{
    ifstream reader;
    ofstream outputter;
    LinkedListPasswords list;

public:
    /*
    Will open pass.txt
    If not found, assumes this is the first time it has been run
    else, decrypts data, and adds it to list


    A line should be like this, including the ""
    "<website>" "<username>" "<password>"
    */
    passwordManager();


    /*
    Adds the website, username, password to the list
    */
    void addPassword(string, string, string);


    /*
    Removes an element, the index given will follow standard indexing
    */
    void removePassword(int index);

    /*
    Couts all data
    */
    void viewPasswords();

    /*
    Returns how many passwords there are
    */
    int getCount();

    /*
    Opens a pass.txt then puts a encrypted string into the txt file
    */
    ~passwordManager();
};

#endif