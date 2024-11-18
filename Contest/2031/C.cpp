#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n;
    cin >> n;

    if (n <= 4) {
        cout << -1 << endl;
        return;
    }

    for (int i = 2; i <= n; i += 2) {
        if (i != 4) {
            cout << i << ' ';
        }
    }
    cout << 4 << ' ';
    cout << 5 << ' ';
    for (int i = 1; i <= n; i += 2) {
        if (i != 5) {
            cout << i << ' ';
        }
    }
    cout << endl;
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