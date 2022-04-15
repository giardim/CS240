#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Hash
{
public:
    Hash()
        : hashVector(15, "?")
        {}

    void display()
    {
        for (place = hashVector.begin(); place != hashVector.end(); place++)
        {
            cout << *place << " ";
        }
        cout << endl;
        return;
    }

    void fill(string word)
    {
        element = (word[0] + word [1] - word[word.size() - 1]) % 15;
        place = hashVector.begin() + element; 
        if (*place == "?")
        {
            hashVector[element] = word;
        }
        else 
        {
            while (*place != "?")
            {place++;
                if(place == hashVector.end())
                {
                    place = hashVector.begin();
                }
            }
            place = hashVector.erase(place);
            place = hashVector.insert(place, word);
        }
        return;
    }

    int search(string target)
    {
        int outcome = -1;

        element = (target[0] + target [1] - target[target.size() - 1]) % 15;
        place = hashVector.begin() + element;
        
        do
        {
            if (target == *place)
            {
                outcome = 1;
            }
            else 
            {
                place++;
                if(place == hashVector.end())
                {
                    place = hashVector.begin();
                }
            }
        }while((*place != "?") && (outcome == -1));


        return outcome;
    }

private:
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

    cout << "Please enter ten words: " << endl;
    for (i = 0; i < 10 ; i++)
    {
        cin >> word;
        hash.fill(word);
    }

    hash.display();

    do
    {
        cout << "What word would you like to find in the list?: ";
        cin >> target;
        outcome = hash.search(target);
        
        if (outcome == 1)
        {
            cout << "The word was found in the list" << endl;
        } 
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

/*(1) defines and implements a hash class that constructs a 15 element array (may be implemented using a vector, a deque, or a list, if you prefer, (using the STL implementations, not Nyhoff's), storing strings, using the following hash function:
((first_letter) + (second_letter) - (last_letter))% 15


So, for example, the word "rocky" would be
('r') = 114 + ('o') = 111 - ('y') = 121 = 104%15 = 14


In this example, an attempt would be made to store "rocky" in position 14. In the event of a collision, the word would be stored in the first available location, so if there is a collision in location 14, an attempt would be made to store the word in location 15, but the next location after location 14 is to circle back to location 0 because there is no location 15.  If there is a collision in location 0, try location 1, and so on.
I will not try your program with words that are shorter than three letters, so you do not need to consider shorter words.
(2) the driver program should:
a. query the user for ten words and store them using the hash technique described above.
b. print out the contents of each position of the array (or vector, deque, or whatever you used), showing vacant as well as filled positions. Remember, only 10 of the 15 positions will be filled.
c. repeatedly query the user for a target word, hash the word, check for its inclusion in the list of stored words, and report the result. Continue doing this task until the user signals to stop (establish a sentinel condition).*/