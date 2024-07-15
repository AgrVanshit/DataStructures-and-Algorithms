//*****https://leetcode.com/problems/partition-equal-subset-sum/description/*****


//****Recursion and Memoization****
//T.C: O(n*sum) + O(n);
//S.C: O(n*sum) + O(n);
class Solution {
public:
    bool solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return(nums[0] == target);

        if(dp[ind][target] != -1) return dp[ind][target];

        bool nt = solve(ind-1, target, nums, dp);
        bool t = false;
        if(nums[ind] <= target) t = solve(ind-1, target-nums[ind], nums, dp);

        return dp[ind][target]= (nt | t);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum = sum + nums[i];

        if(sum % 2) return false;

        int k = sum/2;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));

        return solve(n-1, k, nums, dp);
    }
};


//****Tabulation****
//T.C: O(n * sum) + O(n);
//S.C: O(n * sum);
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum = sum + nums[i];
        if(sum % 2) return false;
        int k = sum/2;

        vector<vector<bool>> dp(n, vector<bool>(k+1, 0));

        for(int ind = 0; ind < n; ind++) dp[ind][0]=true;
        if(nums[0] <= k) dp[0][nums[0]] = true;
        
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= k; target++){

                bool nt = dp[ind-1][target];
                bool t = false;
                if(nums[ind] <= target) t = dp[ind-1][target-nums[ind]];

                dp[ind][target] = (nt | t);
           }
        }
        return dp[n-1][k];
    }
};


//****Space Optimization****
//T.C: O(n * sum) + O(n);
//S.C: O(sum);
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum = sum + nums[i];

        if(sum % 2) return false;

        int k = sum/2;
        vector<int> prev(k+1, 0), cur(k+1, 0);

        prev[0] = 0; cur[0] = 0;
        if(nums[0] <= k) prev[nums[0]] = true;

        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= k; target++){
                bool nt = prev[target];

                bool t = false;
                if(nums[ind] <= target) t = prev[target-nums[ind]];

                cur[target]= (nt | t);
           }

           prev = cur;
        }

        return prev[k];
    }
};