//*****https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/*****


//T.C: O(n * n) + O(n);
//S.C: O(2 * n);
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;

        vector<int> dp(n, 1), cnt(n, 1);

        for(int i = 0; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[i] > nums[prev] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    //inherit
                    cnt[i] = cnt[prev];
                }
                else if(nums[i] > nums[prev] && 1 + dp[prev] == dp[i]){
                    //increase the count
                    cnt[i] += cnt[prev];
                }
            }

            maxi = max(maxi, dp[i]);
        }

        int nos = 0;

        for(int i = 0; i < n; i++){
            if(dp[i] == maxi) nos += cnt[i];
        }

        return nos;
    }
};