/*Problem: 
Given N chairs (N <= 1e5) locate at specified position (0 → 1e9)
Given M people (M <= 1e5).
You need to arrange M people to N chairs. There will be lots of ways to do that. The score of each way will be defined as the distance between the 2 closest people.
   => Find the way which gives the maximum score => best maximum distance found.
Approach:
Firstly, sort the chairs position increasingly.
Then because the final answer has to be between (1 → 1e9)
Binary Search on the Maximum Score: We will use binary search to find the maximum possible minimum distance between any two seated people.
Lower Bound (low): The minimum possible distance is 1 (since people cannot occupy the same chair).
Upper Bound (high): The maximum possible distance is the difference between the first and last chair positions
   (i.e., chairs[N-1] - chairs[0]).

What is the difference comparing to type 1? - Type 1 will search on the Input Value and compare the middle with K. Type 2 will search on the Output Value and each loop we do the (bool check function) to check if the middle value is satisfied or not.
Take a look at the solution below. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Checks whether it's possible to seat M people on the given chairs such that the minimum distance between two closest seated people is dist.
bool check(const vector<int>& chairs, int M, int dist){

    int countPlaced  = 1; // First person is always placed
    int last_position = chairs[0]; // position of the last person seated

    // Iterate through the sorted chair positions starting from the second position
    for (int i = 1; i < chairs.size(); i++) {
         if (chairs[i] - last_position >= dist) { // if the distance is enough
            
            countPlaced ++; // place another person
             last_position = chairs[i]; // update last position

             if (countPlaced == M) return true; // if all M people are seated, return true
         }
    // if we reach here, it means we couldn't seat M people with at least 'dist' distance
    //There are persons who isn't seated
    }
    return false; // Could not place all people with the given min distance
}

int binarySearch(vector<int>& chairs, int l, int r, int M)
{
    int best = 0; // best max distance found
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(chairs, M, m)) // if found return immediately
        {
            best = max(best, m); // update best found distance
            l = m + 1; // search for a bigger distance
        }
        else{
            r = m - 1; // search for a smaller distance
        }  

    }
    return best; // not found M
}

int main () {
    int N, M; //  N chairs, M people
    cout << "Enter number of chairs and people: ";
    cin >> N >> M;

    cout << "Enter positions of chairs: ";
    vector<int> chairs(N);
    for (int i = 0; i < N; i++) {
        cin >> chairs[i];
    }
    
    sort(chairs.begin(), chairs.end()); // sort the chair positions
    
    // binary search with left = 0 and right = N-1 (M people)
    cout << "Chairs positions for maximun score: " << binarySearch(chairs, 0, 1e9, M) << endl;
    return 0;
}