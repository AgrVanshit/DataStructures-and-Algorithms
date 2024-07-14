//*****https://leetcode.com/problems/house-robber/description/*****


//****Recursive Approach****
//T.C = O(2^N)
//TLE
class Solution {
public:
    int solve(vector<int>& nums,int ind){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;

        int pick = nums[ind] + solve(nums, ind-2);
        int notpick = 0 + solve(nums, ind-1);

        return max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        return solve(nums, n-1);
    }
};


//****Memoization****
//T.C = O(N)
//S.C = O(2*N)
class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int ind){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + solve(nums, dp, ind-2);
        int notpick = 0 + solve(nums, dp, ind-1);

        return dp[ind] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);

        return solve(nums, dp, n-1);
    }
};


//****Tabulation****
//T.C = O(N)
//S.C = O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];
        int neg = 0;

        for(int i=1; i<n; i++){

           int pick = nums[i];
           if(i>1) pick += dp[i-2];

           int notpick = 0 + dp[i-1];

           dp[i] = max(pick, notpick);
        }

        return dp[n-1];
    }
};


//****Space Optimization****
//T.C = O(N)
//S.C = O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        int prev = nums[0];
        int prev2 = 0;

        for(int i=1; i<n; i++){

           int pick = nums[i] + prev2;
           int notpick = 0 + prev;

           int curri = max(pick, notpick);

           prev2 = prev;
           prev = curri;
        }

        return prev;
    }
};