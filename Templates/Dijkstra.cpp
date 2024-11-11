#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	
    vector<i64> dis(n, -1);
    vector<int> pre(n, -1);

    priority_queue<tuple<i64, int, int>> process;

    process.emplace(0, 0, -1);

    while (!process.empty()) {
    	auto [d, x, t] = process.top();
    	process.pop();

    	if (dis[x] != -1) {
    		continue;
    	}

    	dis[x] = -d;
    	pre[x] = t;

    	for (auto [y, w] : adj[x]) {
    		process.emplace(d - w, y, x);
    	}
    }

    if (dis[n - 1] == -1) {
    	cout << "-1" << endl;
    	return;
    }

    vector<int> path;
    for (int i = n - 1; i != -1; i = pre[i]) {
    	path.push_back(i);
    }

    reverse(path.begin(), path.end());

    for (auto u : path) {
    	cout << u + 1 << ' ';
    }
    cout << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}