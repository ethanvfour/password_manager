#ifndef PASSWORD_HEADER
#define PASSWORD_HEADER

#include <iostream>
#include <fstream>



/*
Will be in charge of opening a text file and outputting the text file
*/
class passwordManager
{
    ifstream reader;
    ofstream outputter;
public:
    passwordManager();
    

    ~passwordManager();
    
};

#endif