/*
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;
#include <algorithm>


int main () {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    //We will keep track of the farthest index we can reach, don't care about the actual path taken
    int farthest = 0; // farthest index we can reach
    for (int i = 0; i < n; i++) {
        if(farthest < i){
            cout << "false" << endl; // If we reach an index that is beyond our farthest reach, we cannot proceed
            return 0;
        }

        if(nums[i] + i > farthest){
            farthest = nums[i] + i; // Update the farthest index we can reach
        }
        
    }
    cout << "true" << endl; // reach the last index

    return 0;
    
}