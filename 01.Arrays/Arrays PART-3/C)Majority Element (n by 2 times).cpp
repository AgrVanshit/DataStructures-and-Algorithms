//https://leetcode.com/problems/majority-element/description/


//Bruteforce Approach:
//T.C: O(n*n);
//S.C: O(1);
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] == nums[i]) cnt++;
            }
            if(cnt > n/2) return nums[i];
        }
        return -1;
    }
};


//Better Approach:
//T.C: O(2*n);
//S.C: O(n);
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second>(n/2)){
                return it.first;
            }
        }
        return -1;
    }
};


//Optimal Approach:
//T.C: O(n);
//S.C: O(1);
//****MOORE'S VOTING ALGORITHM:****
/*If there is a majority element, it will
  ultimately emerge as the winner.*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int el;

        //Applying the algorithm:
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            }
            else if (el == nums[i]) cnt++;
            else cnt--;
        }

        /*checking if the stored element is the majority 
          element: (If ques states that majority element 
          always exist then no need to check, directly 
          return "el") */
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) cnt1++;
        }

        if (cnt1 > (n / 2)) return el;
        return -1;
    }
};