//*****https://leetcode.com/problems/find-the-duplicate-number/description/*****


//Bruteforce Approach:(Modifying given array)
//T.C: O(nlogn) + O(n);
//S.C: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]) return nums[i];
        }
        return -1;
    }
};


//Better Approach:
//T.C: O(n)
//S.C: O(n) and without modifying array.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == 2) return nums[i];
        }
        return -1;
    }
};


//Optimised Approach:
//T.C: O(n)
//S.C: O(1) and without modifying array.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while(slow != fast){
            //moving slow pointer by one step.
            slow = nums[slow];
            //moving fast pointer by two steps.
            fast = nums[nums[fast]];
        }
        //at this point slow and fast pointer are at same point.

        //taking slow pointer to the first element.
        slow = nums[0];
        
        /*moving slow and fast pointer one one step untill they meet,
          the point where they meet is the connection point of the 
          cycle, that connection point is the element that occurs twice
          in an array. */
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};