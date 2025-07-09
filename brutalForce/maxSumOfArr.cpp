/*
Input:
Given an integer array with length N (N <= 1e5)
Note that there will be negative elements
Output:
Return the maximum sum of a subarray

1st Approach:
    List all subarray then compute all of those' sum
    Time complexity:
    All subarray → O(N*N)
    Sum of each subarray → O(N)
    Overall: O(N*N*N) → O(1e15) → Fail
2nd Approach:
    List all subarray but we compute all the sum before (Prefix Sum)
    Time complexity:
    All subarray → O(N*N)
    Sum of each subarray → O(1)
    Overall: O(N*N*1) → O(1e10) → Fail
3rd Approach:
    We need to come up with a solution which require only O(N*logN) or O(N) 
    Kadane's Algorithm
    Theory:
    Basically, Kadane algorithm is iterating all elements within that array from index A[0] → A[n-1]
    But during the iteration, we need to save all the status from the previous step, then jump to the next step
    The status need to save will differ from each problems
    We will do an example on this one
Approach:
    In this problem, we need to find the subarray with the maximum sum → We will save status of 2 components
    Component 1: Maximum sum of subarray up until now
    Component 2: The current sum of the subarray we are processing
*/

#include <bits/stdc++.h>
using namespace std;
#include <algorithm>

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x; // input

    int maxSum = arr[0]; // Maximum sum of subarray up until now
    int currentSum = arr[0]; // The current sum of the subarray we are processing

    //Maximum subarray sum using Kadane's algorithm
    for(int i = 1; i < n; i++) {
        // Decide whether to start a new subarray or continue the existing one
        // If (currentSum < = 0) currentSum = 0;
        if(arr[i] > currentSum + arr[i]){
            currentSum = arr[i]; // Start a new subarray
        } else {
            currentSum += arr[i]; // Continue the existing subarray
        }

        maxSum = max(maxSum, currentSum); // Update the maximum sum if needed
    }

    cout << maxSum << endl; 
    return 0;
}
