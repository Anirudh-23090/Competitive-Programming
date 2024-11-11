vector<bool> visited(n, false);

auto dfs = [&] (auto&& self, int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            self(self, u);
    }
};