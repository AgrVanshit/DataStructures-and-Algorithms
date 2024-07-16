//*****https://leetcode.com/problems/coin-change-ii/description/*****


//****Recursion and Memoization****
//T.C: O(n*amount);
//S.C: O(n*amount) + O(n);
class Solution {
public:
    int solve(int ind, int amount, int n, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            return (amount%coins[ind] == 0);
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int nt = solve(ind - 1, amount, n, coins, dp);
        int t = 0;
        if(coins[ind] <= amount) t = solve(ind, amount - coins[ind], n, coins, dp);

        return dp[ind][amount] = (t + nt) ;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        
        return solve(n-1, amount, n, coins, dp);
    }
};


//****Tabulation****
//T.C: O(n * amount);
//S.C: O(n * amount);
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int tar = 0; tar<=amount; tar++){
            if(tar % coins[0] == 0) dp[0][tar] = 1;
        }

        for(int ind = 1; ind < n; ind++){
            for(int tar = 0; tar <= amount; tar++){
                int nt = 0 + dp[ind - 1][tar];

                int t = 0;
                if(coins[ind] <= tar) t = dp[ind][tar - coins[ind]];

                dp[ind][tar] = (t + nt) ;
            }
        }

        return dp[n-1][amount];
    }
};


//****Space Optimization****
//T.C: O(n * amount);
//S.C: O(amount);
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1, 0),curr(amount+1, 0);

        for(int tar = 0; tar<=amount; tar++){
            if(tar % coins[0] == 0) prev[tar] = 1;
        }

        for(int ind = 1; ind < n; ind++){
            for(int tar = 0; tar <= amount; tar++){
                int nt = 0 + prev[tar];

                int t = 0;
                if(coins[ind] <= tar) t = curr[tar - coins[ind]];

                curr[tar] = (t + nt) ;
            }

            prev = curr;
        }

        return prev[amount];
    }
};