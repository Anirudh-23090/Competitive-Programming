#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int k;
    cin >> k;

    vector<int> a(k), cnt(k + 1);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 1; i <= k; i++) {
        if (((k - 2) % i) == 0 && cnt[i]) {
            cnt[i]--;
            if (cnt[(k - 2) / i]) {
                cout << i << ' ' << (k - 2) / i << endl;
                return;
            }
            cnt[i]++;
        } 
    }
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