//https://leetcode.com/problems/combination-sum/description/


//T.C: O(2^t * K(K is Avg. length of combinations));
//S.C: O(K * x(x is no. of combinations));
class Solution {
public:
    void solve(int ind, int s, int target, vector<int>& ds, vector<int>& candidates, vector<vector<int>>& ans){
        int n = candidates.size();
        if(s > target) return;
        if(ind == n){
            if(s == target){
                ans.push_back(ds);
            }
            return;
        }

        ds.push_back(candidates[ind]);
        s += candidates[ind];

        solve(ind, s, target, ds, candidates, ans);

        ds.pop_back();
        s -= candidates[ind];

        solve(ind + 1, s, target, ds, candidates, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, 0, target, ds, candidates, ans);
        return ans;
    }
};