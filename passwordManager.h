#ifndef PASSWORD_HEADER
#define PASSWORD_HEADER

#include <iostream>
#include <fstream>
#include "linkedLists.h"

/*
This function will take in a string and use the ror implication in assembly to encrypt each byte
String is passed by ref
*/
extern "C" void encryptString(string & str, int length);

/*
This function will take in a string and use the rol implication in assembly to decrypt each byte
String is passed by ref
*/
extern "C" void decryptString(string & str, int length);





/*
Will be in charge of opening a text file and outputting the text file
*/
class passwordManager
{
    ifstream reader;
    ofstream outputter;
    LinkedListPasswords list;
public:
    passwordManager();


    ~passwordManager();
    
};

#endif