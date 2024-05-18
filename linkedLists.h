#ifndef LINKED_LISTS
#define LINKED_LISTS

#include <iostream>

using namespace std;

/*
This class will hold three things
    - The website for the password
    - The username related to the password
    - The password itself
*/
class websiteUsernamePassword
{
    string website, username, password;
public:
    /*
        Default constructor
    */
    websiteUsernamePassword();

    /*
        Constructor with parameters
    */
    websiteUsernamePassword(string website, string username, string password);


    /*
        Getter for the website
    */
    string getWebsite();

    /*
        Getter for the username
    */
    string getUsername();

    /*
        Getter for the password
    */
    string getPassword();

    /*
        Setter for the website
    */
    void setWebsite();

    /*
        Setter for the website
    */
    void setUsername();

    /*
        Setter for the website
    */
    void setPassword();
};

/*
Will be a standard linked list
Will always be sorted
*/
class LinkedListPasswords
{
    websiteUsernamePassword * head;
    int count;

    void sortList();

public:
    LinkedListPasswords();

    void addToList();

    ~LinkedListPasswords();

};


#endif