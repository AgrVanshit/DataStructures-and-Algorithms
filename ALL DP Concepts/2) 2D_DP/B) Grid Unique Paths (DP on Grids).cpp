//*****https://leetcode.com/problems/unique-paths/description/*****


//Approach 1:
//Recursion and Memoization:
//T.C: O(m*n);
//S.C: O((m-1) + (n-1)) + O(m*n)
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = solve(i-1, j, dp);
        int left = solve(i, j-1, dp);

        return dp[i][j] = up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));

        return solve(m-1, n-1, dp);
    }
};


//Approach: 2
//Tabulation:
//T.C: O(m*n);
//S.C: O(m*n);
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) dp[i][j] = 1;//base case it is
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];

                    dp[i][j] = up + left;
                }    
            }
        }

        return dp[m-1][n-1];
    }
};


//Approach: 3
//Space Optimization:
//T.C: O(m*n);
//S.C: O(m);
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);

        for(int i=0; i<m; i++){
            vector<int> curr(n, 0); 
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) curr[j] = 1;//base case it is
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];

                    curr[j] = up + left;
                }    
            }

            prev = curr;
        }
        
        return prev[n-1];
    }
};


//Approach: 4
//T.C: O(m-1) OR O(n-1);
//S.C: O(1);
//Total no. of unique paths: (m+n-2)C(m-1) OR (m+n-2)C(n-1);
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int R = m - 1;
        double res = 1;

        for(int i = 0; i < R; i++){
            res *= N-i;
            res /= i+1;
        }

      /*There can only be 2 options, res can be between 
        e.g if res is 3.5-4 then increament of 0.5 in
        (int)res will result in value less than res so
        we increament it to 4 by taking ceil, if res is
        3-3.5 then its (int) is 3 so no need of any ceil,
        in this we we are rounding off to nearest integer 
        value. */
        if(res > int(res)+0.5){
            return ceil(res);
        }
        return int(res);
    }
};


//Approach: 5(Same as Approach: 4)
//T.C: O(m-1) OR O(n-1);
//S.C: O(1);
//Total no. of unique paths: (m+n-2)C(m-1) OR (m+n-2)C(n-1);
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int r = m - 1; 
        double res = 1;
        
        for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
        return (int)res;
    }
};