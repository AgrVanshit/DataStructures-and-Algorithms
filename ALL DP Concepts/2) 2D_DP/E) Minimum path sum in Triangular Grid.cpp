//*****https://leetcode.com/problems/triangle/description/*****


//****Recursion and Memoization****
//T.C: O(n * n);
//S.C: O(n) + O(n * n);
class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i == n-1) return triangle[n-1][j];

        if(dp[i][j] != -1) return dp[i][j];

        int d = triangle[i][j] + solve(i+1, j, n, triangle, dp);
        int dg = triangle[i][j] + solve(i+1, j+1, n, triangle, dp);

        return dp[i][j] = min(d, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(0, 0, n, triangle, dp);
    }
};


//****Tabulation****
//T.C: O(n * n);
//S.C: O(n * n);
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int j = 0; j < n; j++) dp[n-1][j] = triangle[n-1][j];

        for(int i = n-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){

                int d = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(d, dg);
            }
        }

        return dp[0][0];
    }
};


//****Space Optimization****
//T.C: O(n * n);
//S.C: O(n);
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        vector<int> front(n, 0), cur(n, 0);
        for(int j = 0; j < n; j++) front[j] = triangle[n-1][j];

        for(int i = n-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){

                int d = triangle[i][j] + front[j];
                int dg = triangle[i][j] + front[j+1];

                cur[j] = min(d, dg);
            }

            front = cur;
        }

        return front[0];
    }
};