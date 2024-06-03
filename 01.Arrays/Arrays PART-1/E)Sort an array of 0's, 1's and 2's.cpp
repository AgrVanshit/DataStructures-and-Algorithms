//*****https://leetcode.com/problems/sort-colors/description/*****


//Bruteforce Approach:
//Use any sorting algorithm(Merge sort -> T.C: O(nlogn), S.C: O(n));
//OR use sort(nums.begin(), nums.end());


//Better Solution:
//T.C: O(2*n);
// S.C: O(1);
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        for(auto &it : nums){
            if(it == 0) cnt0++;
            if(it == 1) cnt1++;
            if(it == 2) cnt2++;
        }

        for(int i = 0; i < cnt0; i++) nums[i] = 0;
        for(int i = cnt0; i < cnt0 + cnt1; i++) nums[i] = 1;
        for(int i = cnt0 + cnt1; i < cnt0 + cnt1 + cnt2; i++) nums[i] = 2;
    }
};


//Optimized Approach:
//T.C: O(n);
//S.C: O(1);
//****DUTCH NATIONAL FLAG ALGORITHM:****
/* 0 to low-1  ->  0's
   low to mid-1  ->  1's
   mid to high  ->  non sorted
   high+1 to n-1  ->  2's
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0, mid = 0, high = nums.size()-1;

        while(mid<=high){

            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }

            else if(nums[mid]==1){
                mid++;
            }

            else{
                swap(nums[mid],nums[high]);
                high--;
            }

        }
    }
};
