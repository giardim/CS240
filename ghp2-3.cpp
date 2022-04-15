/************************
Program to create a magic square when given 
    an odd integer (3, 5 or 7)
Written by Michael Giardina
    procedure adapted from Larry Nyhoff
Feb 16th, 2022
Language: C++ (g++ target)
************************/
#include <iostream>

using namespace std;

int main(void)
{
    int magic[7][7] = {0};
    int size = 0;
    int middle = 0;
    int total = 0;
    int start = 2;
    int i = 0;
    int j = 0;
    int col = 0;
    int row = 0;

    //Ask for the size of the magic sqaure
    cout << "Enter an odd integer (3, 5 or 7): ";
    cin >> size;

    //Finds the middle of the magic square
    middle = (size / 2);
    //Makes the middle the starting column
    col = middle;
    //How many times the square will be checked
    total = (size * size) - 1;

    //makes the first row middle column equal 1
    magic[0][middle] = 1;

    while (total > 0)
    {
        row--;
        col++;

        //This makes it so if the row and col are
        //   are at the top right of the square
        //   the number will go under the previous number
        if((row < 0) && (col >= size))
        {
            row = row + 2;
            col = col - 1;
        }
        //Makes it so if the next column will go
        //  outside of the square, the column will 
        //  be set to 0
        else if (col >= size)
        {
            col = 0;
        }
        //Makes it so if the next row will go
        //  outside of the square, the row will be 
        //  the size of the square - 1
        else if (row < 0)
        {
            row = size - 1;
        }
        //Makes it so if the square is already
        //  occupied, the next number will go 
        //  under the previous number
        else if (magic[row][col] != 0)
        {
            row = row + 2;
            col = col - 1;
        }
        //Populates the square
        magic[row][col] = start;
        start++;
        total--;

    }

    //Prints out the square
    for (i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            cout << magic[i][j] << "\t";
        }
        cout << endl;
    }
    //Terminate
    return 0;
}