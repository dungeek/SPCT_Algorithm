/*https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/
2389. Longest Subsequence With Limited Sum

You are given an integer array nums of length n, and an integer array queries of length m.

Return an array answer of length m where answer[i] is the maximum size of a subsequence 
that you can take from nums such that the sum of its elements is less than or equal to queries[i].

A subsequence is an array that can be derived from another array by 
deleting some or no elements without changing the order of the remaining elements.
*/

/*
Approach
Sort the nums array: The key observation is that selecting the smallest elements first 
will allow us to maximize the subsequence size while staying under a given query sum.
Use a prefix sum: Construct a prefix sum array, where prefix[i] represents the sum of the first i elements in the sorted array.
Binary search: For each query, use binary search (std::upper_bound) to find the largest subsequence whose sum is ≤ queries[i].
*/

#include <bits/stdc++.h>
using namespace std;
#include <algorithm>

int binarySearch(const vector<int>& prefixSums, int l, int r, int query) {
    while ( l <= r) {
        int m = l + (r - l) / 2;
        if(prefixSums[m] <= query){
            l = m + 1;
        }else{
            r = m - 1; 
        }
    }
    return l;
}

int main (){
    int n, m;
    cin >> n >> m; // Input size of nums and queries
    vector<int> nums(n), limitedSums(m), sizesOfSubsequences(m);

    // Input elements of nums and queries
    for(int i = 0; i < n; i++) {
        cin >> nums[i]; // Input elements of nums
    }

    for(int i = 0; i < m; i++) {
        cin >> limitedSums[i]; // Input elements of queries
    }

    // Sort the nums array
    sort(nums.begin(), nums.end());

    //Calculate prefix sums
    vector<int> prefixSums;
    int preSum = 0;
    for(int i = 0; i < n; i++) {
        preSum += nums[i]; 
        prefixSums.push_back(preSum); 
    }
    // prefixSums.push_back(nums[0]);
    // for(int i = 1; i < n; i++) {
    //     prefixSums.push_back(nums[i] + prefixSums[i-1]);
    // }

    //Process each query, use binary search on prefixSums to find the maximum size of subsequence
    for(int i = 0; i < n; i++) {
        sizesOfSubsequences.push_back(binarySearch(prefixSums, 0, prefixSums.size() -1 ,limitedSums[i]));
    }

    cout << "Sizes of subsequences: ";
    for(int i = 0; i < m; i++) {
        cout << sizesOfSubsequences[i] << " "; // Output the sizes of subsequences
    }

    return 0; 
}

