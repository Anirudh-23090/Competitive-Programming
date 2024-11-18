#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
        i64 sum = 0;
        for (int j = 0, k = 0; j < n; sum -= a[j++]) {
            while (k < n && sum + a[k] <= b[i]) {
                sum += a[k++];
            }
            if (dp[j] != -1) {
                if (dp[k] == -1) {
                    dp[k] = dp[j] + (m - i - 1);
                } else {
                    dp[k] = min(dp[k], dp[j] + (m - i - 1));
                }
            }
        }
    }

    debug(dp);
    cout << dp[n] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--)
        solve();
    
    return 0;
}