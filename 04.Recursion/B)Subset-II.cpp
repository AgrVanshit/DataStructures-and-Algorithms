//*****https://leetcode.com/problems/subsets-ii/description/*****


class Solution {
public:
    void solve(int ind, vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums, int n){
        if(ind == n){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[ind]);
        solve(ind + 1, ds, ans, nums, n);
        ds.pop_back();
        solve(ind + 1, ds, ans, nums, n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;
        set<vector<int>> st;
        vector<vector<int>> ansSubmit;

        solve(0, ds, ans, nums, n);

        for(auto it : ans){
            st.insert(it);
        }
        for(auto it : st){
            ansSubmit.push_back(it);
        }

        return ansSubmit;
    }
};


//****Approach 2****
//T.C: O(2^N * K);
//S.C: O(2^N * K) + O(N);
class Solution {
public:
    void solve(int ind, int n, vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums){
        ans.push_back(ds);

        for(int i = ind; i < n; i++){
            if(i > ind && nums[i] == nums[i-1]) continue;

            ds.push_back(nums[i]);
            solve(i+1, n, ds, ans, nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, n, ds, ans, nums);
        return ans;
    }
};