// Approach 1: DFS
// Time Complexity: O(M*N)
// Space Complexity: O(M*N)


// class Solution {
// public:
    
    void DFS(vector<vector<char>> &grid, int r, int c, int nr, int nc){
        grid[r][c] = '0';
        if(r-1 >= 0 && grid[r-1][c] == '1') DFS(grid, r-1, c, nr, nc);
        if(r + 1 < nr && grid[r+1][c] == '1') DFS(grid, r+1, c, nr, nc);
        if(c - 1 >= 0 && grid[r][c-1] == '1') DFS(grid, r, c-1, nr, nc);
        if(c + 1 < nc && grid[r][c+1] == '1') DFS(grid, r, c+1, nr, nc);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if(!nr)
            return 0;
        int nc = grid[0].size();
        int num_islands = 0;
        for(int i = 0; i < nr; ++i){
            for(int j = 0; j < nc; ++j){
                if(grid[i][j] == '1'){
                    ++num_islands;
                    DFS(grid, i, j, nr, nc);
                }
            }
        }
        return num_islands;
    }
};

// Approach 2: BFS
// Time Complexity: O(N*M)
// Space Complexity: O(min(M,N))




class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if(!nr)
            return 0;
        int nc = grid[0].size();
        int num_islands = 0;
        queue<pair<int, int>> neighbour;
        for(int i = 0; i < nr; ++i){
            for(int j = 0; j < nc; ++j){
                if(grid[i][j] == '1'){
                    ++num_islands;
                    grid[i][j] = 0;
                    neighbour.push({i,j});
                    while(!neighbour.empty()){
                        int r = neighbour.front().first;
                        int c = neighbour.front().second;
                        neighbour.pop();
                        if(r - 1 >= 0 && grid[r-1][c] == '1'){
                            neighbour.push({r-1,c});
                            grid[r-1][c] = '0';
                        } 
                        if(r + 1 < nr && grid[r+1][c] == '1'){
                             neighbour.push({r+1, c});
                             grid[r+1][c] = '0';
                        }
                        if(c - 1 >= 0 && grid[r][c-1] == '1'){
                            neighbour.push({r, c-1});
                            grid[r][c-1] = '0';
                        }
                        if(c + 1 < nc && grid[r][c+1] == '1'){
                             neighbour.push({r, c+1});
                             grid[r][c+1] = '0';
                        }
                    }
                }
            }
        }
        return num_islands;
    }
};

// Approach 3 : Union Find(Disjoint Set)


















