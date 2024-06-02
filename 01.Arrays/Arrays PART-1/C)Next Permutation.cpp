//*****https://leetcode.com/problems/next-permutation/description/*****

//Bruteforce Approach:
// T.C: O(n * n!);
// Steps: 1)Generate all Permutations in sorted order.
//        2)Find given permutation.
//        3)Return its next permutation(next index)


//Better Approach:
//Using STL function: next_permutation(arr.begin(), arr.end());


//Optimized Approach:(Longest prefix match pattern)
//T.C: O(3*n);
//S.C: O(1) (But we are modifying the given array so we can also say O(n));
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),
        int ind = -1;
        //Iterating from the back and finding first element smaller than its next element, before that element all the elements from index 0 to that index will match with the next permutation.
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[ind],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
    }
};