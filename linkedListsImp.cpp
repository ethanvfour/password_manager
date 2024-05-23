/*
NOTES FOR FUNCTIONS IS IN HEADER
*/

#include <linkedLists.h>

// Implications for websiteUsernamePassword

websiteUsernamePassword::websiteUsernamePassword()
{
    website = "";
    username = "";
    password = "";
    next = nullptr;
}

websiteUsernamePassword::websiteUsernamePassword(string website, string username, string password)
{
    this->website = website;
    this->username = username;
    this->password = password;
    next = nullptr;
}

void websiteUsernamePassword::setNext(websiteUsernamePassword *nextNode)
{
    next = nextNode;
}

websiteUsernamePassword *websiteUsernamePassword::getNext()
{
    return next;
}

string websiteUsernamePassword::getWebsite()
{
    return website;
}

string websiteUsernamePassword::getUsername()
{
    return username;
}

string websiteUsernamePassword::getPassword()
{
    return password;
}

void websiteUsernamePassword::setWebsite(string website)
{
    this->website = website;
}

void websiteUsernamePassword::setUsername(string username)
{
    this->username = username;
}

void websiteUsernamePassword::setPassword(string password)
{
    this->password = password;
}

// Implications for LinkedListPasswords

LinkedListPasswords::LinkedListPasswords()
{
    head = nullptr;
    count = 0;
}

void LinkedListPasswords::addToList(string website, string username, string password)
{
    /*
    Cases I can think of
        - Head == nullptr
            - just make head point to it
        - Head != nullptr
            - Adding to start
            - Adding to end
            - Adding in middle
    */
    count++;

    if (head == nullptr)
    {
        head = new websiteUsernamePassword(website, username, password);
    }
    else
    {
        if (tolower(website[0]) < tolower(head->getWebsite()[0])) // Adding to start
        {
            websiteUsernamePassword *adder = new websiteUsernamePassword(website, username, password);
            adder->setNext(head);
            head = adder;
        }
        else // adding to middle and end
        {
            websiteUsernamePassword *goer = head;
            // websiteUsernamePassword * prev = nullptr;
            while (goer != nullptr)
            {
                if (goer->getNext() == nullptr) // end case
                {
                    websiteUsernamePassword *adder = new websiteUsernamePassword(website, username, password);
                    goer->setNext(adder);
                    goer = nullptr;
                }
                else // middle case
                {
                    if (tolower(website[0]) <= tolower(goer->getNext()->getWebsite()[0]))
                    {
                        websiteUsernamePassword *adder = new websiteUsernamePassword(website, username, password);
                        adder->setNext(goer->getNext());
                        goer->setNext(adder);
                        goer = nullptr;
                    }
                    else
                    {
                        goer = goer->getNext();
                    }
                }
            }
        }
    }
}

void LinkedListPasswords::removeFromList(int index)
{
    if (index == 0)
    {
        websiteUsernamePassword *temp = head;
        head = head->getNext();
        delete temp;
        count--;
    }
    else
    {
        int counter = 0;
        websiteUsernamePassword *goer = head;
        websiteUsernamePassword *prev = nullptr;
        while (counter != index)
        {
            prev = goer;
            goer = goer->getNext();
            counter++;
        }
        prev->setNext(goer->getNext());
        delete goer;
        goer = nullptr;
        count--;
    }
}

int LinkedListPasswords::getCount()
{
    return count;
}

LinkedListPasswords::~LinkedListPasswords()
{
    while (head != nullptr)
    {
        websiteUsernamePassword *goer = head->getNext()->getNext();
        delete head;
        head = goer;
    }
}
