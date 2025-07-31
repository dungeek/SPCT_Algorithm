#include <bits/stdc++.h>
using namespace std;

/*
1 switch connects to a list of light

swtich turn on => 


minimum number of switchs

input
number of lights
the number of switches

next line, the i-th switch:

k number of light affected by switch
next k the indices of the lights that this switch toggles.

3 3
2 1 2
2 2 3
1 3
*/
struct Switch{
    int affectLight;
    vector<int> lightIndices;
};

void solve () {
    int numLight; cin >> numLight;
    int numSwitch; cin >> numSwitch;

    vector<Switch> switches;
    for (int i = 0; i < numSwitch; i++)
    {
        int affectLight;
        cin >> affectLight;
        Switch aSwitch;
        for (int j = 0; j < affectLight; j++)
        {
            int indice; cin >> indice;
            aSwitch.lightIndices.push_back(indice);
        }
        switches.push_back(aSwitch);
    }
    
    //Togles 
    int countLight;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
