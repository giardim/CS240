/*************************
Program to check if an expression
    has balanced parenthesis
Written by Michael Giardina
    Use of stack class adapted from Nyhoff
March 25, 2022
Language: C++ (g++ target)
************************/

#include <iostream>
#include <string>

using namespace std;

#include "Stack.h"

int main(void)
{
    string expression;
    Stack input;
    int i = 0, left = 0, right = 0;

    //Query the user for an arithmetic expression
    cout << "Please enter an arithmetic expression: ";
    //Store it in a string
    cin >> expression;
    
    //Put the string in the stack
    for (i = 0; i < expression.length(); i++)
    {
        input.push(expression[i]);
    }

    //While the stack is not empty, check the top of the stack
    while (!input.empty())
    {   
        //If the top of the stack is '('
        //Add one to the left variable
        if (input.top() == '(')
        {
            left++;
        }
        //If the top of the stack is ')'
        //Add one to the right variable
        else if (input.top() == ')')
        {
            right++;
        }
        //Decrease the stack by one
        input.pop();
    }

    //Check if the number of parenthesis are balanced
    if (right == left)
    {
        cout << "The expression has balanced parenthesis." << endl;
    }
    else 
    {
        cout << "The expression does not have balanced parenthesis." << endl;
    }

    //Terminate
    return 0;
}