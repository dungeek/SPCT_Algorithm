/*
A sequence x1, x2, ..., xn is Fibonacci-like if:

n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

// Approach:
// We will use a vector to store the indices of the elements in the Fibonacci-like sequence
Using prefix sums to calculate the sum of the last two elements in the Fibonacci-like sequence
Binary search on the prefix sums to find the next element in the sequence

Binary Search on Length: Use binary search to determine the maximum possible length L of a Fibonacci-like subsequence.
Memoization: Use a map to store intermediate results to avoid redundant checks.
Helper Function: Implement a helper function to check if a subsequence of a given length L exists.
*/

#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <unordered_map>

// check if there exists a Fibonacci-like subsequence of length `L`
bool isFibonacciSubsequece(const vector<int>& arr, int L) {


    for ( int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); ++j) {
            int first = arr[i], second = arr[j];
            int third = first + second;
            
            
        }
    }
    
}

//Search for the longest Fibonacci subsequence length 
int binarySearch(const vector<int>& arr, int l, int r) {
    int bestLength = 0;
    
    while (l <= r) {
        int m = l + (r - l) / 2;
        if(isFibonacciSubsequece(arr, m)){
            bestLength = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return bestLength;
}

int main () {
    //Input
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;   
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Start searching for length 3 to n
    cout << "Length of the longest Fibonacci subsequence: " << binarySearch(arr, 3, n) << endl; 

    return 0;
}