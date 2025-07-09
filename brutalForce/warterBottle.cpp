#include <bits/stdc++.h>
using namespace std;

void solve(){
    int initalBottle, bringedBottle;
    cin >> initalBottle; cin >> bringedBottle;

    int temp = bringedBottle;
    for (int i = 1; i < 1000; i++)
    {
        temp *= 2;

        if(temp >= initalBottle ) break;
    }

    cout << temp - initalBottle;
    
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}