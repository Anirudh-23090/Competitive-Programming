#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

constexpr i64 INF = 1E18;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> mark(n);
    for (int i = 0; i < h; i++) {
        int v;
        cin >> v;
        v--; mark[v] = true;
    }

    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    vector<i64> dis1(2 * n, -1);
    priority_queue<tuple<i64, int, int>> process;
    process.emplace(0, 0, -1);
    while (!process.empty()) {
        auto [d, x, t] = process.top();
        process.pop();

        if (dis1[x] != -1) {
            continue;
        }

        dis1[x] = -d;
        if (x < n && mark[x]) {
            process.push({d, n + x, x});
        }
        if (x > n - 1) {
            process.push({d, x - n, x});
        }

        if (x > n - 1) {
            for (auto [y, w] : adj[x - n]) {
                process.emplace(d - (w >> 1), y + n, x);
            }
        } else {
            for (auto [y, w] : adj[x]) {
                process.emplace(d - w, y, x);
            }
        }
    }
    
    vector<i64> dis2(2 * n, -1);
    process.emplace(0, n - 1, n);
    while (!process.empty()) {
        auto [d, x, t] = process.top();
        process.pop();

        if (dis2[x] != -1) {
            continue;
        }

        dis2[x] = -d;
        if (x < n && mark[x]) {
            process.push({d, n + x, x});
        }
        if (x > n - 1) {
            process.push({d, x - n, x});
        }

        if (x > n - 1) {
            for (auto [y, w] : adj[x - n]) {
                process.emplace(d - (w >> 1), y + n, x);
            }
        } else {
            for (auto [y, w] : adj[x]) {
                process.emplace(d - w, y, x);
            }
        }
    }

    debug(dis1, dis2);

    i64 ans = INF;
    for (int i = 0; i < n; i++) {
        if (dis1[i] != -1 && dis2[i] != -1) {
            ans = min(ans, max(dis1[i], dis2[i]));
        }
    }

    if (ans < INF)
        cout << ans << endl;
    else
        cout << -1 << endl;
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