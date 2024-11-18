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
    i64 x;
    cin >> n >> x;

    string s;
    cin >> s;

    vector<int> len;
    for (int j = 0; j < n; ) {
        int l = 0;
        while (j < n && s[j] == '0') {
            l++, j++;
        }
        len.push_back(l);
        while (j < n && s[j] == '1') {
            j++;
        }
    }

    const int m = len.size();
    for (int i = 0; i < m; i++)
        len[i] = 2 * len[i] + 1;

    int ans = count(s.begin(), s.end(), '1');

    sort(len.rbegin(), len.rend());
    for (int i = 0; i < m; i++)
        if (x >= len[i]) {
            ans += (len[i] - 1) / 2;
            x -= len[i];
        } else {
            ans += (x - 1) / 2;
            break;
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