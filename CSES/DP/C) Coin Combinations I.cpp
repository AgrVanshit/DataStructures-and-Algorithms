#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int sum = 1; sum <= x; sum++) {
        for (int i = 0; i < n; i++) {
            if (sum >= coins[i]) {
                dp[sum] = (dp[sum] + dp[sum - coins[i]]) % M;
            }
        }
    }
    
    cout << dp[x] << endl;
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
