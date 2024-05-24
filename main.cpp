#include <iostream>
#include "passwordManager.h"
#include "coolFunctions.h"

using namespace std;

int main()
{
    coolOutput("Welcome to password manager!\n");
    waitThisLong(1);
    passwordManager pm;
    bool endOfUse = false;
    while (!endOfUse)
    {
        coolOutputNoClear("What would you like to do?\n");
        coolOutputNoClear("1. View Passwords\n");
        coolOutputNoClear("2. Add a Password\n");
        coolOutputNoClear("3. Delete a Password\n");
        coolOutputNoClear("4. Exit Program\n**");
        int userChoice = -1;
        cin >> userChoice;
        if (cin.fail() || ((userChoice < 1) || (userChoice > 4)))
        {
            cin.clear();
            cin.ignore('\n', 1000);
            coolOutput("Not good input\n");
            waitThisLong(1);
        }
        else
        {
            
            if(userChoice == 1)
            {
                /* code */
                coolOutput("");
                pm.viewPasswords();
                waitThisLong(4);
            }
            else if(userChoice == 2)
            {
                string website = "", username = "", password = "", uAns = "";
                cin.clear();
                cin.ignore(256, '\n');

                bool websiteGood = false;
                while (!websiteGood)
                {
                    coolOutput("What is the website for this password?\n**");
                    getline(cin, website);
                    coolOutput("");
                    coolOutputNoClear("Is this correct?\n");
                    coolOutputNoClear(website);
                    coolOutputNoClear(" Y/N\n**");
                    getline(cin, uAns);
                    if(uAns[0] == 'Y' || uAns[0] == 'y')
                    {
                        websiteGood = true;
                    }
                }

                bool usernameGood = false;
                while(!usernameGood)
                {
                    coolOutput("What is the username for this password?\n**");
                    getline(cin, username);
                    coolOutputNoClear("Is this correct?\n");
                    coolOutputNoClear(username);
                    coolOutputNoClear(" Y/N");
                    getline(cin, uAns);
                    if(uAns[0] == 'Y' || uAns[0] == 'y')
                    {
                        usernameGood = true;
                    }
                }

                bool passwordGood = false;
                while(!passwordGood)
                {
                    coolOutput("Finally, what is the password?\n**");
                    getline(cin, password);
                    coolOutputNoClear("Is this correct?\n");
                    coolOutputNoClear(password);
                    coolOutputNoClear(" Y/N");
                    getline(cin, uAns);
                    if(uAns[0] == 'Y' || uAns[0] == 'y')
                    {
                        passwordGood = true;
                    }
                }

                pm.addPassword(website, username, password);
                coolOutput("");
            }
            else if(userChoice == 3)
            {
                int index = -1000;

                bool goodIndex = false;
                while(!goodIndex)
                {
                    pm.viewPasswords();
                    coolOutputNoClear("Which index do you want to delete? If pressed by mistake, enter -1\n**");
                    cin >> index;
                    if(cin.fail() || ((index < 1) || (index > pm.getCount())))
                    {
                        cin.clear();
                        cin.ignore('\n', 1000);
                        coolOutput("Not good input\n");
                        waitThisLong(1);
                    }
                    else
                    {
                        index--; //needed for standard indexing 
                        pm.removePassword(index);
                    }
                }
            }
            else if(userChoice == 4)
            {
                endOfUse = true;
                coolOutput("Saving password to database...");
                waitThisLong(2);
                cout << endl;
            }
            else
            {
                coolOutput("ERROR: GIVING OPTIONS AGAIN!\n");
                waitThisLong(1);
            }
            
        }
    }
}