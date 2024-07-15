//*****https://www.geeksforgeeks.org/problems/geeks-training/1*****


//****Memoization****
//T.C = O(N * 4) * 3;
//S.C = O(N) + O(N * 4);
class Solution {
  public:
    int solve(int ind, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
        
        if(ind == 0){
            int maxi = 0;
            for(int i = 0; i < 3; i++){
                if(i != last) maxi = max(maxi, points[0][i]);
            }
            return maxi;
        }
        
        if(dp[ind][last] != -1) return dp[ind][last];
        
        int maxi = 0;
        
        for(int i = 0; i < 3; i++){
            if(i != last){
                int point = points[ind][i] + solve(ind - 1, i, points, dp);
                maxi = max(maxi, point);
            }
        }
        
        return dp[ind][last] = maxi;
        
    } 
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>dp(n, vector<int>(4, -1));

        return solve(n-1, 3, points, dp);
    }
};


//****Tabulation****
//T.C = O(N * 4) * 3;
//S.C = O(N * 4);
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>dp(n, vector<int>(4));
        
        // dp[0][0] = max(points[0][1], points[0][2]);
        // dp[0][1] = max(points[0][0], points[0][2]);
        // dp[0][2] = max(points[0][0], points[0][1]);
        // dp[0][3] = max(max(points[0][0], points[0][1]), points[0][2]);
        
        for(int last = 0; last < 4; last++){
            int maxi = 0;
            for(int i = 0; i < 3; i++){
                if(i != last) maxi = max(maxi, points[0][i]);
            }
            dp[0][last] = maxi;
        }
        
        for(int ind = 1; ind < n; ind++){
            for(int last = 0; last < 4; last++){
                int maxi = 0;
                for(int i = 0; i < 3; i++){
                    if(i != last){
                        int point = points[ind][i] + dp[ind-1][i];
                        maxi = max(maxi, point);
                    }
                }
                dp[ind][last] = maxi;
            }
        }
        
        return dp[n-1][3];
    }
};


//****Space Optimization****
//T.C = O(N * 4) * 3;
//S.C = O(4);
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<int>prev(4);
        
        for(int last = 0; last < 4; last++){
            int maxi = 0;
            for(int i = 0; i < 3; i++){
                if(i != last) maxi = max(maxi, points[0][i]);
            }
            prev[last] = maxi;
        }
        
        for(int ind = 1; ind < n; ind++){
            vector<int> temp(4);
            
            for(int last = 0; last < 4; last++){
                int maxi = 0;
                for(int i = 0; i < 3; i++){
                    if(i != last){
                        int point = points[ind][i] + prev[i];
                        maxi = max(maxi, point);
                    }
                }
                
                temp[last] = maxi;
            }
            
            prev = temp;
        }
        
        return prev[3];
    }
};