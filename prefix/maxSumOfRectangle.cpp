/*https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
*/

#include <bits/stdc++.h>
using namespace std;

//At each element in each row => loop for the rest to calculate prefixSum starting from that element
class Solution {
    public:
        int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
            
            int m = matrix.size(), n = matrix[0].size();
            int maxSum = INT_MIN;
            
            //Iterate all over possible stating columns (at l) at the first row
            for(int l = 0; l < n; l++) {
                //Prefix sum for each row of submatrix
                vector<int> sumArr(m, 0);

                //Iterate over all possible ending columns (r) starting from l
                for(int r = l; r < n; r++) {
                    
                    // Continuoudly update sumArr with cumulative sums from column l to r (Deepend on the loop ending column r)
                    for(int i = 0; i < m; i++) sumArr[i] += matrix[i][r];

                    /// For each submatrix with columns l to r, find the max subarray sum
                    for(int i = 0; i < m; i++) {
                        int sum = 0;
                        for(int j = i; j < m; j++) {
                             // Cumulative sum from row i to j
                            sum += sumArr[j];
                            if(sum > maxSum && sum <= k) maxSum = sum;
                        }
                    }
                }
            }
            return maxSum;
        }
    };