//*****https://leetcode.com/problems/minimum-path-sum/description/*****


//****Recursion and Memoization****
//T.C: O(m*n);
//S.C: O((m-1) + (n-1)) + O(m*n)
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        long long up = grid[i][j] + solve(i-1, j, grid, dp);
        long long left = grid[i][j] + solve(i, j-1, grid, dp);

        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();

        vector<vector<int>>dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, grid, dp);
    }
};


//****Tabulation****
//T.C: O(m*n);
//S.C: O(m*n);
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();

        vector<vector<int>>dp(m,vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[0][0] = grid[0][0];
                else{
                    int up = grid[i][j];
                    if(i > 0) up += dp[i-1][j];
                    else up += 1e9;

                    int left = grid[i][j];
                    if(j > 0) left += dp[i][j-1];
                    else left += 1e9;

                    dp[i][j] = min(up, left);
                }    
            }
        }

        return dp[m-1][n-1];
    }
};


//****Space Optimization****
//T.C: O(m*n);
//S.C: O(n);
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();

        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) curr[0] = grid[0][0];
                else{
                    int up = grid[i][j];
                    if(i > 0) up += prev[j];
                    else up += 1e9;

                    int left = grid[i][j];
                    if(j > 0) left += curr[j-1];
                    else left += 1e9;

                    curr[j] = min(up, left);
                }    
            }
            prev = curr;
        }

        return prev[n-1];
    }
};