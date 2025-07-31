#include <bits/stdc++.h>
using namespace std;

struct Team {
    int id;
    int gold;
    int silver;
    int cooper;
};

void solve () {
    int numTeam; cin >> numTeam;
    int myTeamID; cin >> myTeamID;

    vector<Team> teams(numTeam);
    
    for (int i = 0; i < numTeam; i++) {
        int id, g, s, c;
        cin >> id >> g >> s >> c;

        //ID will be different from the index in the vector
        teams[i].id = id;
        teams[i].gold = g;
        teams[i].silver = s;
        teams[i].cooper = c;
    }

    // Find my team
    Team targetTeam;
    for (int i = 0; i < numTeam; i++) {
        if (teams[i].id == myTeamID) {
            targetTeam = teams[i];
            break;
        }
    }

    //Calculate rank  
    int tempRank = 1;
    int goldTeam = targetTeam.gold;
    int silverTeam = targetTeam.silver;
    int cooperTeam = targetTeam.cooper;
    for (int i = 0; i < numTeam; i++)
    {
        if (teams[i].id == myTeamID) continue;
        
        if (teams[i].gold > goldTeam || (teams[i].gold == goldTeam && teams[i].silver > silverTeam) || 
                    (teams[i].gold == goldTeam && teams[i].silver == silverTeam && teams[i].cooper > cooperTeam)) {
                        tempRank++;
        }
        
    }
    
    cout << tempRank;
    
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}

