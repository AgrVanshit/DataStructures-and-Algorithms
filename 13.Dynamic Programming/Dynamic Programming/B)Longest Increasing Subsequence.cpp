//*****https://leetcode.com/problems/longest-increasing-subsequence/description/*****


//****Recursion and Memoization****
//T.C: O(n * n);
//S.C: O(n * n) + O(n);
class Solution {
private:
    int solve(int ind, int prev_ind, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == n) return 0;

        if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        int len = 0 + solve(ind + 1, prev_ind, n, nums, dp);
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len, 1 + solve(ind+1, ind, n, nums, dp));
        }

        return dp[ind][prev_ind + 1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(0, -1, n, nums, dp);
    }
};


//****Tabulation****
//T.C: O(n * n);
//S.C: O(n * n);
class Solution {
private:
    int solve(int ind, int prev_ind, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == n) return 0;

        if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        int len = 0 + solve(ind + 1, prev_ind, n, nums, dp);
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len, 1 + solve(ind+1, ind, n, nums, dp));
        }

        return dp[ind][prev_ind + 1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int ind = n-1; ind >= 0; ind--){
            for(int prev_ind = ind-1; prev_ind >= -1; prev_ind--){
                int len = 0 + dp[ind+1][prev_ind+1];
                if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    len = max(len, 1 + dp[ind+1][ind+1]);
                }

                dp[ind][prev_ind + 1] = len;
            }
        }

        return dp[0][-1+1];
    }
};


//****2 Array Space Optimization****
//T.C: O(n * n);
//S.C: O(n);
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int> ahead(n+1, 0), curr(n+1,0);

        for(int ind = n-1; ind >= 0; ind--){
            for(int prev_ind = ind-1; prev_ind >= -1; prev_ind--){
                int len = 0 + ahead[prev_ind+1];
                if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    len = max(len, 1 + ahead[ind+1]);
                }

                curr[prev_ind + 1] = len;
            }

            ahead = curr;
        }

        return ahead[-1+1];
    }
};


//****Alternate Tabulation Approach****
//T.C: O(n * n);
//S.C: O(n);
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxi = -1;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};