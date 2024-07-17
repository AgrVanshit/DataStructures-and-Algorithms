//*****https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1*****


//****Recursion and Memoization****
//T.C: O(n*W);
//S.C: O(n*W) + O(n);
class Solution{
public:
    int solve(int ind, int W, int val[], int wt[], vector<vector<int>>& dp){
        if(ind == 0){
            return (int)(W/wt[0]) * val[0];
        }
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int nottake = 0 + solve(ind - 1, W, val, wt, dp);
        
        int take = 0;
        if(W >= wt[ind]) take = val[ind] + solve(ind, W - wt[ind], val, wt, dp);
        
        return dp[ind][W] = max(take, nottake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        return solve(N-1, W, val, wt, dp);
    }
};


//****Tabulation****
//T.C: O(n * W);
//S.C: O(n * W);
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, 0));
        
        for(int w = 0; w <= W; w++){
            dp[0][w] = w/wt[0] * val[0];
        }
        
        for(int ind = 1; ind < N; ind++){
            for(int w = 0; w <= W; w++){
                int nottake = 0 + dp[ind-1][w];

                int take = 0;
                if(w >= wt[ind]) take = val[ind] + dp[ind][w - wt[ind]];
                
                dp[ind][w] = max(take, nottake);
            }
        }
        
        return dp[N-1][W];
    }
};


//****2 Array Space Optimization****
//T.C: O(n * W);
//S.C: O(2 * W);
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> prev(W + 1, 0), curr(W + 1, 0);
        
        for(int w = 0; w <= W; w++){
            prev[w] = w/wt[0] * val[0];
        }
        
        for(int ind = 1; ind < N; ind++){
            for(int w = 0; w <= W; w++){
                int nottake = 0 + prev[w];

                int take = 0;
                if(w >= wt[ind]) take = val[ind] + curr[w - wt[ind]];
                
                curr[w] = max(take, nottake);
            }

            prev = curr;
        }
        
        return prev[W];
    }
};


//****1 Array Space Optimization****
//T.C: O(n * W);
//S.C: O(W);
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> prev(W + 1, 0);
        
        for(int w = 0; w <= W; w++){
            prev[w] = w/wt[0] * val[0];
        }
        
        for(int ind = 1; ind < N; ind++){
            for(int w = 0; w <= W; w++){
                int nottake = 0 + prev[w];

                int take = 0;
                if(w >= wt[ind]) take = val[ind] + prev[w - wt[ind]];
                
                prev[w] = max(take, nottake);
            }
        }
        
        return prev[W];
    }
};