//*****https://leetcode.com/problems/unique-paths-ii/description/*****


//****Recursion and Memoization****
//T.C: O(m*n);
//S.C: O((m-1) + (n-1)) + O(m*n)
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = 0,left = 0;
        if(i>0 && obstacleGrid[i-1][j] != 1) up = solve(i-1, j, obstacleGrid, dp);
        if(j>0 && obstacleGrid[i][j-1] != 1) left = solve(i, j-1, obstacleGrid, dp);
        
        return dp[i][j] = up + left; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        if(obstacleGrid[m-1][n-1] == 1) return 0;
        return solve(m-1, n-1, obstacleGrid, dp);
    }
};


//****Tabulation****
//T.C: O(m*n);
//S.C: O(m*n);
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        if(obstacleGrid[m-1][n-1] == 1) return 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int up = 0,left = 0;
                    if(i > 0 && obstacleGrid[i-1][j] != 1) up = dp[i-1][j];
                    if(j > 0 && obstacleGrid[i][j-1] != 1) left = dp[i][j-1];
                    dp[i][j] = up + left; 
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();

        vector<int> prev(n, 0);

        if(obstacleGrid[m-1][n-1] == 1) return 0;

        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0 && obstacleGrid[i-1][j] != 1) up = prev[j];
                    if(j > 0 && obstacleGrid[i][j-1] != 1) left = curr[j-1];
                    curr[j] = up + left; 
                }
            }

            prev = curr;
        }

        return prev[n-1];
    }
};




//**************************************Alternate******************************************

//****Recursion and Memoization****
//T.C: O(m*n);
//S.C: O((m-1) + (n-1)) + O(m*n);
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){ 
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = 0,left = 0;
        if(i > 0) up = solve(i-1, j, obstacleGrid, dp);
        if(j > 0) left = solve(i, j-1, obstacleGrid, dp);
        
        return dp[i][j] = up + left; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        if(obstacleGrid[m-1][n-1] == 1) return 0;
        return solve(m-1, n-1, obstacleGrid, dp);
    }
};


//****Tabulation****
//T.C: O(m*n);
//S.C: O(m*n);
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        if(obstacleGrid[m-1][n-1] == 1) return 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int up = 0,left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left; 
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();

        vector<int> prev(n, 0);

        if(obstacleGrid[m-1][n-1] == 1) return 0;

        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1) curr[j] = 0;
                else if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j-1];
                    curr[j] = up + left; 
                }
            }

            prev = curr;
        }

        return prev[n-1];
    }
};