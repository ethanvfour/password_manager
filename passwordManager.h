#ifndef PASSWORD_HEADER
#define PASSWORD_HEADER

#include <iostream>
#include <fstream>
#include "linkedLists.h"



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