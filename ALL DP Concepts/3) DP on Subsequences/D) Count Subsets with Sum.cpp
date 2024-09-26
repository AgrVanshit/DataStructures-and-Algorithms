//*****https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1*****


//****Recursion and Memoization****
//T.C: O(n*sum);
//S.C: O(n*sum) + O(n);
class Solution{
public:
	int mod = (int)1e9 + 7;
	int solve(int i, int arr[], int currsum, vector<vector<int>>& dp){
      if(i==0){
        if(currsum==0 && arr[0]==0) return 2;
        if(currsum==0 || arr[0]==currsum) return 1;
        else return 0;
      }	   
      /* if(currsum == 0) return 1;//can't add this case because arrays has zero
        also we are missing additional subsets that can be made by addind zeroes 
        in the already made subset with the target sum....*/
      
      if(dp[i][currsum] != -1) return dp[i][currsum] % mod;
        
	    int pick = 0;
	    if(currsum >= arr[i]) pick = solve(i-1, arr, currsum - arr[i], dp) % mod;
	    int npick = solve(i-1, arr, currsum, dp) % mod;
	    
	    return dp[i][currsum] = (pick + npick)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return solve(n-1, arr, sum, dp) % mod;
	}
};


//****Tabulation****
//T.C: O(n * sum);
//S.C: O(n * sum);
class Solution{
public:
	int mod = (int)1e9 + 7;
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>>dp(n, vector<int>(sum+1, 0));
        
        if(arr[0] <= sum) dp[0][arr[0]] = 1; 
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        
        for(int i = 1; i < n; i++){
            for(int currsum = 0; currsum <= sum; currsum++){
                int pick = 0;
        	    if(currsum >= arr[i]) pick = dp[i-1][currsum-arr[i]] % mod;

        	    int npick = dp[i-1][currsum] % mod;
        	    
        	    dp[i][currsum] = (pick + npick)%mod;
            }
        }
        
        return dp[n-1][sum];
	}
};


//****Space Optimization****
//T.C: O(n * sum);
//S.C: O(sum);
class Solution{
public:
	int mod = (int)1e9 + 7;
	int perfectSum(int arr[], int n, int sum)
	{
        vector<int>prev(sum+1, 0), curr(sum+1, 0);
        
        if(arr[0] <= sum) prev[arr[0]] = 1; 
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        
        for(int i = 1; i < n; i++){
            for(int currsum = 0; currsum <= sum; currsum++){
                int pick = 0;
        	    if(currsum >= arr[i]) pick = prev[currsum-arr[i]] % mod;

        	    int npick = prev[currsum] % mod;
        	    
        	    curr[currsum] = (pick + npick)%mod;
            }
            prev = curr;
        }
        
        return prev[sum];
	}
};