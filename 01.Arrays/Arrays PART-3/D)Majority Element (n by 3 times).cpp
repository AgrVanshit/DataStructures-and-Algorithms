//*****https://leetcode.com/problems/majority-element-ii/description/*****


//Bruteforce Approach:
//T.C: O(n*n);
//S.C: O(1);
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(ans.empty() || ans[0] != nums[i]){
                int cnt = 0;
                for(int j = 0; j < n; j++){
                    if(nums[j] == nums[i]){
                        cnt++;
                    }
                }
                if(cnt > n/3) ans.push_back(nums[i]);
            }
            /*There can not be more than two majority(>n/3)
              elements in an array.*/
            if(ans.size() == 2) break;
        }
        return ans;
    }
};


//Better Approach 1:
//T.C: O(2*n);
//S.C: O(n);
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second>(n/3)){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};


//Better Approach 2:
//T.C: O(n);
//S.C: O(n);
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        int n = nums.size();
        int num = n/3 + 1;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] == num) ans.push_back(nums[i]);
            if(ans.size() == 2) break;
        }
        return ans;
    }
};


//Optimal Approach:
//T.C: O(2*n);
//S.C: O(1);
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;

        // Applying the Extended Boyer Moore's Voting Algorithm:
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1) cnt1++;
            else if (nums[i] == el2) cnt2++;
            else {
                cnt1--, cnt2--;
            }
        }

        vector<int> ans;

        /* Manually check if the stored elements in 
           el1 and el2 are the majority elements: */
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) cnt1++;
            if (nums[i] == el2) cnt2++;
        }

        int mini = int(n / 3) + 1;
        if (cnt1 >= mini) ans.push_back(el1);
        if (cnt2 >= mini) ans.push_back(el2);

        // if it is told to sort the answer array:
        // sort(ans.begin(), ans.end()); //TC --> O(2*log2) ~ O(1);

        return ans;
    }
};