//*****https://leetcode.com/problems/set-mismatch/description/*****


//Bruteforce Approach:
//T.C: O(n*n);
//S.C: O(1);
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int missing = -1, repeating = -1;
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] == i) cnt++;
            }
            if(cnt == 2) repeating = i;
            if(cnt == 0) missing = i;
            if(repeating != -1 && missing != -1) break;
        }
        return {repeating, missing};
    }
};


//Better Approach:
//T.C: O(2*n);
//S.C: O(n);
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; i++){
            mp[i] = 0;
        }
        for(auto it : nums){
            mp[it]++;
        }
        int dupli, missing;
        for(int i = 1; i <= n; i++){
            if(mp[i] == 2) dupli = i;
            if(mp[i] == 0) missing = i;
        }
        return {dupli, missing};
    }
};




// Optimal Approach 1:
// T.C: O(2*n);
// S.C: O(1);
class Solution {
public:
  /*This technique is used in various problems where it is given
    that the elements in the array are from 1 to n, here we are 
    marking the index as neg, this ind is equal to the element on
    which we are at, and if while markind we reach on an element 
    that is already negative means the element equivalent to its 
    index on which it is present is the array and hence is duplicate,
    if any of the element remains non negative after iteration, means
    value equals to its index is not present in an array and hence is
    missing */
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dupli, missing;
        for(int i = 0; i < n; i++){
            int ind = abs(nums[i]) - 1;
            if(nums[ind] < 0){
                dupli = ind + 1;
            }
            else nums[ind] *= -1;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) missing=i+1;
        }
        return {dupli, missing};
    }
};


// Optimal Approach 2:(Using Maths)
// T.C: O(n);
// S.C: O(1);
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size(); // size of the array

        // Find Sn and S2n:
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        // Calculate S and S2:
        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }

        //S-Sn = X-Y:  //X -> Duplicate, Y -> Missing
        long long val1 = S - SN;

        // S2-S2n = X^2-Y^2:
        long long val2 = S2 - S2N;

        //Find X+Y = (X^2-Y^2)/(X-Y):
        val2 = val2 / val1;

        //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
        // Here, X-Y = val1 and X+Y = val2:
        long long X = (val1 + val2) / 2;
        long long Y = X - val1;

        return {(int)X, (int)Y};
    }
};


// Optimal Approach 3:(Using XOR)
// T.C: O();
// S.C: O();
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //To be done....
    }
};
