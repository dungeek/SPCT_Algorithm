/*
https://www.hackerrank.com/contests/spct2025batch-2-pretest-3/challenges/strawberry-sunshade
*/

#include <bits/stdc++.h>
using namespace std;

void solve () {
    int gardenM, gardenN; cin >> gardenM; cin >> gardenN;
    vector<vector<int>> yield(gardenM, vector<int>(gardenN));
    for (int i = 0; i < gardenM; ++i) {
        for (int j = 0; j < gardenN; ++j) {
            cin >> yield[i][j];
        }
    }

    int tarpH, tarpW; cin >> tarpH; cin >> tarpW;

    //Preprocess 
    vector<vector<int>> prefix(gardenM, vector<int>(gardenN));
    for(int i = 1; i <= gardenM; i++){
        for (int j = 1; j < gardenN; j++)
        {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + yield[i][j];
        }
        
    }

    long long maxYeildCovered = 0;
    for (int i = tarpH; i < gardenM; i++)
    {
        for (int j = tarpW; j < gardenN; j++)
        {
            long long sumYeild = prefix[i][j] - prefix[i - tarpW][j] + prefix[i - tarpH][j - tarpW];
            maxYeildCovered = max(sumYeild, maxYeildCovered);
        }
        
    }
    
    cout << maxYeildCovered;
}


int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}