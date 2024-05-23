#include "passwordManager.h"




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



void passwordManager::addPassword(string website, string username, string password)
{
    list.addToList(website, username, password);
}

passwordManager::~passwordManager()
{
    outputter.open("pass.txt");
}