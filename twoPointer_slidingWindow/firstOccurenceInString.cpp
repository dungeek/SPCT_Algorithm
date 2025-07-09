/*
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle) {
            
            int count = 0;
            for (int i = 0; i < haystack.size(); i++)
            {
                if(haystack[i] == needle[count]){
                    count++;
                } else {
                    // start from the next index of previous start index
                    i = i - count;
                    count = 0;
                }

                if(count == needle.size()){
                    // return the first index
                    return i - needle.size() + 1;
                }
            }
            return -1;
        }
};