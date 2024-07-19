//*****https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/*****


//****Tabulation****
//T.C: O(n * n) + O(n);
//S.C: O(n * n);
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[n][m];
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());

        return longestCommonSubsequence(s, t);
    }

    int minInsertions(string s) {
        int n = s.size();
        return n - longestPalindromeSubseq(s);
    }
};


//****2 Array Space Optimization****
//T.C: O(n * n) + O(n);
//S.C: O(n);
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }

            prev = curr;
        }
        
        return prev[m];
    }
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());

        return longestCommonSubsequence(s, t);
    }

    int minInsertions(string s) {
        int n = s.size();
        return n - longestPalindromeSubseq(s);
    }
};