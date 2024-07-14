//*****https://www.geeksforgeeks.org/problems/minimal-cost/1*****


//****Memoization****
//T.C = O(N * k)
//S.C = O(2*N)
class Solution {
  public:
    int solve(vector<int>& height, int ind, int k, vector<int>& dp){
        if(ind == 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int mini = INT_MAX;
        
        for(int i = 1; i <= k; i++){
            if(ind >= i) {
                int jump = solve(height, ind - i, k, dp) + abs(height[ind] - height[ind - i]);
                mini = min(mini, jump);
            }    
        }
        
        return dp[ind] = mini;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n, -1);
        return solve(height, n-1, k, dp);
    }
};


//****Tabulation****
//T.C = O(N * k)
//S.C = O(N)
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n);
        
        dp[0] = 0;
        
        for(int ind = 1; ind < n; ind++){
            int mini = INT_MAX;
            for(int i = 1; i <= k; i++){
                if(ind >= i) {
                    int jump = dp[ind-i] + abs(height[ind] - height[ind - i]);
                    mini = min(mini, jump);
                }    
            }
            dp[ind] = mini;
        }
        
        return dp[n-1];
    }
};