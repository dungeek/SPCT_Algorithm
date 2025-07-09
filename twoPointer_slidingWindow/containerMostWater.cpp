/*
https://leetcode.com/problems/container-with-most-water/description/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& heights) {
            int ptr1 = 0; 
            int ptr2 = heights.size() - 1;
            int maxArea = (ptr2 - ptr1) * min(heights[ptr1], heights[ptr2]);

            while (ptr1 < ptr2)
            {
                if(heights[ptr1] <= heights[ptr2]){
                    ptr1++;
                } else {
                    ptr2--;
                }

                maxArea = max(maxArea, (ptr2 - ptr1) * min(heights[ptr1], heights[ptr2]));
            }
            
            return maxArea;
        }
    };