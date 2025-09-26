#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows ==0) {
            return 0;
        }
        int column = grid[0].size();
        queue<pair<int, int>>q;
        int fresh =0;
        for (int row = 0; row < rows; row++){
            for(int c = 0; c< column; c++ ){
                if (grid[row][c] == 2) {
                    q.push({row, c});
                }
                else if (grid[row][c]==1){
                    fresh = fresh +1;
                }
            }
        }
        if (fresh == 0) {
            // return nothing
            return 0;
        }
        int mins = 0;
        while(!q.empty() && fresh > 0){
            int size = q.size();
            for (int i = 0; i < size; i++){
                pair<int, int> on = q.front();
                q.pop();
                int ro = on.first;
                int co = on.second;
                rotten(ro-1, co, grid, rows, column, q, fresh);
                rotten(ro+1, co, grid, rows, column, q, fresh);
                rotten(ro, co-1, grid, rows, column, q, fresh);
                rotten(ro, co+1, grid, rows, column, q, fresh);
            }
            mins++;
        }
        if (fresh == 0) {
            return mins;
        }
        else {
            return -1;
        }
    }
    void rotten(int row, int col, vector<vector<int>>& grid, int r, int c, queue<pair<int, int>>&q, int & fresh) {
        if (row >= 0 && row < r && col >= 0 && col < c && grid[row][col]==1){
            grid[row][col] =2;
            fresh--;
            q.push({row, col});
        }
    }
};