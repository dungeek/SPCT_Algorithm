/*
Given an array A of N integers, a pair (i, j : i < j) is called valid if each index k (i <= k <= j) satisfies at least one of below conditions:

- If the value at index k is equal to the value at index i, then all indices from i to k have the same value.

- If the value at index k is equal to the value at index j, then all indices from k to j have the same value.

- If the value at index k is different from both the value at index i and index j, then the value at index k has to be less than both value at index i and index j.
Find total number of valid pairs.

Input Format

The first line gives total number of integers N

The second line gives N integers A[i]

Output: print single integer that is total number of valid pairs

Constraints

1 <= N <= 100000

0 <= A[i] <= 1000000000

index from 0 to N - 1
*/

#include <bits/stdc++.h>
using namespace std;
#include <algorithm>

void solve(){

    int total; cin >> total;
    vector<int> nums(total);
    for(int i = 0; i < total; i++){
        cin >> nums[i];
    } 

    int validPairs = 0;
    //Status to be saved
    //Count all next-to pair : total - 1
    //Loop though to check the condition 3

    for (int i = 0; i < total - 1; i++)
    {
        for(int j = i + 1; j < total; j++){
            bool isValid = true;
            bool isValid1 = true;
            bool isValid2 = true;
            bool isValid3 = true;
            
            //Check all k between i and j
            for (int k = i; k <= j; k++)
            {
                //Encounter the same indice
                //Check though all wrong conditions
                if (nums[i] = nums[k]) //Condition 1: all indices from i to k have the same value
                {
                    for (int x = i; x <= k; x++)
                    {
                        if (nums[x] != nums[k]) {
                            isValid1 = false;
                            break;
                        }
                    }
                } else if (nums[j] = nums[k]) //Condition 2: all indices from k to j have the same value
                {
                    for (int x = k; x < j; x++)
                    {
                        if (nums[x] != nums[k]){
                            isValid2 = false;
                            break;
                        }
                    }
                } else //Condition 3: the value at index k has to be less than both value at index i and index j. 
                {
                    if (nums[k] >= nums[i] || nums[k] >= nums[j]){
                        isValid3 = false;
                        break;
                    }
                }

                //If there is a k doesn't satisfied any condition, then stop checking that pair i j
                if(isValid1 == false && isValid2 == false && isValid3 == false) {
                    isValid = true;
                    break;
                }
            }

            //Find a valid pair
            if(isValid) validPairs++;
        }
    }
    cout << validPairs;
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}