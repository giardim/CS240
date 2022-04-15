
/**************************
Program to count the number of Dooflingies
    produced in a 10 day period, returning the 
    highest number produced, lowest number produced,
    average number produced, partial sum and adjacent 
    difference.
Written by Michael Giardina
April 22, 2022
Language: C++ (g++ target)
***************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define DAYS 10

int main (void)
{
    vector<int> dooflingies;
    vector<int> partSum(DAYS);
    vector<int> adjDiff(DAYS);
    int i = 0, produced = 0;
    int small, large, sum, average, difference;

    for (i = 0; i < DAYS; i++)
    {
        cout << "How many dooflingies did you produce on day " << i + 1 << ": ";
        cin >> produced;
        dooflingies.push_back(produced); 
    }

    cout << endl;

    //1. the lowest, the highest, and the average of the values read in.
    cout << "In the ten days, the lowest number of dooflingies you produced was: ";
    small = *min_element(dooflingies.begin(),dooflingies.end());
    cout << small << endl;

    cout << "In the ten days, the highest number of dooflingies you produced was: ";
    large = *max_element(dooflingies.begin(),dooflingies.end());
    cout << large << endl;

    cout << "In the ten days, the average number of dooflingies you produced was: ";
    sum = accumulate(dooflingies.begin(), dooflingies.end(), 0);
    average = sum / DAYS;
    cout << average << endl;


    //2. a sequence that shows how the number of dooflingies produced changed from day to day.
    cout << endl;
    adjacent_difference(dooflingies.begin(), dooflingies.end(), adjDiff.begin());
    for (i = 0; i < DAYS; i++)
    {
        
        cout << "From day " << i  << " to " << i + 1  << " the difference is dooflingies produced is: ";
        cout << adjDiff[i] << endl;
    }


    //3. a sequence that shows the number of dooflingies produced up to and including that day (so if there were 5 values 1,2,3,4,5  the calculated result would be 1,3,6,10,15).
    cout << endl;
    partial_sum(dooflingies.begin(), dooflingies.end(), partSum.begin());
    for (i = 0; i < DAYS; i++)
    {
        
        cout << "On day " << i + 1 << " the total number of dooflingies produced is: ";
        cout << partSum[i] << endl;
    }

    return 0;
}