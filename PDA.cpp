/*
Project 2 for CS 341
Section number:005
Semester: Fall 2022
Written by: Ishita Bhatt UCID: ijb4
Instructor: Marvin Nakayama, marvin@njit.edu
*/
#include <stack>
#include <iostream>
using namespace std;

void getString(string &str)
{
    stack<char> stack; // stack to store characters
    int states = 0;    // all the states
    // these are all the operators
    char a = '+';
    char s = '-';
    char m = '*';
    char d = '/';

    for (int i = 0; i < str.size(); i++)
    {

        switch (states)
        {
            // this is the start state here we check if first char is %  and if it is we read the first character pop nothing and push % onto stack
            // if the first character is not % then throw error and it crashes our pda
        case 0:
            if (str[i] == '%')
            {
                stack.push('%');
                cout << "This is start state q" << states << "\n";
                cout << "Current state is:q" << states << " stack read " << str[i] << " "
                     << "pop :"
                     << " Eps "
                     << " push: " << stack.top() << "\n";
                states = 1;
            }
            else
            {
                cout << "Oops PDA crashed!"
                     << "\n";
                cout << "String Rejected"
                     << "\n";
                return;
            }

            break;
            // this is the case where we check if the character is ( then we loop through it and we pop nothing but we push x onto stack
            //  we also see if we read a number than we change the states to 2
            // and if we read . we change the state to 3
            // and if we read anything other than else that should crash our pda
        case 1:
            if (str[i] == '(')
            {
                stack.push('x');
                cout << "Current state is:q" << states << " stack read " << str[i] << " "
                     << "pop :"
                     << " Eps "
                     << " push: " << stack.top() << "\n";
                states = 1;
            }
            else if (isdigit(str[i]))
            {
                cout << "Current state is:q" << states << " stack read " << str[i] << " "
                     << "pop :"
                     << " Eps "
                     << " push: "
                     << " Eps "
                     << "\n";
                states = 2;
            }
            else if (str[i] == '.')
            {
                cout << "Current state is:q" << states << " stack read " << str[i] << " "
                     << "pop :"
                     << " Eps "
                     << " push: "
                     << " Eps "
                     << "\n";
                states = 3;
            }
            else
            {
                cout << "Oops PDA crashed!"
                     << "\n";
                cout << "String Rejected"
                     << "\n";
                return;
            }

            break;
            // here this is the case where we check if we have a dot after our digit that we found in state 1 and if we have a dot we change the state to 4
            // and we also loop through numbers if we have numbers after numbers we read them here we push and pop nothing onto stack
            // if we read anything other than that we throw error because it crashes our pda
        case 2:
            if (isdigit(str[i]))
            {
                cout << "Current state is:q" << states << " stack read " << str[i] << " "
                     << "pop :"
                     << " Eps "
                     << " push:"
                     << " Eps "
                     << "\n";
                states = 2;
            }
            else if (str[i] == '.')
            {
                cout << "Current state is:q" << states << " stack read " << str[i] << " "
                     << "pop :"
                     << " Eps "
                     << " push:"
                     << " Eps "
                     << "\n";
                states = 4;
            }
            else
            {
                cout << "Oops PDA crashed!"
                     << "\n";
                cout << "String Rejected"
                     << "\n";
                return;
            }

            break;
            // if we have digits after . we read them here and push and pop nothing onto stack
            // else our pda crashes and stops right there

        case 3:
            if (isdigit(str[i]))
            {
                cout << "Current state is:q" << states << " stack read " << str[i] << " "
                     << "pop :"
                     << " Eps "
                     << " push: "
                     << " Eps "
                     << "\n";
                states = 4;
            }
            else
            {
                cout << "Oops PDA crashed!"
                     << "\n";
                cout << "String Rejected"
                     << "\n";
                return;
            }
            break;
            // this is the case where if we read any of the operators then we change the states to 1 and we push and pop nothing onto stack
            //  here if we read more digits after . digit then we loop through them and read all of them and pop and push nothing onto stack
            // if we read ) then we check if our stack top is x and if it is x we pop the stack and we go to state 5
            //  here if we read a % straight after a digit we go to state 6 and we check if our stack top is % then we pop the stack and push nothing onto stack
            // if we have anything else than that we throw error and that crashes our pda and it stops then and there
        case 4:
            if (str[i] == a || str[i] == s || str[i] == m || str[i] == d)
            {
                cout << "Current state is:q" << states << " stack read " << str[i] << " "
                     << "pop :"
                     << " Eps "
                     << " push: "
                     << " Eps "
                     << "\n";
                states = 1;
                break;
            }
            if (isdigit(str[i]))
            {
                cout << "Current state is:q" << states << " stack read " << str[i] << " "
                     << "pop :"
                     << " Eps "
                     << " push: "
                     << " Eps "
                     << "\n";
                states = 4;
                break;
            }
            if (str[i] == ')')
            {

                cout << "Current state is:q" << states << " stack read " << str[i] << " "
                     << "pop :" << stack.top() << " push: "
                     << " Eps "
                     << "\n";
                if (stack.top() == 'x')
                {
                    stack.pop();
                    states = 5;
                }
                else
                {
                    cout << "Oops PDA crashed!"
                         << "\n";
                    cout << "String Rejected"
                         << "\n";
                    return;
                }
                break;
            }
            if (str[i] == '%')
            {

                cout << "Current state is:q" << states << " stack read " << str[i] << " "
                     << "pop :" << stack.top() << " push: "
                     << " Eps "
                     << "\n";

                if (stack.top() == '%')
                {

                    states = 6;
                    stack.pop();
                }
                else
                {
                    cout << "Oops PDA crashed!"
                         << "\n";
                    cout << "String Rejected"
                         << "\n";
                    return;
                }
            }
            else
            {
                cout << "Oops PDA crashed!"
                     << "\n";
                cout << "String Rejected"
                     << "\n";
                return;
            }

            // this is the case where we see if we have more ) we loop through them and if we read ) then we check if our stack top is x and if it is x we pop the stack and we stay in state 5
            // if we read a % then we check if stack top is % and if it is we pop the stack and go to state 6 and we push nothing onto stack
            // here if we find any operators we go to state 1 we push and pop nothing onto stack we do this because we want to make sure that if we find any operator after ) character then we should be able to handle that clause
            // if there is anything other than that we throw error because it crashes our pda
        case 5:
            if (states == 5)
            {
                if (str[i] == ')')
                {

                    cout << "Current state is:q" << states << " stack read " << str[i] << " "
                         << "pop :" << stack.top() << " push: "
                         << " Eps "
                         << "\n";
                    if (stack.top() == 'x')
                    {
                        stack.pop();
                        states = 5;
                        break;
                    }
                    else
                    {
                        cout << "Oops PDA crashed!"
                             << "\n";
                        cout << "String Rejected"
                             << "\n";
                        return;
                    }
                }

                if (str[i] == '%')
                {

                    cout << "Current state is:q" << states << " stack read " << str[i] << " "
                         << "pop : " << stack.top() << " push: "
                         << " Eps "
                         << "\n";
                    if (stack.top() == '%')
                    {
                        states = 6;
                        stack.pop();
                    }
                    else
                    {
                        cout << "Oops PDA crashed!"
                             << "\n";
                        cout << "String Rejected"
                             << "\n";
                        return;
                    }
                }
                else if (str[i] == a || str[i] == s || str[i] == m || str[i] == d)
                {
                    cout << "Current state is:q" << states << " stack read " << str[i] << " "
                         << "pop : "
                         << " Eps "
                         << " push: "
                         << " Eps "
                         << "\n";
                    states = 1;
                }
                else
                {
                    cout << "Oops PDA crashed!"
                         << "\n";
                    cout << "String Rejected"
                         << "\n";
                    return;
                }
            }

        // this is the accepting state if our stack is empty then our string is accepted
        case 6:
            if (str[i] == '%')
            {
                cout << "Current state is:q" << states << " stack read " << str[i] << " "
                     << "pop :" << str[i] << " push: "
                     << " Eps "
                     << "\n";
                if (stack.empty())
                {

                    cout << "string is accepted"
                         << "\n";
                    break;
                }
            }
            break;
        }
    }
}
int main()
{
    cout << "Project 2 for CS 341 \n";
    cout << "Section number:005 \n";
    cout << "Semester: Fall 2022\n";
    cout << "Written by: Ishita Bhatt UCID: ijb4 \n";
    cout << "Instructor: Marvin Nakayama, marvin@njit.edu\n";

    char i;        // gets char n or y
    string newStr; // stores the string in it
    cout << "\nDo you want to enter a string? (y/n): \n " << endl;
    cin >> i; // gets input from user
    if (i == 'n' || i == 'N')
    {
        printf("You choose no!");
        exit(1);
    }
    else if (i == 'y' || i == 'Y')
    {
        cout << "Enter a string" << endl;
        cin >> newStr;
        getString(newStr);

        while (i == 'y' || i == 'Y')
        { // looping through if it finds a y
            cout << "Do you want to enter a string? (y/n): \n";
            cin >> i;
            if (i == 'n' || i == 'N')
            {
                printf("You choose no!");
                exit(1);
            }
            cout << "Enter a string" << endl;

            cin >> newStr;
            getString(newStr);
        }
    }
}
