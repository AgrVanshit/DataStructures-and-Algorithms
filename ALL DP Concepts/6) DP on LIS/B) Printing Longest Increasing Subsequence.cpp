//*****https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1*****


//T.C: O(n * n) + O(LIS length);
//S.C: O(2 * n);
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastInd = 0;
        
        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int prev = 0; prev < i; prev++){
                if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastInd = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastInd]);
        
        while(hash[lastInd] != lastInd){
            lastInd = hash[lastInd];
            temp.push_back(arr[lastInd]);
        }
        
        reverse(temp.begin(), temp.end());

        return temp;
    }
};