/**************************
Program to find the length of strings 
    that start with 'D'
Written by Michael Giardina
    adapted from handout in class
March 4, 2022
Language: C++ (g++ target)
***************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

int main(void)
{
    string inputFile;
    string s;
    ifstream fileIn;
    int words = 0;
    int i = 0;
    int totalA [10] = {0};
    
    
    //Gets the file the user wants to open
    cout << "Enter the name of the file you want to check: ";
    cin >> inputFile;

    //Opens the file the user wants to open
    fileIn.open(inputFile.data());

    //Checks if the file was opened properly
    assert(fileIn.is_open());
    
    //Checks for words that start with 'D'
    //  and stores them in the corresponding length
    //  location in the array
    while (fileIn >> s)
    {
        words++;
        if(s[0] == 'D' || s[0] == 'd')
        {
        totalA[s.length()]++;        
        }
    }

    //Tells the user how many words start with 'D'
    //  and their length
    cout << "In the file provided there are:" << endl;
    cout << words << " words" << endl;

    for (i = 1; i <= 10; i++)
    {
        if(totalA[i] != 0)
        {
            if(totalA[i] == 1)
            {
                cout << "There is also ";
                cout << totalA[i] << " word starting with 'D' or 'd' that have ";
            }
            else if (totalA[i] > 1 || totalA[i] == 0)
            {
                cout << "There are also ";
                cout << totalA[i] << " words starting with 'D' or 'd' that have ";
            }

            if(i == 1)
            {
                cout << i << " letter" << endl;
            }
            else if (i > 1 || i == 0)
            {
                cout << i << " letters" << endl;
            }
        }
    }

    //Close the file
    fileIn.close();

    //Terminate
    return 0;
}