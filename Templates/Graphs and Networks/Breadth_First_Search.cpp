auto bfs = [&] (int s) {
    queue<int> q;
    vector<bool> used(n);
    vector<int> d(n), p(n);
    d.assign(n, 0);

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
};