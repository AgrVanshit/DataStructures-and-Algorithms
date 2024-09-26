#include <bits/stdc++.h>
using namespace std;

int M = 1e9 + 7;

void solve() {
    long long n;
    cin >> n;

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= 6; j++) {
            if (i >= j) {
                dp[i] = (dp[i] + dp[i - j]) % M;
            }
        }
    }

    cout << dp[n] % M << endl;
}

int main() {
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
