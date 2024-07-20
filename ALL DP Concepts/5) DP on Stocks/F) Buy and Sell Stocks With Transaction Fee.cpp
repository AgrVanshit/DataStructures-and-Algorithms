//*****https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/*****


//T.C: O(n * 2);
//S.C: O(4);
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadBuy, aheadNotBuy, currBuy, currNotBuy;
        aheadNotBuy = aheadBuy = 0;

        for(int ind = n-1; ind>=0; ind--){
            currBuy = max(-prices[ind] + aheadNotBuy, 0 + aheadBuy);

            currNotBuy = max(prices[ind] - fee + aheadBuy, 0 + aheadNotBuy);
                
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

        return aheadBuy;
    }
};