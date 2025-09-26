#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands_counter = 0;
        // nothing in it 
        if(grid.empty()) {
            return 0;
        }
        else {
            int r= grid.size();
            int c= grid[0].size();
            for(int row =0; row < r; row++) {
                for(int col = 0; col < c; col++){
                    if (grid[row][col] == '1') {
                        islands_counter = islands_counter+1;
                    
                        // bfs approach
                        queue<pair<int, int>> q;
                        q.push({row, col});
                        grid[row][col] ='0';
                        while(!q.empty()){
                            pair<int, int> on = q.front();
                            q.pop();
                            int onrow = on.first;
                            int oncol = on.second;
                            check(onrow -1, oncol, grid, r, c, q);
                            check(onrow +1, oncol, grid, r, c, q);
                            check(onrow, oncol-1, grid, r, c, q);
                            check(onrow, oncol+1, grid, r, c, q);
                        }
                    }
                }
            }
        }
        return islands_counter;
    }

    void check(int row, int col, vector<vector<char>>&grid, int r, int c, queue<pair<int,int>>& q){
        if (row >=0 && row < r && col>=0 && col < c && grid[row][col] == '1') {
            grid[row][col] ='0';
            q.push({row, col});
        }
    }
};