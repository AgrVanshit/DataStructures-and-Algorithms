//*****https://leetcode.com/problems/minimum-falling-path-sum/description/*****


//****Recursion and Memoization****
//T.C: O(n*n);
//S.C: O(n*n) + O(n)
class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j < 0 || j  > n-1) return 1e9;
        if(i == 0) return matrix[0][j];

        if(dp[i][j] != -1) return dp[i][j];
        
        int s = matrix[i][j] + solve(i-1, j, n, matrix, dp);
        int ld = matrix[i][j] + solve(i-1, j-1, n, matrix, dp);
        int rd = matrix[i][j] + solve(i-1, j+1, n, matrix, dp);

        return dp[i][j] = min(s, min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j = 0; j < n; j++){
            mini = min(mini, solve(n-1, j, n, matrix, dp));
        }
        
        return mini;
    }
};


//****Tabulation****
//T.C: O(n*n) + O(n);
//S.C: O(n*n);
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j = 0; j < n; j++) dp[0][j] = matrix[0][j];

        for(int i = 1; i < n; i++){
            for(int j = 0; j<n; j++){
                int s = matrix[i][j] + dp[i-1][j];

                int ld = matrix[i][j]; 
                if(j > 0) ld += dp[i-1][j-1];
                else ld += 1e9;

                int rd = matrix[i][j];
                if(j+1 < n) rd += dp[i-1][j+1];
                else rd += 1e9;

                dp[i][j] = min(s,min(ld,rd));
            }
        }

        int mini = dp[n-1][0];

        for(int j = 1; j < n; j++){
            mini = min(mini, dp[n-1][j]);
        }

        return mini;
    }
};


//****Space Optimization****
//T.C: O(n*n) + O(n);
//S.C: O(n);
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        vector<int> prev(n,0), cur(n,0);

        for(int j = 0; j < n; j++) prev[j] = matrix[0][j];

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int s = matrix[i][j] + prev[j];

                int ld = matrix[i][j]; 
                if(j > 0) ld += prev[j-1];
                else ld += 1e9;

                int rd = matrix[i][j];
                if(j+1 < n) rd += prev[j+1];
                else rd += 1e9;

                cur[j] = min(s, min(ld,rd));
            }

            prev = cur;
        }

        int mini = prev[0];

        for(int j = 1; j < n; j++){
            mini = min(mini, prev[j]);
        }

        return mini;
    }
};