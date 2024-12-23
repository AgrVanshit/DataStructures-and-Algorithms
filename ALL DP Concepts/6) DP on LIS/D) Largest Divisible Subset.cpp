//*****https://leetcode.com/problems/largest-divisible-subset/description/*****


//T.C: O(n * n) + O(n);
//S.C: O(2 * n);
class Solution {
private:
    vector<int> lengthOfLDivisibleIS(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1), hash(n);
        int maxi = -1;
        int lastIndex = 0;
        for(int i = 0; i<n; i++){
            hash[i] = i;
            for(int prev = 0; prev<i; prev++){
                if(nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
              maxi = dp[i];
              lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);

        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }

        return temp;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return lengthOfLDivisibleIS(nums);
    }
};