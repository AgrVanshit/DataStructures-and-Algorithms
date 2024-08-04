//*****https://leetcode.com/problems/subsets/description/*****


class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& subs, vector<vector<int>>& ans){
        int n = nums.size();
        if(i == n){
            ans.push_back(subs);
            return;
        }

        subs.push_back(nums[i]);
        solve(i+1, nums, subs, ans);
        subs.pop_back();
        solve(i+1, nums, subs, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subs;
        solve(0, nums, subs, ans);
        return ans;
    }
};