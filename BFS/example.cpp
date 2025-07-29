/*
Breadth-First Search (BFS) is a graph traversal algorithm that explores all neighbors of a node before moving on to the next level of neighbors. 
It uses a queue to keep track of nodes to visit next.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> dx{-1,1,0,0}, dy{0,0,-1,1};  //Represent movement in four directions: dx = {-1, 1, 0, 0} → up, down  dy = {0, 0, -1, 1} → left, right
vector<vector<int>> A; // Grid A: each cell can be  0: Unvisited  1: Visited

void bfs(int start_x , int start_y) {

    queue<pair<int, int>> q;
    q.push({start_x, start_y}); // Start BFS from (start_x, start_y)
    A[start_x][start_y] = 1; // Mark as visited

    while (!q.empty()){ //While there are cells to explore

        auto [x, y] = q.front(); q.pop(); //Get the current cell (x, y) from the front of the queue

        for (int i = 0; i < 4; ++i) { // Loop through all 4 directions
            
            int newx = x+dx[i], newy = y+dy[i];

            if (newx<0 || newx>=R|| newy<0 || newy>=C) continue; // ignore if next step is out of bounds
           
            if (A[newx][newy] == 0) { // If not visited
                // do something
                A[newx][newy] = 1; // Mark as visited
                q.push({newx, newy}); // Add to queue for further exploration
            }
        }
    }
}