/*
 His fence consists of N segments, each with a height of Ai. Cong also has a cart carrying M planks, each with a height of Bi
Determine the maximum possible overall height of the fence under these conditions.
First line N and M number of fence segment and number of planks

Second line N number array A height of fence

Third line M number array B height of plank

6 7
2 5 4 1 7 5
2 3 1 3 2 4 6
Sample Output 0

5
*/

#include <bits/stdc++.h>
using namespace std;

// Check if the fence can be adjusted to meet the required height by adding planks to segments that are shorter than the specified height.
bool check(vector<int> &segments, vector<int> &planks, int height)
{

    // Track the number of planks used and their indices to ensure the fence meets the required height
    int plankIndex = 0; // Start from the first/topmost plank in cart as stack

    // Start from the highest segment in fence
    for (int i = 0; i < segments.size(); i++)
    {
        if (segments[i] >= height)
        { // If the segment is already tall enough, no plank is needed
            continue;
        }

        // if a segment lower than the overall exsists, check if the segment have proper plank
        // Discard the small plank when we still have planks
        while ((plankIndex <= planks.size() - 1) && (segments[i] + planks[plankIndex] < height))
        {
            plankIndex++;
        }

        // In case, no plank is proper
        if (plankIndex >= planks.size())
        {
            return false;
        }

        // Use a plank to attach the segment
        plankIndex++; // Move to the next-to plank
    }

    return true;
}

void solve()
{
    int numSegs, numPlanks;
    cin >> numSegs;
    cin >> numPlanks;

    vector<int> segments(numSegs);
    vector<int> planks(numPlanks);

    for (int i = 0; i < numSegs; i++)
    {
        cin >> segments[i];
    }

    for (int i = 0; i < numPlanks; i++)
    {
        cin >> planks[i];
    }

    int l = 0;
    int r = 1e8;

    int maxPossibleHeight = 0;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (check(segments, planks, m))
        {
            maxPossibleHeight = max(maxPossibleHeight, m);
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << maxPossibleHeight << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int i;
    // cin >> i;

    // while (i--) solve();
    solve();
    return 0;
}