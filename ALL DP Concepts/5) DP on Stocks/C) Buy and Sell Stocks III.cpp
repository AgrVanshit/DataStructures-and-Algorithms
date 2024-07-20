//*****https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/*****


//****Memoization****
//T.C = O(N * 2 * 3);
//S.C = O(N * 2 * 3) + O(N);
class Solution {
public:
    int solve(int ind, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>>& dp){
        if(cap == 0) return 0;
        if(ind == n) return 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + solve(ind + 1, 0, cap, prices, n, dp), 0 + solve(ind + 1, 1, cap, prices, n, dp));
        }
        else profit = max(prices[ind] + solve(ind + 1, 1, cap-1, prices, n, dp), 0 + solve(ind + 1, 0, cap, prices, n, dp));

        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(0, 1, 2, prices, n, dp);
    }
};


//****Tabulation****
//T.C = O(N * 2 * 3);
//S.C = O(N * 2 * 3);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy < 2; buy++){
                for(int cap = 1; cap<=2; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                    }
                    else profit = max(prices[ind] +dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);

                    dp[ind][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};


//****Space Optimization****
// T.C = O(N * 2 * 3);
// S.C = Nearly O(1);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy < 2; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[ind] + ahead[0][cap], 0 + ahead[1][cap]);
                    }
                    else profit = max(prices[ind] + ahead[1][cap-1], 0 + ahead[0][cap]);

                    curr[buy][cap] = profit;
                }
            }

            ahead = curr;
        }
        
        return ahead[1][2];
    }
};


//****Using (N * 4) DP array in place (N * 2 * 3)****
//****Memoization****
// T.C = O(N * 4);
// S.C = O(N * 4) + O(N);
class Solution {
public:
    int solve(int ind, int transaction, vector<int>& prices, int n, vector<vector<int>>& dp){
        if(ind == n || transaction == 4) return 0;

        if(dp[ind][transaction] != -1) return dp[ind][transaction];

        int profit = 0;
        if(transaction%2 == 0){
            profit = max(-prices[ind] + solve(ind + 1, transaction + 1, prices, n, dp), 0 + solve(ind + 1, transaction, prices, n, dp));
        }
        else{
            profit = max(prices[ind] + solve(ind + 1, transaction + 1, prices, n, dp), 0 + solve(ind + 1, transaction, prices, n, dp));
        }

        return dp[ind][transaction] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));

        return solve(0, 0, prices, n, dp);
    }
};