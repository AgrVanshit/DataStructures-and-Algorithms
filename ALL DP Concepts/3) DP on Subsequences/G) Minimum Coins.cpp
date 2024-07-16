//*****https://leetcode.com/problems/coin-change/description/*****


//****Recursion and Memoization****
//T.C: O(n*amount);
//S.C: O(n*amount) + O(n);
class Solution {
public:
    int solve(int ind, int T, int n, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(T % coins[ind] == 0) return T/coins[ind];
            return 1e9;
        }

        if(dp[ind][T] != -1) return dp[ind][T];

        int nottake = 0 + solve(ind - 1, T, n, coins, dp);
        int take = INT_MAX;
        if(coins[ind] <= T) take = 1 + solve(ind, T-coins[ind], n, coins, dp);

        return dp[ind][T] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        if(solve(n-1, amount, n, coins, dp) >= 1e9) return -1;
        return solve(n-1, amount, n, coins, dp);
    }
};


//****Tabulation****
//T.C: O(n * amount);
//S.C: O(n * amount);
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int T = 0; T <= amount; T++){
            if(T % coins[0] == 0) dp[0][T] = T/coins[0];
            else dp[0][T] = 1e9;
        }

        for(int ind = 1; ind < n; ind++){
            for(int T = 0; T <= amount; T++){
                int nottake = 0 + dp[ind - 1][T];

                int take = INT_MAX;
                if(coins[ind] <= T) take = 1 + dp[ind][T-coins[ind]];

                dp[ind][T] = min(take, nottake);
            }
        }
        
        if(dp[n-1][amount] >= 1e9) return -1;
        return dp[n-1][amount];
    }
};


//****Space Optimization****
//T.C: O(n * amount);
//S.C: O(amount);
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for(int T = 0; T <= amount; T++){
            if(T % coins[0] == 0) prev[T] = T/coins[0];
            else prev[T] = 1e9;
        }

        for(int ind = 1; ind < n; ind++){
            for(int T = 0; T <= amount; T++){
                int nottake = 0 + prev[T];

                int take = INT_MAX;
                if(coins[ind] <= T) take = 1 + curr[T-coins[ind]];

                curr[T] = min(take, nottake);
            }

            prev = curr;
        }

        if(prev[amount] >= 1e9) return -1;
        return prev[amount];
    }
};