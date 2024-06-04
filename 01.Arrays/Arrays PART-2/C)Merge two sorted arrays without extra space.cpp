//*****https://leetcode.com/problems/merge-sorted-array/description/*****


//Bruteforce Approach:
//T.C: O(m+n);
//S.C: O(m+n);
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> dummy = nums1;
        int cnt = 0;
        while(i != m && j != n){
            if(dummy[i] <= nums2[j]){
                nums1[cnt] = dummy[i];
                i++;
            }
            else{
                nums1[cnt] = nums2[j];
                j++;
            }
            cnt++;
        }
        while(i != m){
            nums1[cnt] = dummy[i];
            i++;
            cnt++;
        }
        while(j != n){
            nums1[cnt] = nums2[j];
            j++;
            cnt++;
        }
    }
};


//Optimal Approach 1:
//T.C: O(n) + O((m+n)log(m+n));
//S.C: O(1);
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m; i < m+n; i++){
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin(), nums1.end());
    }
};


//Optimal Approach 2:
// T.C: O((n+m)log(n+m)) + O(n);
//S.C: O(1);
//****GAP METHOD****
class Solution {
public:
    void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2){
        if(arr1[ind1] > arr2[ind2]) swap(arr1[ind1], arr2[ind2]);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        int gap = len/2 + (len%2); //ceil(double(len)/2)
        while(gap > 0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                // arr1 and arr2
                if(left < m && right >= m){
                    swapIfGreater(nums1, nums2, left, right-m);
                }
                //arr2 and arr2
                else if(left >= m){
                    swapIfGreater(nums2, nums2, left-m, right-m);
                }
                //arr1 and arr1
                else{
                    swapIfGreater(nums1, nums1, left, right);
                }
                left++;
                right++;
            }
            if(gap == 1) break;
            gap = gap/2 + (gap%2);
        }
        //copying nums2 at the end of nums1.
        for(int i = m; i < m + n; i++){
            nums1[i] = nums2[i-m];
        }
    }
};
