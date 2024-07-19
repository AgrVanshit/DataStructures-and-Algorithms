//*****https://www.geeksforgeeks.org/problems/longest-common-substring1452/1*****


//****Tabulation****
//T.C: O(n * m);
//S.C: O(2 * n * m);
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for(int j = 0; j<=m; j++) dp[0][j] = 0;
        for(int i = 0; i<=n; i++) dp[i][0] = 0;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(S1[i-1] == S2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
            }
        }
        
        int maxi = INT_MIN;
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                maxi = max(maxi, dp[i][j]);
            }
        }
        
        return maxi;
    }
};


//****Tabulation****
//IN ONE LOOP:
//T.C: O(n * m);
//S.C: O(n * m);
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for(int j = 0; j<=m; j++) dp[0][j] = 0;
        for(int i = 0; i<=n; i++) dp[i][0] = 0;
 
        int maxi = 0;
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(S1[i-1] == S2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxi = max(maxi, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        
        return maxi;
    }
};


//****2 Array Space Optimization****
//T.C: O(n * m);
//S.C: O(m);
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<int> prev(m+1, 0), curr(m+1, 0);
 
        int maxi = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(S1[i-1] == S2[j-1]){
                    curr[j] = 1 + prev[j-1];
                    maxi = max(maxi, curr[j]);
                }
                else curr[j] = 0;
            }
            
            prev = curr;
        }
        
        return maxi;
    }
};