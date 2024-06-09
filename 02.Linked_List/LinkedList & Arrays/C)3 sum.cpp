//*****https://leetcode.com/problems/3sum/description/*****


//Bruteforce Approach 1:
//T.C: O(n*n*n) + O(log(no. of unique triplets));
//S.C: 2 * O(no of unique triplets);
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> temp;
        for(int i = 0; i < n; i++){
            temp.push_back(nums[i]);
            for(int j = i + 1; j < n; j++){
                temp.push_back(nums[j]);
                for(int k = j + 1; k < n; k++){
                    temp.push_back(nums[k]);
                    vector<int> v = temp;
                    sort(v.begin(), v.end());
                    if(nums[i] + nums[j] + nums[k] == 0 && st.count(v) == 0){
                        ans.push_back(temp);
                    }
                    st.insert(v);
                    temp.pop_back();
                }
                temp.pop_back();
            }
            temp.pop_back();
        }
        return ans;
    }
};


//Bruteforce Approach 2:
//T.C: O(n*n*n) + O(log(no. of unique triplets));
//S.C: 2 * O(no of unique triplets);
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();

        // check all possible triplets:
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        //store the set elements in the answer:
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


//Better Approach:
/*T.C: O(n*n*log(m)); -> log(m) due to storing in hashset
                         if we use unordered set then it 
                         will not come. */
//S.C: O(n) + 2* O(no. of unique triplets);
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            set<int> hashset;
            for (int j = i + 1; j < n; j++) {
                //Calculate the 3rd element:
                int third = -(nums[i] + nums[j]);

                //Find the element in the set:
                if (hashset.find(third) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }

        //store the set in the answer:
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


//Optimal Approach :
//T.C: O(n*log(n)) + O(n*n);
//S.C: O(no. of unique triplets) for "ans" array;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            //don't do again for same i:
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            //moving 2 pointers:
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    //skip the duplicates:
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};