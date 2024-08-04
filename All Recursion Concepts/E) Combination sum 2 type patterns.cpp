//https://leetcode.com/problems/combination-sum-ii/description/
/*ONE OF THE RECURSION PATTERN IS TAKE/NOTTAKE WHICH WE USE IN "PRINT
  ALL SUBSEQUENCES" AND "COMBINATION ONE TYPE PROBLEMS" AND THE OTHER 
  RECURSION PATTERN IS THAT WE ARE USING IN THIS PROBLEM.*/

//T.C: O(2^N * K(K is Avg. length of combinations));
//S.C: O(K * x(x is no. of combinations));
class Solution {
public:
    void solve(int ind, int target, vector<int>& ds, vector<vector<int>>& ans, vector<int>& candidates, int n){
       if(target == 0){
           ans.push_back(ds);
           return;
       }

       for(int i = ind; i < n; i++){
           if(i > ind && candidates[i] == candidates[i-1]) continue;
           if(candidates[i] > target) break;

           ds.push_back(candidates[i]);
           solve(i+1, target-candidates[i], ds, ans, candidates, n);
           ds.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        int ind = 0;
        vector<int> ds;
        vector<vector<int>> ans;
        solve(ind, target, ds, ans, candidates, n);
        return ans;
    }
};