#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr i64 INF = 1E18;

void solve() {
	int n;
	cin >> n;
	
	vector<i64> a(n + 1);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	// i64 ans = -INF;
	// for (int i = 1; i <= n; i++) {
	// 	a[i] = max(a[i], a[i] + a[i - 1]);
	// 	ans = max(ans, a[i]);
	// cout << ans << endl;
	// }

	array<i64, 3> ans = {-INF, -1, -1};

    i64 sum = 0;
    for (int i = 0, j = 0; i < n && j < n;) {
        while (j < n && a[j] + sum >= 0) {
            sum += a[j];
            ans = max(ans, {sum, i, j});
            j++;
        }
        if (j < n)
            ans = max(ans, {a[j], j, j});
        i = j = j + 1, sum = 0;
    }

    cout << ans[1] + 1 << ' ' << ans[2] + 1 << ' ' << ans[0] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}