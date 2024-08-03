//*****https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/*****
//PRINT ALL PATTERN IN RECURSION:


#include <bits/stdc++.h>
using namespace std;

void printSubsequences(int ind, int s, vector<int>& ds, int k, int n, vector<int>& arr){
    if(ind == n){
        if(s == k){
            for(auto it : ds) cout << it << " ";
            cout << endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    printSubsequences(ind + 1, s, ds, k, n, arr);

    ds.pop_back();
    s -= arr[ind];

    printSubsequences(ind + 1, s, ds, k, n, arr);
}
void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> ds;
    printSubsequences(0, 0, ds, k, n, arr);
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


//"COUNT All" PATTERN IN RECURSION:
/*return 1(if condition satisfied) or 0(if condition not satisfied) in the 
  base case, and return sum of all functional calls in the main recursive function.*/