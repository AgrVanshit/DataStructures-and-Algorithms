//*****https://leetcode.com/problems/climbing-stairs/description/*****


/* 
Steps for writing Recurrence in any problem:
1) Try to represent a problem in terms of index.
2) Do all possible stuffs on that index according to the problem statement.
3) Sum -> count all ways.
   min/max -> count min/max.
*/

//****CODE:****

//Memoization:
class Solution {
public:
    // int climbStairs(int n) {
    //     if(n==0 || n==1) return 1;
    //     int l=climbStairs(n-1);
    //     int r=climbStairs(n-2);
    //     return l+r;
    // }
    
    int solve(int n, vector<int>& dp){
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n] != -1) return dp[n];

        return dp[n]=solve(n-1, dp)+ solve(n-2, dp);
    }

    int climbStairs(int n){
        vector<int> dp(n+1,-1);

        int ans=solve(n, dp);
        return ans;

    }
};


//Tabulation:
class Solution {
public:
    int climbStairs(int n){
        vector<int> dp(n+1);
        
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};


//Space Optimization Approach:
class Solution {
public:
    int climbStairs(int n){
        int prev = 1;
        int prev2 = 1;

        for(int i = 2; i <= n; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};