//*****https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/*****


//****Recursion and Memoization****
//T.C: O(n * 2);
//S.C: O(n * 2) + O(n + 2);
class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, int n, vector<vector<int>>& dp){
        if(ind == n) return 0;
        int profit = 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            profit = max(-prices[ind] + solve(ind+1, 0, prices, n, dp), 0 + solve(ind+1, 1, prices, n, dp));
        }
        else{
            profit = max(prices[ind] + solve(ind+1, 1, prices, n, dp), 0 + solve(ind+1, 0, prices, n, dp));
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
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        dp[n][0] = dp[n][1] = 0;
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<2; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
                }
                else{
                    profit = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};


//****2 Array Space Optimization****
//T.C: O(n * 2);
//S.C: O(4);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(n+1, vector<int>(2, -1));
        vector<int> ahead(2, 0), curr(2, 0);
        ahead[0] = ahead[1] = 0;
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<2; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                }
                else{
                    profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};


//****Space Optimization(Using 4 variables)****
//T.C: O(n * 2);
//S.C: O(4);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadBuy, aheadNotBuy, currBuy, currNotBuy;
        aheadNotBuy = aheadBuy = 0;
        for(int ind = n-1; ind>=0; ind--){
            currBuy = max(-prices[ind] + aheadNotBuy, 0 + aheadBuy);

            currNotBuy = max(prices[ind] + aheadBuy, 0 + aheadNotBuy);
                
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }
};