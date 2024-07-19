//*****https://leetcode.com/problems/delete-operation-for-two-strings/description/*****


//****Tabulation****
//T.C: O(n * m);
//S.C: O(n * m);
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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        return m + n - 2*longestCommonSubsequence(word1, word2);
    }
};


//****2 Array Space Optimization****
//T.C: O(n * m);
//S.C: O(m);
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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        return m + n - 2*longestCommonSubsequence(word1, word2);
    }
};