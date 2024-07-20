//*****https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/*****


//****Space Optimization****
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy < 2; buy++){
                for(int cap = 1; cap <= k; cap++){
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

        return ahead[1][k];
    }
};


//****Using (N * 2k) DP array in place (N * 2 * 3)****

//****Memoization****
// T.C = O(N * 2k);
// S.C = O(N * 2k) + O(N);
class Solution {
public:
    int solve(int ind, int transaction, vector<int>& prices, int k, int n, vector<vector<int>>& dp){
        if(ind == n || transaction == 2*k) return 0;
        if(dp[ind][transaction] != -1) return dp[ind][transaction];
        int profit = 0;

        if(transaction%2 == 0){
            profit = max(-prices[ind] + solve(ind + 1, transaction + 1, prices, k, n, dp), 0 + solve(ind + 1, transaction, prices, k, n, dp));
        }
        else{
            profit = max(prices[ind] + solve(ind + 1, transaction + 1, prices, k, n, dp), 0 + solve(ind + 1, transaction, prices, k, n, dp));
        }

        return dp[ind][transaction] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));

        return solve(0, 0, prices, k, n, dp);
    }
};


//****Tabulation****
// T.C = O(N * 2k);
// S.C = O(N * 2k);
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

        for(int ind = n-1; ind >= 0; ind--){
            for(int transaction = 2*k - 1; transaction >= 0; transaction--){
                int profit = 0;

                if(transaction%2 == 0){
                    profit = max(-prices[ind] + dp[ind+1][transaction+1], 0 + dp[ind+1][transaction]);
                }
                else{
                    profit = max(prices[ind] + dp[ind+1][transaction+1], 0 + dp[ind+1][transaction]);
                }

                dp[ind][transaction] = profit;
            }
        }

        return dp[0][0];
    }
};


//****Space Optimization****
// T.C = O(N * 2k);
// S.C = O(2 * 2k);
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2*k+1, 0);
        vector<int> curr(2*k+1, 0);

        for(int ind = n-1; ind >= 0; ind--){
            for(int transaction = 2*k - 1; transaction >= 0; transaction--){
                int profit = 0;

                if(transaction%2 == 0){
                    profit = max(-prices[ind] + ahead[transaction+1], 0 + ahead[transaction]);
                }
                else{
                    profit = max(prices[ind] + ahead[transaction+1], 0 + ahead[transaction]);
                }
                curr[transaction] = profit;
            }

            ahead = curr;
        }

        return ahead[0];
    }
};