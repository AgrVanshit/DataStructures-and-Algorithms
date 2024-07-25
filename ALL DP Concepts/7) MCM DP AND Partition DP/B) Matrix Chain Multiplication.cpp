//*****https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1*****


//****Tabulation****
//T.C: O(n * n * n);
//S.C: O(n * n);
class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for(int i = N-1; i >= 1; i--){
            for(int j = i+1; j < N; j++){
                int mini = 1e9;
        
                for(int k = i; k < j; k++){
                    int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini, steps);
                }
                
                dp[i][j] = mini;
            }
        }
        
        return dp[1][N-1];
    }
};