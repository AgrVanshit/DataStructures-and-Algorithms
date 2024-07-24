/*PARTITION DP: STEPS-
1) Start with entire block array.
2)Try all partitions (Run a loop to try all partitions).
3)Return the best possible two partitions.
*/

//*****https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1*****


//****Recursion and Memoization****
//T.C: O(n * n * n);
//S.C: O(n * n) + O(n);
class Solution{
public:
    int solve(int i, int j, int arr[], vector<vector<int>>& dp){
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        
        for(int k = i; k < j; k++){
            int steps = arr[i-1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k+1, j, arr, dp);
            mini = min(mini, steps);
        }
        
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solve(1, N-1, arr, dp);
    }
};


