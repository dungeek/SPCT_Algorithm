/*
You are given a positive integer N.

Your task is to decompose N into distinct positive integers such that no two chosen numbers are consecutive, and the number of elements is maximized.

Input Format

The first line contains single integer N

Constraints

1 <= N <= 10^18
Output Format

output single integer
Sample Input 0

1
Sample Output 0

1
Explanation 0

1 can only be decomposed to [1]

Sample Input 1

5
Sample Output 1

2
Explanation 1

5 can be decomposed into [1, 4]
*/

#include <bits/stdc++.h>
#
using namespace std;

int solve() {
     unsigned long long num; cin >> num;

//    unsigned long long l = 0, r = 1e9; 
//    while (l < r)
//     {
//         unsigned long long m = l + (r - l) / 2;
//         if(sqrt(r))
//     }
    return floor(sqrt(num));
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}