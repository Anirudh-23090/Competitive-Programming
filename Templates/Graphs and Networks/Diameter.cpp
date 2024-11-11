#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	auto get_dis = [&](int s) {
        vector <int> dep(n);
        auto dfs = [&](auto&& self, int v, int pa) -> void {
            dep[v] = (pa != -1) ? (dep[pa] + 1) : 0;
            for (int u : adj[v]) if (u != pa) {
                self(self, u, v);
            }
        };
        dfs(dfs, s, -1);
        return dep;
    };

    vector<int> dis0 = get_dis(0);

    int a = max_element(dis0.begin(), dis0.end()) - dis0.begin();

    vector<int> dis_a = get_dis(a);
    int diamter = *max_element(dis_a.begin(), dis_a.end());

    cout << diamter << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}