#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    i64 n, m, l;
    cin >> n >> m >> l;

    vector<array<i64, 2>> intervals(n);
    for (int i = 0; i < n; i++)
        cin >> intervals[i][0] >> intervals[i][1];

    vector<i64> x(m), v(m);
    for (int i = 0; i < m; i++)
        cin >> x[i] >> v[i];

    priority_queue<i64> pq;

    i64 j = 1;
    int pos = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        auto idx = lower_bound(x.begin(), x.end(), intervals[i][0]) - x.begin();
        for (int j = pos; j < idx; j++) {
            pq.push(v[j]);
        }

        i64 length = intervals[i][1] - intervals[i][0] + 1;
        while (!pq.empty() && j < length + 1) {
            j += pq.top();
            ans++;
            pq.pop();
        }


        if (j < length + 1) {
            debug(i, j);
            cout << -1 << endl;
            return;
        }
        pos = idx;
    }

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