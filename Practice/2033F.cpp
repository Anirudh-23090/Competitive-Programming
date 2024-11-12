#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const int P = 1E9 + 7;

void solve() {
    i64 n, k;
    cin >> n >> k;

    int a = 0 % k, b = 1 % k, l = 0;
    while (b) {
        tie(a, b) = pair(b, (a + b) % k);
        l++;
    }

    cout << ((n % P) * (l + 1)) % P << endl;
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