//*****https://leetcode.com/problems/longest-substring-without-repeating-characters/description/*****


//Bruteforce Approach :
//T.C: O(n*n);
//S.C: O(n);
/* This approach includes forming all substrings using
   two loops and then checking each substring individually
    wether the repeating character is present or not, and 
    returning longest substring without repeating character.
*/


//Better Approach 1:
//T.C: O(2*n);
//S.C: O(n);
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int mp[256] = {0};
        int maxi = 0;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            if(mp[s[j]] == 1){
                maxi = max(maxi, j-i+1);
            }
            j++;
        }
        return maxi;
    }
};


//Better Approach 2:
//T.C: O(2*n);
//S.C: O(n);
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int maxi = 0;
        unordered_map<char, int> mp;
        while(j < n){
            mp[s[j]]++;
            // if(mp.size() < k) j++;
            if(mp.size() == j-i+1){
                maxi = max(maxi, j-i+1);
            }
            while(mp.size() < j-i+1){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return maxi;
    }
};


//Optimal Approach:
//T.C: O(n);
//S.C: O(n);
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector < int > mpp(256, -1);
        int left = 0, right = 0;
        int n = s.size();
        int len = 0;
        while (right < n) {
            if (mpp[s[right]] != -1){
                left = max(mpp[s[right]] + 1, left);
            }
            mpp[s[right]] = right;

            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};