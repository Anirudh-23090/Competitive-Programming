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

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i].resize(c[i]);
        for (int j = 0; j < c[i]; j++) {
            cin >> p[i][j];
        }
    }

    vector<int> directions(n, 1); 
    directions[1] = 0;            
    vector<int> stk = {1};        

    auto calc = [&](int idx) {
        int res = 0;
        if (idx > 0 && directions[idx - 1] == 1) {
            for (int i = 0; i < min(c[idx], c[idx - 1]); i++) {
                res += (p[idx][i] == p[idx - 1][i]);
            }
        }
        if (idx - 1 > 0 && directions[idx - 2] == 1) {
            for (int i = 0; i < min(c[idx], c[idx - 1]); i++) {
                res += (p[idx][i] == p[idx - 2][i]);
            }
        }
        return res;
    };

    for (int i = 2; i < n; i++) {
        while (!stk.empty()) {
            int q = calc(stk.back());
            int cd = directions[stk.back()];
            directions[stk.back()] = 1;
            int w = calc(i);
            directions[stk.back()] = cd;
            if (q > w) {
                directions[stk.back()] = 1;
                stk.pop_back();
            } else {
                break;
            }
        }
        directions[i] = 0;
        stk.push_back(i);
    }

    int ans = 0;
    for (auto x : stk) {
        ans += calc(x);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
