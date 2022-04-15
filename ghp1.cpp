/************************
Program to find and pass back an integer found in a 
    4x4 matrix
Written by Michael Giardina
January 24th, 2022
Language: C++ (g++ target)
************************/



#include <iostream>


using namespace std;

//Bool function prototype
bool look(int [][4], int, int &, int &);

int main (void)
{
    //Fill a static array
    int matrix [4][4] = {2, 3, 5, 7,
                            11, 13, 17, 19,
                            23, 29, 31, 37,
                            41, 43, 47, 53};    
    int i = 0;
    int j = 0;
    int num = 0;
    bool outcome = NULL;

    //Print out the array
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << matrix[i][j] <<  " ";
        }
        cout << endl;
    }

    //Query the user for an integer
    cout << "Please enter an integer: ";
    cin >> num;

    //Pass the maxtrix and the number to a bool function
    outcome = look(matrix, num, i, j);

    //Display if the integer was found and if so, the first occurance
    if (outcome == true)
    {
        cout << "The integer was found at " << i << " " << j << "." << endl;
    }
    else if (outcome == false)
    {
        cout << "The integer was not found in the matrix." << endl;
    }


    return 0;
}


//Bool function def.
bool look (int matrix[][4], int num, int &k, int &l)
{
    /************************
    A program to find the first occurance of a number
        in a 4x4 matrix
    Written by Michael Giardina
    Loop Condition Written by Michael Giardina
        Adapted from Professor Ron Sarner
    January 24th, 2022
    Language: C++ (g++ target)
    ************************/

    bool outcome = false;
    int i = 0;
    int j = 0;

    //Look for the first and only first occurance
    while ((i < 4) && (!outcome))
    {
        if ((matrix[i][j] == num))
        {
            k = i;
            l = j;
            outcome = true;
        }
        j++;
        if (j == 4)
        {
            i++;
            j = 0;
        }
    }
    //Pass back the coordinates of the first occurance and
    //  If the integer is found
    return outcome;
}