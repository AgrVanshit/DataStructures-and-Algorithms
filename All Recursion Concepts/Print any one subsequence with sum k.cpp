//"PRINT ANY ONE" PATTERN IN RECURSION:
/*Technique to print any one answer: In the base case if the condition is satisfied return true, else return false. And also add true condition in the function call.*/


#include <bits/stdc++.h>
using namespace std;

bool printSubsequences(int ind, int s, vector<int>& ds, int k, int n, vector<int>& arr){
    if(ind == n){
        if(s == k){
            for(auto it : ds) cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    if(printSubsequences(ind + 1, s, ds, k, n, arr)) return true;

    ds.pop_back();
    s -= arr[ind];

    if(printSubsequences(ind + 1, s, ds, k, n, arr)) return true;

    return false;
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