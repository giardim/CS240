/**************************
Program to check if the sentence entered
    by the user if a palindrome
Written by Michael Giardina
April 8, 2022
Language: C++ (g++ target)
***************************/

//Include the libraries needed for this program
#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main (void)
{
    string sentence;
    stack <char> s;
    queue <char> q;
    int i = 0;
    bool outcome = true;

    //Ask the user to enter a string
    cout << "Please enter a string to check if it is a palindrome: ";
    //Record the string
    cin >> sentence;

    for (i = 0; i < sentence.length(); i++)
    {
        //Make the string uppercase, this way even if 
        //  the user types using camelcase, the program
        //  will be able to tell if the word is a palindrome
        sentence[i] = toupper(sentence[i]);
    }

    for (i = 0; i < sentence.length(); i++)
    {
        //Add the string one character at a time to the stack
        s.push(sentence[i]);
        //Add the string one character at a time to the queue
        q.push(sentence[i]);
    }

     for (i = 0; i < sentence.length(); i++)
    {
        //Check if the top of the stack is the same as the 
        //  front of the queue
        if (s.top() != q.front())
        {
            outcome = false;
        }
        //Remove the top element
        s.pop();
        //Remove the element at the front
        q.pop();
    }

    //Check if the string is a palindrome
    if (outcome == true)
    {
        cout << "The string you entered is a palindrome." << endl;
    }
    else 
    {
        cout << "The string you entered is not a palindrome." << endl;
    }
    
    //Terminate
    return 0;
}