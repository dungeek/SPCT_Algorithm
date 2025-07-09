/*
https://leetcode.com/problems/longest-harmonious-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findLHS(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int maxlength = 0;
    
            for (int i = 0; i < nums.size(); i++) {
                int count = 0;
                bool found = false;
    
                for (int j = i; j < nums.size(); j++) {
                    if (nums[j] == nums[i]) {
                        count++;
                    } else if (nums[j] == nums[i] + 1) {
                        count++;
                        found = true;
                    } else if (nums[j] > nums[i] + 1) {
                        break; // No longer part of a valid subsequence
                    }
                }
    
                if (found) {
                    maxlength = max(maxlength, count);
                }
            }
    
            return maxlength;
        }
};