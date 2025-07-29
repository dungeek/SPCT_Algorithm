/*
Given an array A of N integers (N <= 1e5), for each element A[i], find the first element to the right of A[i] that is greater than A[i]. If there is no such element, output -1.
Approach:
Brute Force:
Each element, we iterate from the next index to the end find the first greater element
Time complexity: O(N*N) = O(1e10) → FAIL
Monotonic Stack:
We will iterate from the right to left → Save all the elements in decreasing order
Then at each index we will get the top of the stack → Compare to the current index
If current index >= top of stack → A[i] = -1 (no element greater than this) → Push this to stack
If current index < top of stack → A[i] = stack.top() → Don't push this to stack
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    

}

int main () {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   solve();

   return 0;
}