//*****https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1*****


//Bruteforce Approach:
//(Also valid if negatives present)
//T.C: O(n*n*n);
//S.C: O(1);
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum = 0;
                for(int t = i; t <= j; t++){
                    sum += arr[t];
                }
                if(sum == k) maxi = max(maxi, j-i+1);
            }
        }
        return maxi;
    } 
};


//Bruteforce Approach (optimised):
//(Also valid if negatives present)
//T.C: O(n*n);
//S.C: O(1);
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        int maxi = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += arr[j];
                if(sum == k) maxi = max(maxi, j-i+1);
            }
        }
        return maxi;
    } 
};


/*Better Approach: Better if only positives and zeroes present,
                   it is optimal Approach if negatives are present */
//T.C: O(n*log(n)) if ordered map is used;
//T.C: O(n*1) if unordered map is used (in avg and best case);
//T.C: O(n*n) if unordered map is used (in worst case);
//S.C: O(n);
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        map<long long, int> mp; //map storing presum
        long long sum = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == k){
                maxi = max(maxi, i+1);
            }
            long long rem = sum - k;
            if(mp.find(rem) != mp.end()){
                int len = i - mp[rem];
                maxi = max(maxi, len);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        return maxi;
    } 
};


//Optimal Approach:(Valid only if array has no negatives)
//Sliding Window Approach:
//T.C: O(2*n);
//S.C: O(1);
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    {
        int i = 0, j = 0;
        long long sum = 0;
        int maxi = INT_MIN;
        while(j < n){
            sum += arr[j];
            while(i <= j && sum > k) sum -= arr[i++];
            if(sum == k){
                maxi = max(maxi, j-i+1);
            }
            j++;
        }
        return maxi; 
    } 
};