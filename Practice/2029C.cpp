#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

constexpr int INF = 1E9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<array<int, 3>> dp(n + 1);
    int rating = 0; dp[0][0] = 0, dp[0][1] = -INF, dp[0][2] = -INF;

    auto update = [&] (int& x, int i) {
        i--;
        if (a[i] > x) {
            x++;
        } else if (a[i] < x) {
            x--;
        }
        return x;
    };

    for (int i = 1; i <= n; i++) {
        int r = rating, x = dp[i - 1][1], y = dp[i - 1][2];
        update(rating, i), update(x, i), update(y, i);
        dp[i][0] = rating;
        dp[i][1] = max(r, dp[i - 1][1]);
        dp[i][2] = max(x, y);
    }

    debug(dp);

    int ans = max({dp[n][1], dp[n][2]});
    cout << ans << endl;
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