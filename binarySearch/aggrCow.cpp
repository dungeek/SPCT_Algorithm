/*
https://www.spoj.com/problems/AGGRCOW/
Farmer John has built a new long barn, with N (2 ≤ N ≤ 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 ≤ xi ≤ 1,000,000,000).

His C (2 ≤ C ≤ N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input
t – the number of test cases, then t test cases follows.

Line 1: Two space-separated integers: N and C
Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Input
t – the number of test cases, then t test cases follows.

Line 1: Two space-separated integers: N and C
Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.

Example
Input:
1
5 3
1
2
8
4
9

Output:
3
*/

#include <bits/stdc++.h>
using namespace std;

bool checkArrangeCowsEnough(const vector<int>& positionStalls, int numCows, int distance) {
    int countPLaced = 1; // Always put first cow
    int lastPosition = positionStalls[0];

    for (int i = 1; i < positionStalls.size(); i++){
        if((positionStalls[i] - lastPosition) >= distance ){ // if the distance is enough
            countPLaced++; // place a cow between two position
            lastPosition = positionStalls[i];
            if(countPLaced == numCows) 
            return true;
        }
    }
    return false;
}

void solve(){
    int numStalls, numCows; cin >> numStalls; cin >> numCows;
    vector<int> positionStalls(numStalls);

    for (int i = 0; i < numStalls; i++)
    {
        cin >> positionStalls[i];
    }
    sort(positionStalls.begin(), positionStalls.end());

    int l = 0; 
    int r = positionStalls.back() - positionStalls.front();

    int maxDistance = 0;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if(checkArrangeCowsEnough(positionStalls, numCows, m)){
            maxDistance = max(maxDistance, m);
            l = m + 1;  // Try bigger distance
        }else{
            r = m - 1;  //Try smaller distance
        }
    }
    
    cout << maxDistance << endl;
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}