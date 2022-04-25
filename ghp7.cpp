/**************************
Program take a string from the user,
    hash it and store the string in a vector
    at the hashed index. Then it will display 
    the vector and allow the user to input a string
    to check if the string is in the vector.
Written by Michael Giardina
April 29, 2022
Language: C++ (g++ target)
***************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Hash
{
public:
    /**************************
    Construction function for the hash class.
    Written by Michael Giardina
    April 29, 2022
    Language: C++ (g++ target)
    ***************************/
    Hash()
        : hashVector(15, "?")
        {}

    void display()
    {
    /**************************
    Method used to display the vector
    Written by Michael Giardina
    April 29, 2022
    Language: C++ (g++ target)
    ***************************/
        for (place = hashVector.begin(); place != hashVector.end(); place++)
        {
            //Check the current value of the vector
            if(*place == "?")
            {
                //if the value is '?' write "empty"
                cout << "EMPTY" << " ";
            }
            else
            {
                //if the value is not '?' write the value
                cout << *place << " ";
            }
        }
        cout << endl;
        return;
    }

    void fill(string word)
    {
    /**************************
    Method used to take the word the user
        input, hash it, and place it in the 
        vector.
    Written by Michael Giardina
    April 29, 2022
    Language: C++ (g++ target)
    ***************************/
        //Hash the word the user inputs
        element = (word[0] + word [1] - word[word.size() - 1]) % 15;
        
        //Assign the iterator to the beginning of the vector
        // plus the hashed value
        place = hashVector.begin() + element; 
        
        //Check the current value of the vector
        if (*place == "?")
        {
            //If the value is '?', assign the word to the vector
            // at the element index
            hashVector[element] = word;
        }
        else 
        {
            //check the current value of the vector
            while (*place != "?")
            {   
                //While the value of the vector is not '?'
                // increment the iterator
                place++;
            
                //Check if the iterator is the end of the vector
                if(place == hashVector.end())
                {   
                    //If the iterator is past the end of the vector
                    // Make the iterator equal to the beginning of the vector
                    place = hashVector.begin();
                }
            }

            //Erase the value at current iterator and replace it with the 
            // New word
            place = hashVector.erase(place);
            place = hashVector.insert(place, word);
        }
        return;
    }

    int search(string target)
    {
    /**************************
    Method used to search for the string
        the user input
    Written by Michael Giardina
    April 29, 2022
    Language: C++ (g++ target)
    ***************************/
        int outcome = -1;

        //Hash the target word input
        element = (target[0] + target [1] - target[target.size() - 1]) % 15;
       
        //Assign the iterator to the beginning of the vector
        // plus the hashed value
        place = hashVector.begin() + element;
        
        do
        {   
            //Check if the target word is equal to the current 
            //  value of the vector
            if (target == *place)
            {
                //If it is, assign 1 to outcome
                outcome = 1;
            }
            else 
            {
                //Increment iterator
                place++;

                //Check if the iterator is the end of the vector
                if(place == hashVector.end())
                {
                    //If the iterator is past the end of the vector
                    // Make the iterator equal to the beginning of the vector
                    place = hashVector.begin();
                }
            }
        //Check if the current value at the vector is '?' and 
        // the value of outcome
        } while((*place != "?") && (outcome == -1));

        return outcome;
    }

private:
    /**************************
    Values to be used inside the class.
    Written by Michael Giardina
    April 29, 2022
    Language: C++ (g++ target)
    ***************************/
    vector<string> hashVector;
    vector<string>::iterator place;
    int element = 0; 
    
};

int main(void)
{
    Hash hash;
    int i  = 0, outcome = 0;
    char input = 'Y';
    string word, target;

    //Ask the user for 10 words
    cout << "Please enter ten words: " << endl;
    for (i = 0; i < 10 ; i++)
    {
        cin >> word;
        hash.fill(word);
    }

    //Display the vector
    hash.display();

    do
    {
        //Ask what word the user wants to find in the list
        cout << "What word would you like to find in the list?: ";
        cin >> target;
        outcome = hash.search(target);
        
        //If the word was found, tell the user
        if (outcome == 1)
        {
            cout << "The word was found in the list" << endl;
        } 
        //If the word was not found, tell the user
        else
        {
            cout << "The word was not found in the list" << endl;
        }

        cout << "Would you like to find another word(Y/N)? ";
        cin >> input;
        input = toupper(input);

    }while(input == 'Y');
    return 0;
}