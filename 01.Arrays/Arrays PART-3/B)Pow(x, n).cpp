//*****https://leetcode.com/problems/powx-n/description/*****


//Bruteforce Approach:(TLE)
//T.C: O(n);
//S.C: O(1);
// class Solution {
// public:
//     double myPow(double x, int n) {
//         int m = n;
//         double ans = 1;
//         n = abs(n);
//         for(int i = 0; i < n; i++){
//             ans *= x;
//         }
//         if(m < 0) ans = 1.0/ans;
//         return ans;
//     }
// };


//Optimal Approach:
//T.C: O(logn);
//S.C: O(1);
class Solution {
public:
    double myPow(double x, int n) {
        long long m = n; // for the case of n = INT_MIN take long long.
        double ans = 1.0;
        n = abs(n);
        while(n > 0){
            if(n%2 == 1){
                n = n-1;
                ans = ans * x;
            }
            else{
                n = n/2;
                x = x*x;
            }
        }
        if(m < 0) return 1.0/ans;
        return ans;
    }
};