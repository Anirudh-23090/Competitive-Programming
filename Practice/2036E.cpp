#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector a(k, vector<i64>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            cin >> a[j][i];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < k; j++)
            a[j][i] |= a[j][i - 1];


    while (q--) {
        int m;
        cin >> m;
        int b = 0, u = n - 1;
        while (m--) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            r--;
            if (o == '<') {
                u = min(u, int(lower_bound(a[r].begin(), a[r].end(), c) - a[r].begin()) - 1);
            } else {
                b = max(b, int(upper_bound(a[r].begin(), a[r].end(), c) - a[r].begin()));
            }
            debug(b, u);
        }
        if (b <= u) {
            cout << b + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}