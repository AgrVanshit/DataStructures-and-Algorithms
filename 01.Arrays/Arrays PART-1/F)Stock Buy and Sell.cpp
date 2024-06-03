//*****https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/*****


//Bruteforce Approach:
// T.C: O(n*n);
// S.C: O(1);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0;
        
        for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               profit=max(profit,prices[j]-prices[i]);
           }
        }
        return profit;
    }
};


//Optimal Approach:
// T.C: O(n);
// S.C: O(1);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], profit = 0,cost,n = prices.size();

        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            profit=max(profit,cost);

            mini=min(mini,prices[i]);
        }
        return profit;
    }
};