#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
	}

	vector<int> ts;
	vector<int> mark(N);

	function<void(int)> dfs = [&] (int u) {
		mark[u] = 1;
		for (auto node : adj[u]) {
			if (!mark[node])
				dfs(node);
			else if (mark[node] == 1) {
				cout << -1 << endl;
				exit(0);
			}
		}
		ts.push_back(u);
		mark[u] = 2; 
	};

	for (int i = 0; i < N; i++) {
		if (!mark[i])
			dfs(i);
	}

	reverse(ts.begin(), ts.end());
	for (auto x : ts)
		cout << x + 1 << ' ';
	cout << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}