#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Chain {
    int num;
    vector<int> modules;
    int sumEnergy;
};

int main() {
    int budget; cin >> budget;
    int numChain; cin >> numChain;

    vector<Chain> chains(numChain);
    for(int i = 0; i < numChain; i++){
        int num; cin >> num;
        chains[i].num = num;
        chains[i].modules.resize(num);
        int sumEnergy = 0;
        for(int j = 0; j < num; j++){
            int energy; cin >> energy;
            sumEnergy += energy;
            chains[i].modules[j] = energy;
        }
        chains[i].sumEnergy = sumEnergy;
    }

    // Active all chains with positive energy
    int final = budget;
    for(int i = 0; i < numChain; i++){
        if(chains[i].sumEnergy > 0){
            final += chains[i].sumEnergy;
        }
    }
    
    cout << final;
    return 0;
}