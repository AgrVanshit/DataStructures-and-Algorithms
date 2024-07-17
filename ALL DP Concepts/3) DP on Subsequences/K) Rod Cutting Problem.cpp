//*****https://www.geeksforgeeks.org/problems/rod-cutting0840/1*****


//****Recursion and Memoization****
//T.C: O(n * n);
//S.C: O(n * n) + O(n);
class Solution{
  public:
    int solve(int i, int tar, int price[], vector<vector<int>>& dp){
        if(i == 0){
            return (int)(tar/(i+1)) * price[0];
        }

        if(dp[i][tar] != -1) return dp[i][tar];

        int ntake = 0 + solve(i-1, tar, price, dp);

        int take = INT_MIN;
        if(i+1 <= tar) take = price[i] + solve(i, tar-i-1, price, dp);
        
        return dp[i][tar] = max(take, ntake);
    }

    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n, vector<int>(n+1, -1));

        return solve(n-1, n, price, dp);
    }
};


//****Tabulation****
//T.C: O(n * n);
//S.C: O(n * n);
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n, vector<int>(n+1, 0));
        
        for(int tar = 0; tar <= n; tar++){
            dp[0][tar] = tar * price[0];
        }
        
        for(int i = 1; i < n; i++){
            for(int tar = 0; tar <= n; tar++){
                int ntake = 0 + dp[i-1][tar];

                int take = INT_MIN;
                if(i+1 <= tar) take = price[i] + dp[i][tar-i-1];
                
                dp[i][tar] = max(take, ntake);
            }
        }
        
        return dp[n-1][n];
    }
};


//****2 Array Space Optimization****
//T.C: O(n * n);
//S.C: O(2 * n);
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int tar = 0; tar <= n; tar++){
            prev[tar] = tar * price[0];
        }
        
        for(int i = 1; i < n; i++){
            for(int tar = 0; tar <= n; tar++){
                int ntake = 0 + prev[tar];

                int take = INT_MIN;
                if(i+1 <= tar) take = price[i] + curr[tar-i-1];
                
                curr[tar] = max(take, ntake);
            }

            prev = curr;
        }
        
        return prev[n];
    }
};


//****1 Array Space Optimization****
//T.C: O(n * n);
//S.C: O(n);
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> prev(n+1, 0);
        
        for(int tar = 0; tar <= n; tar++){
            prev[tar] = tar * price[0];
        }
        
        for(int i = 1; i < n; i++){
            for(int tar = 0; tar <= n; tar++){
                int ntake = 0 + prev[tar];

                int take = INT_MIN;
                if(i+1 <= tar) take = price[i] + prev[tar-i-1];
                
                prev[tar] = max(take, ntake);
            }
        }
        
        return prev[n];
    }
};