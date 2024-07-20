//*****https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/*****


//****Recursion and Memoization****
//T.C: O(n * 2);
//S.C: O(n * 2) + O(n);
class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, int n, vector<vector<int>>& dp){
        if(ind >= n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + solve(ind+1, 0, prices, n, dp), 0 + solve(ind+1, 1, prices, n, dp));
        }
        else{
            profit = max(prices[ind] + solve(ind+2, 1, prices, n, dp), 0 + solve(ind+1, 0, prices, n, dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        
        return solve(0, 1, prices, n, dp);
    }
};


//****Tabulation****
//T.C: O(n * 2);
//S.C: O(n * 2);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2, vector<int>(2, 0));

        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
                }
                else{
                    profit = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
                }

                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }
};


//****Tabulation(Removing inside loop)****
//T.C: O(n);
//S.C: O(n * 2);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for(int ind = n-1; ind >= 0; ind--){
            
            dp[ind][1] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            
            dp[ind][0] = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
        }

        return dp[0][1];
    }
};


//****Space Optimization****
//T.C: O(n);
//S.C: O(6);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(n+2, vector<int>(2, 0));
        vector<int> ffront(2,0), front(2,0), curr(2,0);

        for(int ind = n-1; ind >= 0; ind--){
            
            curr[1] = max(-prices[ind] + front[0], 0 + front[1]);
            
            curr[0] = max(prices[ind] + ffront[1], 0 + front[0]);

            ffront = front;
            front = curr;
        }

        return front[1];
    }
};