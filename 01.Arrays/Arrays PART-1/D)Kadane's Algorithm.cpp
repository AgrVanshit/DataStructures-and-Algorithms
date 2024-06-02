//*****https://leetcode.com/problems/maximum-subarray/description/*****

//Bruteforce Approach:
//T.C: O(n*n*n);
//S.C: O(1);
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum = 0;
                for(int k = i; k <= j; k++){
                    sum += nums[k];
                }
                maxi = max(sum, maxi);
            }
        }
        return maxi;
    }
};


//Better Approach:
//T.C: O(n*n);
//S.C: O(1);
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                maxi = max(sum, maxi);
            }
        }
        return maxi;
    }
};


//Optimised Approach:
//T.C: O(n);
//S.C: O(1);
//****KADANE'S ALGORITHM:****
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        // int start = -1, ansStart = -1, ansEnd = -1;
        for(int i = 0; i < n; i++){
            // if(sum == 0) start = i;
            sum += nums[i];
            if(sum > maxi){
                maxi = sum;
                // ansStart = start;
                // ansEnd = i;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};