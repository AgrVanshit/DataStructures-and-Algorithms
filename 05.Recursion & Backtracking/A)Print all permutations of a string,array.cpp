//*****https://leetcode.com/problems/permutations/description/*****
//VALID IF ARRAY CONTAINS ALL UNIQUE ELEMENTS(i.e ALL PERMUTATIONS WE GET ARE UNIQUE).
/*IN CASE ID ARRAY CONTAINS DUPLICATE ELEMENTS ANS QUESTION ASKS TO RETURN UNIQUE 
  PERMUTATIONS THEN WE WILL REMOVE DUPLICATES BEFORE RETURNING THE ANS.*/


//APPROACH: 1
//T.C: O(n! * n);
//S.C: O(n!) + O(3*n);// n! for "ans" array, 2*n for "freq" and "ds" arrays, and n for recursive stack space.
class Solution {
public:
    void solve(int n, vector<int>& nums, vector<int>& ds, vector<int>& freq, vector<vector<int>>& ans){
        if(ds.size() == n){
            ans.push_back(ds);
        }

        for(int i = 0; i < n; i++){
            if(!freq[i]){
                freq[i] = 1;
                ds.push_back(nums[i]);
                solve(n, nums, ds, freq, ans);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<int> ds;
        vector<vector<int>> ans;
        vector<int> freq(n, 0);

        solve(n, nums, ds, freq, ans);

        return ans;
    }
};


//APPROACH: 2
//SWAPPING TECHNIQUE:
//T.C: O(n! * n);
//S.C: O(n!) + O(n);
class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<vector<int>>& ans){
        int n = nums.size();

        if(ind == n){
            ans.push_back(nums);
            return;
        }

        for(int i = ind; i < n; i++){
            swap(nums[ind], nums[i]);
            solve(ind + 1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        solve(0, nums, ans);

        return ans;
    }
};