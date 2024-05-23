#include "passwordManager.h"



/*
A line should be like this, including the ""
"<website>" "<username>" "<password>"
*/
passwordManager::passwordManager()
{
    reader.open("pass.txt");
    if (reader.is_open()) // found file
    {
        while (!reader.eof())
        {
            string lineFromFile = "";
            getline(reader, lineFromFile);
            decryptString(&lineFromFile[0], lineFromFile.length());
            
        }
    }
}

passwordManager::~passwordManager()
{
    outputter.open("pass.txt");
}