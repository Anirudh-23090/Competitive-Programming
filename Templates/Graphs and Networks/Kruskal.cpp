#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

struct Edge {
	int u, v, w;
};

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<Edge> edges(m);
	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}

	DSU d(n);

	auto weight = [&] (Edge e, Edge f) {
		return e.w < f.w;
	};
	sort(edges.begin(), edges.end(), weight);

	i64 ans = 0;
	for (int i = 0; i < m; i++) {
		if (!d.same(edges[i].u, edges[i].v)) {
			ans += edges[i].w;
			d.merge(edges[i].u, edges[i].v);
		}
	}

	cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}