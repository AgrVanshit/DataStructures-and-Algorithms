//*****https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/*****


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(prices[i] > mini) maxi = max(maxi, prices[i]-mini);
            else mini = prices[i];
        }
        return maxi;
    }
};