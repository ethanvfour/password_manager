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
    websiteUsernamePassword * next;
public:
    /*
        Default constructor
    */
    websiteUsernamePassword();

    /*
        Constructor with parameters
    */
    websiteUsernamePassword(string, string, string);

    /*
    Sets next node for this one
    */
    void setNext(websiteUsernamePassword * nextNode);
    

    /*
    Hopefully returns next node
    */
    websiteUsernamePassword* getNext();

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
    void setWebsite(string);

    /*
        Setter for the website
    */
    void setUsername(string);

    /*
        Setter for the website
    */
    void setPassword(string);
};

/*
Will be a standard linked list
Will always be sorted
*/
class LinkedListPasswords
{
    websiteUsernamePassword * head;
    int count;


    
public:
    LinkedListPasswords();


    /*
    Adds information to list
    Will add it alphebetically hopefully
    */
    void addToList(string, string, string);


    /*
    Removes element at specified index
    */
    void removeFromList(int index);

    ~LinkedListPasswords();

};


#endif