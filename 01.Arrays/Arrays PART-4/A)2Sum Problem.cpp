//*****https://leetcode.com/problems/two-sum/description/*****


//Bruteforce Approach 1:
//T.C: O(n*n);
//S.C: O(1);
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if(i == j) continue;
                if (nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }
        return {};
    }
};


//Bruteforce Approach 2:
//T.C: O(n*n);
//S.C: O(1);
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }
        return {};
    }
};


//Optimal Approach:
//T.C: O(n*log(n));
//S.C: O(n);
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n = nums.size();
       unordered_map<int, int> mp;
       for(int i = 0; i < n; i++){
        int num1 = nums[i];
        int num2 = target - nums[i];
        if(mp.find(num2) != mp.end()){
            return {mp[num2], i};
        }
        mp[num1] = i;
       }
       return {};
    }
};


/*NOTE: If the ques just ask to return "true" OR "false" if 
        such two elements exists or not, we can sort the
        array and apply two pointer approach.

        //T.C: O(n*log(n)) + O(n);
        //S.C: O(1);
        bool twoSum(int n, vector<int> &arr, int target) {
            sort(arr.begin(), arr.end());
            int left = 0, right = n - 1;
            while (left < right) {
                int sum = arr[left] + arr[right];
                if (sum == target){
                    return true;
                }
                else if (sum < target) left++;
                else right--;
            }
            return false;
        }   
*/        