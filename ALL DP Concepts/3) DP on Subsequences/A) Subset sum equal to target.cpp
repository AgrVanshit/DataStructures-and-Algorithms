//*****https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1*****


//****Recursion and Memoization****
//T.C: O(n*sum);
//S.C: O(n*sum) + O(n);
class Solution{   
public:
    bool solve(int i, vector<int>& arr, int curr, int sum, vector<vector<int>>& dp){
        if(curr == 0) return true;
        if(i == 0){
            return (curr == arr[0]);
        }
        
        if(dp[i][curr] != -1) return dp[i][curr];
        
        bool pick = false;
        if(curr >= arr[i]) pick = solve(i - 1, arr, curr - arr[i], sum, dp);

        bool npick = solve(i - 1, arr, curr, sum, dp);
        
        return dp[i][curr] = (pick | npick);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(sum + 1, -1));
        
        return solve(n-1, arr, sum, sum, dp);
    }
};


//****Tabulation****
//T.C: O(n * sum);
//S.C: O(n * sum);
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>>dp(n, vector<bool>(sum + 1, 0));
        
        for(int i = 0; i < n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;
        
        for(int ind = 1; ind < n; ind++){
            for(int curr = 1; curr <= sum; curr++){
                bool pick = false;
                if(curr >= arr[ind]) pick = dp[ind-1][curr - arr[ind]];

                bool npick = dp[ind-1][curr];
                
                dp[ind][curr] = (pick | npick);
            }
        }
        
        return dp[n-1][sum];
    }
};


//****Space Optimization****
//T.C: O(n * sum);
//S.C: O(sum);
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        vector<bool>prev(sum+1, 0), cur(sum+1, 0);
        prev[0] = 1;
        cur[0] = 1;
        
        if(arr[0] <= sum) prev[arr[0]] = 1;
        
        for(int ind = 1; ind < n; ind++){
            for(int curr = 1; curr <= sum; curr++){
                bool pick = false;
                if(curr >= arr[ind]) pick = prev[curr - arr[ind]];

                bool npick = prev[curr];
                
                cur[curr] = (pick | npick);
            }

            prev = cur;
        }
        
        return prev[sum];
    }
};