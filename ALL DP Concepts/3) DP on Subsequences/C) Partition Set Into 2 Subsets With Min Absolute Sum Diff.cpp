//*****https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1*****


//T.C: O(n * sum) + O(n);
//S.C: O(sum);
class Solution{
public:
	int minDifference(int arr[], int n)  {
	    int totsum = 0;
	    for(int i = 0; i < n; i++){
	        totsum += arr[i];
	    }
	    int sum = totsum;
	    
	    vector<bool>prev(sum+1, 0), cur(sum+1, 0);
        prev[0] = 1;
        cur[0] = 1;
        
        if(arr[0] <= sum) prev[arr[0]] = 1;
        
        for(int ind = 1; ind < n; ind++){
            for(int curr = 1; curr <= sum; curr++){
                bool pick = false;
                if(curr >= arr[ind]) pick = prev[curr - arr[ind]];
                bool npick = prev[curr];
                
                cur[curr] = (pick | npick);
            }
            prev = cur;
        }
        
	    int mini = 1e9;
	    for(int s = 0; s <= totsum/2; s++){
	        if(prev[s]){
	            mini = min(mini, abs(totsum - 2*s));
	        }
	    }
	    
	    return mini;
	} 
};