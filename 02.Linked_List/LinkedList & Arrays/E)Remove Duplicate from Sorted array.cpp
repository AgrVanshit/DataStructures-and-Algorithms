//*****https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/*****


//Bruteforce Approach:
/*T.C: O(n*log(n)) + O(n); -> log(n) with n is for inserting 
                              each value in set.*/
//S.C: O(n);
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        int ind = 0;
        for(auto it : st){
            nums[ind] = it;
            ind++;
        }
        return ind;
    }
};


//Optimal Approach:
//T.C: O(n); // n -> array's length.
//S.C: O(1);
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int left = 0;
        for(int right = 1; right < nums.size(); right++){
           if(nums[left] != nums[right]){
               left++;
               nums[left] = nums[right];
           }
        }
        return left+1;
    }
};