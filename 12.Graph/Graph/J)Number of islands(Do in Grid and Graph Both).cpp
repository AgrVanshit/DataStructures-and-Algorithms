//*****https://leetcode.com/problems/number-of-islands/description/*****


//BFS Approach:
//T.C: O(n*m);
//S.C: 2*O(n*m);
class Solution {
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vis[row][col] = 1;
        q.push({row, col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
             
            for(int delrow = -1; delrow<=1; delrow++){
                for(int delcol = -1; delcol<=1; delcol++){
                    if(delrow != 0 && delcol != 0) continue; 
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && 
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};


//DFS Approach:
//T.C: O(n*m);
//S.C: 2*O(n*m);
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i != 0 && j != 0) continue;
                int nrow = row + i;
                int ncol = col + j;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' 
                    && !vis[nrow][ncol]){
                        dfs(nrow, ncol, vis, grid);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    dfs(row, col, vis, grid);
                }
            }
        }

        return cnt;
    }
};