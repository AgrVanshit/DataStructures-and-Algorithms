//*****https://leetcode.com/problems/longest-consecutive-sequence/description/*****


//Bruteforce Approach:
//T.C: O(n*n*n);
// S.C: O(1);
class Solution {
public:
    bool ls(vector<int>& nums, int x){
        for(auto it : nums){
            if(it == x) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int cnt = 1;
            while(ls(nums, x + 1) == true){
                x = x + 1;
                cnt++;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};


//Better Approach 1:
//T.C: O(n*log(n)) + O(n);
// S.C: O(1);
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 1, maxi = 1;
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]) continue;
            if(nums[i+1] - nums[i] == 1){
                cnt++;
                maxi = max(maxi, cnt);
            }
            else cnt = 1;
        }
        return maxi;
    }
};


//Better Approach 2:(Same intution as Better Approach: 1)
//T.C: O(n*log(n)) + O(n);
// S.C: O(1);
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 0, maxi = 1, lastSmaller = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] - 1 == lastSmaller){
                cnt++;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller){
                cnt = 1;
                lastSmaller = nums[i];
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};


//Optimal Approach:
//T.C: O(n) + O(2*n);
// S.C: O(n);
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi = 1, n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x + 1) != st.end()){
                    cnt = cnt + 1;
                    x = x + 1;
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};

