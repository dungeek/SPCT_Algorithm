/*
https://www.hackerrank.com/contests/spct2025batch-2-pretest-5/challenges/rearrange-the-cargo
Input Format

The first line contains two integers:  and , representing the number of rows and columns of the grid.
The next  lines each contain a string of length , with characters from the set 

Constraints


Output Format

The  lines each contain a string of length , showing the grid after rotation and gravity adjustment.

Sample Input 0

1 3
.#.
Sample Output 0

.
.
#
Sample Input 1

3 5  
#...*  
.#*#.  
..#..  
Sample Output 1

...
.#.
.*.
..#
##*
*/

#include <bits/stdc++.h>
using namespace std;

void solve () {
    int row, column;
    cin >> row; cin >> column;

    vector<string> grid(row);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
        {
            cin >> grid[i][j];
        }
        cout << endl;
    }

    //Loop through each column within the current row
    for (int i = 0 ; i < row ; i++)
    {   
        vector<int> cargoIndexs;
        bool cargoExist = false;

        //Loop through each element in that row
        for (int j = 0; j < column; j++)
        {
            if(grid[i][j] == '#'){
                cargoIndexs.push_back(j);
                cargoExist = true;
                continue;
            }
            
            if(cargoExist){

                //If cargo falls on obstacle or bottom 
                if (grid[i][j] == '*' || j == column - 1)
                {
                    int countCargo = cargoIndexs.size();
                    while (countCargo > 0)
                    {
                        grid[i][j - countCargo] = '#';
                        countCargo--;
                    }
                    //Reset cargo count
                    cargoExist = false;
                }      
                
            }
        }
    }
    
     // Output the rearranged grid
    for (int i = 0; i < row; i++) {
        for (int j = column - 1 ; j >= 0 ; j--)
        {
            cout << grid[j][i];
        }
        cout << endl;
    }
    
    
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}