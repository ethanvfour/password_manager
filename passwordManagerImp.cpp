#include "passwordManager.h"
#include <sstream>
#include "coolFunctions.h"

passwordManager::passwordManager()
{
    reader.open("pass.txt");
    if (reader.is_open()) // found file
    {
        while (!reader.eof())
        {
            string lineFromFile = "";
            getline(reader, lineFromFile);
            if (reader.eof())
            {
                // empty space at end
            }
            else
            {
                decryptString(&lineFromFile[0], lineFromFile.length());
                stringstream adder(lineFromFile);
                string website = "", username = "", password = "", waste = "";
                getline(adder, waste, '"');    // gets the start
                getline(adder, website, '"');  // website
                getline(adder, waste, '"');    // gets the space between website and username
                getline(adder, username, '"'); // gets the start
                getline(adder, waste, '"');    // gets the space between username and password
                getline(adder, password, '"'); // gets the password
                list.addToList(website, username, password);
            }
        }
    }
}

void passwordManager::addPassword(string website, string username, string password)
{
    list.addToList(website, username, password);
}

void passwordManager::viewPasswords()
{
    if (list.getCount() != 0)
    {
        cout<<left;
        cout<<setfill('*')<<setw(100)<<"";
        cout<<setfill(' ');

        cout<<endl;
        for (int i = 0; i < list.getCount(); i++)
        {
            websiteUsernamePassword *goer = list.getNode(i);

            
            cout << to_string(i + 1) <<". Website: "
                 << setw(20)<< goer->getWebsite()
                 <<" Username: "
                 << setw(20) << goer->getUsername()
                 <<" Password: "
                 <<setw(20)<< goer->getPassword()<<endl;
                
            
        }
        cout<<setfill('*')<<setw(100)<<"";
        cout<<setfill(' ');
        cout<<endl;
    }
    else
    {
        cout << "No passwords given!\n";
    }
}

passwordManager::~passwordManager()
{
    if (reader.is_open())
    {
        reader.close();
    }
    outputter.open("pass.txt");
    for (int i = 0; i < list.getCount(); i++)
    {
        websiteUsernamePassword *temp = list.getNode(i);
        string adder = "";
        // website
        adder.append("\""); // start of the "
        adder.append(temp->getWebsite());
        adder.append("\" "); // end of the " with a space

        // username
        adder.append("\""); // start of the "
        adder.append(temp->getUsername());
        adder.append("\" "); // end of the " with a space

        // password
        adder.append("\""); // start of the "
        adder.append(temp->getPassword());
        adder.append("\""); // end of the "

        // now we encrypt
        encryptString(&adder[0], adder.length());

        outputter << adder << endl;
    }
}