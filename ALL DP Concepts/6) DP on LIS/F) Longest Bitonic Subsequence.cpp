//*****https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1*****


//T.C: O(2 * n * n) + O(n);
//S.C: O(2 * n);
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> front(n, 1);

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    front[i] = max(front[i], 1 + front[prev]);
                }
            }
        }
        
        vector<int> end(n, 1);
        
        for(int i = n-1; i >= 0; i--){
            for(int prev = n-1; prev > i; prev--){
                if(nums[prev] < nums[i]){
                    end[i] = max(end[i], 1 + end[prev]);
                }
            }
        }
        
        int maxi = 0;
        
        for(int i = 0; i < n; i++){
            if(front[i] > 1 && end[i] > 1) maxi = max(maxi, front[i] + end[i] - 1);
        }

        return maxi;
    }
};