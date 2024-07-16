//*****https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1*****


//****Space Optimization****
//T.C: O(n) + (n * sum);
//S.C: O(sum);
class Solution {
  public:
    int mod = 1e9+7;
    int count(vector<int>& arr, int n, int sum)
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
        
        return prev[sum] % mod;
	}

    int countPartitions(int n, int d, vector<int>& arr) {
        int totsum = 0;
	    for(int i = 0; i < n; i++){
	        totsum += arr[i];
	    }
	    
	    if(totsum - d < 0 || (totsum-d) % 2) return false;
	    
	    return count(arr, n, (totsum-d)/2);
    }
};