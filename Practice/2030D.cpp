#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++) {
        a[i] = max(a[i], a[i - 1]);
    }

    string s;
    cin >> s;

    set<int> bad;

    for (int i = 1; i < n; i++) {
        if (s.substr(i - 1, 2) == "LR" && a[i - 1] > i) {
            bad.insert(i - 1);
        }
        if (s.substr(i, 2) == "LR" && a[i] > i + 1) {
            bad.insert(i);
        }
    }

    auto Update = [&] (int i) {
        if (s.substr(i - 1, 2) == "LR" && a[i - 1] > i) {
            bad.erase(i - 1);
        }
        if (s.substr(i, 2) == "LR" && a[i] > i + 1) {
            bad.erase(i);
        }
        if (s[i] == 'R')
            s[i] = 'L';
        else
            s[i] = 'R';
        if (s.substr(i - 1, 2) == "LR" && a[i - 1] > i) {
            bad.insert(i - 1);
        }
        if (s.substr(i, 2) == "LR" && a[i] > i + 1) {
            bad.insert(i);
        }
    };

    while (q--) {
        int i;
        cin >> i;
        i--;
        
        Update(i);

        if (bad.size() > 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
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