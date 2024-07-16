//*****https://leetcode.com/problems/target-sum/description/*****


//****Recursion and Memoization****
//T.C: O(n) + O(n * k);
//S.C: O(n * k) + O(n);
class Solution {
public:
    int solve(int ind, int target, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || target == nums[0]) return 1;
            return 0;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        int nt = 0 + solve(ind - 1, target, n, nums, dp);
        int t = 0;
        if(nums[ind] <= target) t = solve(ind-1, target-nums[ind], n, nums, dp);

        return dp[ind][target] = t + nt;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(auto &it:nums) totSum+=it;

        if(totSum - target < 0 || (totSum - target)%2) return 0;

        int k = (totSum - target)/2;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));

        return solve(n-1, k, n, nums, dp);
    }
};


//****Space Optimization****
//T.C: O(n) + (n * k);
//S.C: O(k);
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(auto &it:nums) totSum+=it;

        if(totSum - target < 0 || (totSum - target)%2) return 0;

        int k = (totSum - target)/2;
        vector<int>prev(k+1, 0), curr(k+1, 0);
        
        if(nums[0] <= k) prev[nums[0]] = 1; 
        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        
        for(int i = 1; i < n; i++){
            for(int currsum = 0; currsum <= k; currsum++){
                int pick = 0;
        	    if(currsum >= nums[i]) pick = prev[currsum-nums[i]];

        	    int npick = prev[currsum];
        	    
        	    curr[currsum] = (pick + npick);
            }
            
            prev = curr;
        }
        
        return prev[k];
    }
};