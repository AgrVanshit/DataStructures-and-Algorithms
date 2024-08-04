//https://www.geeksforgeeks.org/problems/subset-sums2234/1


//T.C: O(2^N);
//S.C: O(2^N);
class Solution {
  public:
    void solve(int ind, int s, int n, vector<int>& ans, vector<int>& arr){
        if(ind == n){
            ans.push_back(s);
            return;
        }
        
        s += arr[ind];
        solve(ind + 1, s, n, ans, arr);
        s -= arr[ind];
        
        solve(ind + 1, s, n, ans, arr);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        solve(0, 0, n, ans, arr);
        return ans;
    }
};


//Alternate:
class Solution {
  public:
    void solve(int ind, int s, int n, vector<int>& ans, vector<int>& arr){
        if(ind == n){
            ans.push_back(s);
            return;
        }
        
        solve(ind + 1, s + arr[ind], n, ans, arr);
        
        solve(ind + 1, s, n, ans, arr);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        solve(0, 0, n, ans, arr);
        return ans;
    }
};