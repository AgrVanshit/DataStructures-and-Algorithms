//*****https://leetcode.com/problems/longest-string-chain/description/*****


//T.C: O(n * n * L) + O(log(n));
//S.C: O(n);
class Solution {
private:
    bool checkPossible(string& s1, string& s2){
        if(s1.size() - s2.size() != 1) return false;

        int first = 0, second = 0;

        while(first != s1.size()){
            if(s1[first] == s2[second] && second < s2.size()){
                first++;
                second++;
            }
            else{
                first++;
            }
        }

        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }
    void sort(vector<string>& s, int n){
        for (int i=1 ;i<n; i++){
            string temp = s[i];
    
            // Insert s[j] at its correct position
            int j = i - 1;

            while (j >= 0 && temp.length() < s[j].length()){
                s[j+1] = s[j];
                j--;
            }

            s[j+1] = temp;
        }
    }
    // bool compare(string &s1,string &s2){
    //     return s1.size() < s2.size();
    // }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words,n);
        // sort(words.begin(), words.end(), compare);

        vector<int> dp(n, 1);
        int maxi = -1;

        for(int i = 0; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(checkPossible(words[i], words[prev]) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }
            if(dp[i] > maxi){
              maxi = dp[i];
            }
        }

        return maxi;
    }
};