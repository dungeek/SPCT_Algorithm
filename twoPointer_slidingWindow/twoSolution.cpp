/*
https://www.acmicpc.net/problem/2470
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int num; cin >> num;
    vector<int> solutions(num);

    for (int i = 0; i < num; i++)
    {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end());

    int l = 0; int r = num - 1; 
    int value = 9999;

    int track_l = 0, track_r = num -1;
    while (l < r)
    {
        int currentSum = solutions[l] + solutions[r];
        if(abs(currentSum) < abs(value)){
            value = currentSum;
            track_l = l;
            track_r = r;
        }

        if (currentSum == 0)
        {
            cout << solutions[track_r] << " " << solutions[track_l];
        } else if (currentSum > 0)
        {
            r--;
        } else
        {
            l++;
        }
        
    }
    cout << solutions[track_l] << " " << solutions[track_r];
    
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}