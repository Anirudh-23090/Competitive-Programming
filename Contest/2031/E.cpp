#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << endl; 
    int val;
    cin >> val;
    return val;
}

void solve() {
    int n;
    cin >> n;

    string ans;

    int f = 1, prevAns = -1;
    for (int s = 2; s <= n; s++) {
        if (f == s)
            continue;
        int res = ask(f, s);
        if (ans.empty() && res) {
            int len = s - f + 1;
            ans += string(len - 1 - res, '1');
            f = ans.size() + 1;
            ans += string(res, '0');
            ans += '1';
            prevAns = res;
        } else if (!ans.empty()) {
            if (res > prevAns)
                ans += '1';
            else
                ans += '0';
            prevAns = res;
        }
    }

    if (ans.empty()) {
        cout << "! IMPOSSIBLE" << endl;
    } else {
        cout << "!" << ' ' << ans << endl;
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