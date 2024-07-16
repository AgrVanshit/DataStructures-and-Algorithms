//*****https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1*****


//****Recursion and Memoization****
//T.C: O(n*W);
//S.C: O(n*W) + O(n);
class Solution{
public:
    int solve(int i, int w, int wt[], int val[], int n, vector<vector<int>>& dp){
        if(i == 0){
            if(wt[0] <= w) return val[0];
            else return 0;
        }

        if(dp[i][w] != -1) return dp[i][w];

        int pick = INT_MIN;
        if(w >= wt[i]) pick = val[i] + solve(i-1, w - wt[i], wt, val, n, dp);

        int npick = 0 + solve(i-1, w, wt, val, n, dp);
        
        return dp[i][w] = max(pick, npick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n, vector<int>(W+1, -1));

       return solve(n-1, W, wt, val, n, dp);
    }
};


//****Tabulation****
//T.C: O(n * W);
//S.C: O(n * W);
class Solution{
public:
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n, vector<int>(W+1));
        
        for(int i = 0; i <= W; i++){
            if(i >= wt[0]) dp[0][i] = val[0];
            else dp[0][i] = 0;
        }
        
        for(int i = 1; i < n; i++){
            for(int w = 0; w <= W; w++){
                int pick = INT_MIN;
                if(w >= wt[i]) pick = val[i] + dp[i-1][w-wt[i]];
                int npick = 0 + dp[i-1][w];
                
                dp[i][w] = max(pick, npick);
            }
        }
        
        return dp[n-1][W];
    }
};


//****2 Array Space Optimization****
//T.C: O(n * W);
//S.C: O(W);
class Solution{
public:
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<int>prev(W+1, 0),curr(W+1, 0);

        for(int i = 0; i <= W; i++){
            if(i >= wt[0]) prev[i] = val[0];
            else prev[i] = 0;
        }
        
        for(int i = 1; i < n; i++){
            for(int w = 0; w <= W; w++){
                int pick = INT_MIN;
                if(w >= wt[i]) pick = val[i] + prev[w-wt[i]];

                int npick = 0 + prev[w];
                
                curr[w] = max(pick, npick);
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
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<int>prev(W+1, 0);
        
        for(int i = 0; i <= W; i++){
            if(i >= wt[0]) prev[i] = val[0];
            else prev[i] = 0;
        }
        
        for(int i = 1; i < n; i++){
            for(int w = W; w >= 0; w--){
                int pick = INT_MIN;
                if(w >= wt[i]) pick = val[i] + prev[w-wt[i]];
                
                int npick = 0 + prev[w];
                
                prev[w] = max(pick, npick);
            }
        }
        
        return prev[W];
    }
};