#include <cctype>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void getString(string &str)
{

    int i = 0;
    int states = 0;
    bool istrap = false;

    for (i = 0; i < str.size(); i++)
    {

        switch (states)
        {
        // here it checks if the starting alphabet is lowecase or not
        case 0:

            if (islower(str[i]))
            {
                states = 1;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            else
            {
                states = 8;
                istrap == true;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            break;

            // case 1 loops through all the numbers and alphabets and if it finds a dot it goes back to case 0 andif it finds an @ i goes to case 2
        case 1:
            if (islower(str[i]) || isdigit((str[i])))
            {
                states = 1;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            if ((str[i]) == '.')
            {
                states = 0;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            if ((str[i]) == '@')
            {
                states = 2;

                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }

            break;

            // here in case 2 it checks if there is a aphabet after @ and if it is not found it goes to trap state that is case 8
        case 2:
            if (islower((str[i])))
            {
                states = 3;

                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            else
            {
                states = 8;
                istrap = true;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            break;

            // here it loops through all the alphabets or numbers and if it gets a dot it goes to case 4

        case 3:
            if (islower((str[i])) || isdigit((str[i])))
            {
                states = 3;

                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            else if ((str[i]) == '.')
            {
                states = 4;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            else
            {
                states = 8;
                istrap = true;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            break;

            // if a c is found after dot it goes to state 5 and anything other than c goes to case 3 and loops back
        case 4:
            if ((str[i]) == 'c')
            {
                states = 5;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            else if (isalpha(str[i]) && islower((str[i])) != 'c')
            {
                states = 3;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            else
            {
                states = 8;
                istrap = true;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            break;
            // here if a o is found it goes to case 6 anything other than o goes to case 3 and if a dot is found it goes to case 4
        case 5:
            if ((str[i]) == 'o')
            {
                states = 6;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            else if ((str[i]) == '.')
            {
                states = 4;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            else if (islower((str[i])) || isdigit((str[i])))
            {

                states = 3;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            else
            {
                states = 8;
                istrap = true;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            break;
            // here it checks if m is found or not and im also checking if m is the last character in the string or not if it is it goes to string 7 and it gets accepted anything other than that goes back to case 3(alpha and digits) and case 4(dot)
        case 6:
            if ((str[i]) == 'm')
            {
                states = 7;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
                if (i == str.size() - 1)
                {

                    cout << str << "Final State: string is accepted\n";
                }
            }
            else if ((str[i]) == '.')
            {
                states = 4;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            else if (islower((str[i])) || isdigit((str[i])))
            {
                states = 3;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
                continue;
            }
            else
            {
                states = 8;
                istrap = true;
                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }
            break;
            // here again im checking the same thing as case 6
        case 7:
            if ((str[i]) == 'm')
            {

                if (i == str.size() - 1)
                {

                    if (istrap == true)
                    {
                        printf("String is rejected122");
                        break;
                    }
                    cout << str << "Final State: string is accepted\n";
                }
                if (islower((str[i])) || isdigit((str[i])))
                {
                    states = 3;

                    cout << "CHARACTER IS " << str[i] << " "
                         << "STATE IS IN"
                         << " " << states << "\n";
                }
            }
            if (islower((str[i])) || isdigit((str[i])))
            {
                states = 3;

                cout << "CHARACTER IS " << str[i] << " "
                     << "STATE IS IN"
                     << " " << states << "\n";
            }

            // trap state
        case 8:
            istrap = true;
            cout << "CHARACTER IS " << str[i] << " "
                 << "STATE IS IN"
                 << " " << states << "\n";
            break;
        }
    }
    // if anything doesnt end up in state 7 which is accepting state it is rejected
    if (states != 7)
    {
        printf("string is rejected1\n");
    }
}

int main()
{
    cout << "Project 1 for CS 341 \n";
    cout << "Section number:005 \n";
    cout << "Semester: Fall 2022\n";
    cout << "Written by: Ishita Bhatt UCID: ijb4 \n";
    cout << "Instructor: Marvin Nakayama, marvin@njit.edu\n";

    char vl;       // gets char n or y
    string newStr; // stores the string in it
    cout << "Would you like to enter a string? (y/n): \n " << endl;
    cin >> vl;
    if (vl == 'n' || vl == 'N')
    {
        printf("You choose no!");
        exit(1);
    }
    else if (vl == 'y' || vl == 'Y')
    {
        cout << "Enter a string" << endl;
        cin >> newStr;
        getString(newStr);
        cout << "Would you like to enter a string? (y/n): \n";
        cin >> vl;
        while (vl == 'y' || vl == 'Y')
        { // looping through if it finds a y
            cout << "Would you like to enter a string? (y/n): \n";
            cin >> vl;
            cout << "Enter a string" << endl;
            if (vl == 'n')
            {
                exit(1);
            }
            cin >> newStr;
            getString(newStr);
        }
    }
}
