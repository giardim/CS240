/************************
Program to fill two static arrays to the 
    size the user wants, then adding the
    elements at the same index and
    putting them in a third array
Written by Michael Giardina
Feb. 8th, 2022
Language: C++ (g++ target)
************************/

#include <iostream>

using namespace std;

int main (void)
{
    double arrayA[10][10] = {0};
    double arrayB[10][10] = {0};
    double arrayC[10][10] = {0};
    unsigned int rowA =0;
    unsigned int colA = 0;
    unsigned int rowB = 0;
    unsigned int colB = 0;
    unsigned int biggerR = 0;
    unsigned int biggerC = 0;
    int i = 0;
    int j = 0;

   

   
    //Gets the rows and col for array A
    cout << "How many rows would you like in the first array" << endl;
    cout << " (Values 0-10 only): ";
    cin >> rowA;
    cout << "How many columns would you like in the first array"<< endl;
    cout << " (Values 0-10 only): ";
    cin >> colA;

    //Gets the rows and col for array B
    cout << "How many rows would you like in the second array"<< endl;
    cout << " (Values 0-10 onlyy): ";
    cin >> rowB;
    cout << "How many columns would you like in the second array"<< endl;
    cout << " (Values 0-10 only): ";
    cin >> colB;

    //Assigns the biggest number of rows to c
    if (rowA >= rowB)
    {
        biggerR = rowA;
    }
    else
    {
        biggerR = rowB;
    }

    //Assigns the biggest number of col to C
    if (colA >= colB)
    {
        biggerC = colA;
    }
    else
    {
        biggerC = colB;
    }

    //Fills array A
    cout << endl << "Please enter values to fill array A" << endl;
    for (i = 0; i < rowA; i++)
    {
        for(j = 0; j < colA; j++)
        {
            cout << "Please enter the value for row " << i << " column " << j << ": "; 
            cin >> arrayA[i][j];
        }
    }

    //Fills array B
    cout << endl << "Please enter values to fill array B" << endl;
    for (i = 0; i < rowB; i++)
    {
        for(j = 0; j < colB; j++)
        {
            cout << "Please enter the value for row " << i << " column " << j << ": "; 
            cin >> arrayB[i][j];
        }
    }

    //Computes the sum and puts it in array C
    for (i = 0; i < biggerR; i++)
    {
        for(j = 0; j < biggerC; j++)
        {
            arrayC[i][j] = arrayA[i][j] + arrayB[i][j];
        }
    }

    //Outputs array A
    cout << endl << "array A : ";
    for (i = 0; i < rowA; i++)
    { cout << endl;
        for(j = 0; j < colA; j++)
        {
            cout <<  arrayA[i][j] << " ";
        }
    }
    cout << endl;

    //Outputs array B
    cout << endl << "array B : ";
    for (i = 0; i < rowB; i++)
    {   cout << endl;
        for(j = 0; j < colB; j++)
        {
            cout << arrayB[i][j] << " ";
        }
    }
    cout << endl;

    //Outputs array C
    cout << endl << "array C : ";
    for (i = 0; i < biggerR; i++)
    {   cout << endl;
        for(j = 0; j < biggerC; j++)
        {
            cout << arrayC[i][j] << " ";
        }
    }

    cout << endl;

    //Terminate
    return 0;
}