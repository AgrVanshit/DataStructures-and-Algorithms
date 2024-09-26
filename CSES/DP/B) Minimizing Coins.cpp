#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(x+1, 0));

        for(int T = 0; T <= x; T++){
            if(T % arr[0] == 0) dp[0][T] = T/arr[0];
            else dp[0][T] = 1e9;
        }

        for(int ind = 1; ind < n; ind++){
            for(int T = 0; T <= x; T++){
                int nottake = 0 + dp[ind - 1][T];

                int take = INT_MAX;
                if(arr[ind] <= T) take = 1 + dp[ind][T-arr[ind]];

                dp[ind][T] = min(take, nottake);
            }
        }
        
        if(dp[n-1][x] >= 1e9) cout << -1;
        else cout << dp[n-1][x];
}

int main() {
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
