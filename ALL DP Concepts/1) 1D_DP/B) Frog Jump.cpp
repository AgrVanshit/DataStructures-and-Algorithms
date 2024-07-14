//*****https://www.geeksforgeeks.org/problems/geek-jump/1*****


//Memoization:
class Solution {
  public:
    int solve(int ind, vector<int>& height, vector<int>& dp){
        if(ind == 0) return 0;

        if(dp[ind] != -1) return dp[ind];
        
        int one = abs(height[ind] - height[ind-1]) + solve(ind - 1, height, dp);
        int two = INT_MAX;
        if(ind > 1) two = abs(height[ind] - height[ind-2]) + solve(ind - 2, height, dp);
        
        return dp[ind] = min(one, two);
    }

    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n, -1);

        return solve(n-1, height, dp);
    }
};


//Tabulation:
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n);

        dp[0] = 0;

        for(int ind = 1; ind < n; ind++){
            
            int one = abs(height[ind] - height[ind-1]) + dp[ind-1];
            int two = INT_MAX;
            if(ind > 1) two = abs(height[ind] - height[ind-2]) + dp[ind-2];
            
            dp[ind] = min(one, two);
        }

        return dp[n-1];
    }
};


//Space Optimization:
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n);

        int prev2 = 0;
        int prev = 0;
        int curr;
        for(int ind = 1; ind < n; ind++){
            
            int one = abs(height[ind] - height[ind-1]) + prev;
            int two = INT_MAX;
            if(ind > 1) two = abs(height[ind] - height[ind-2]) + prev2;
            
            curr = min(one, two);
            
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};