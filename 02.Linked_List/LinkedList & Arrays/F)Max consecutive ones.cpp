//*****https://leetcode.com/problems/max-consecutive-ones/description/*****


//T.C: O(n); // n -> array's length.
//S.C: O(1);
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
                ans = max(cnt, ans);
            }
            else{
                cnt = 0;
            }
        }
        return ans;
    }
};