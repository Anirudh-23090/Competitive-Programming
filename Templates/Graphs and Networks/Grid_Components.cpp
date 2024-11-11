vector<vector<int>> identify(n, vector<int>(m, 0));
vector<int> sz(n * m + 1, 0);

auto valid = [&] (int x, int y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	return true;
};

vector<vector<bool>> visited(n, vector<bool>(m, 0));

auto check = [&] (int x, int y) {
	if (valid(x, y) && grid[x][y] == '.' && !visited[x][y])
		return true;
	return false;
};

function<void(int,int,int)> dfs = [&] (int x, int y, int id) {
	identify[x][y] = id;
	sz[id]++;
	visited[x][y] = true;
	for (auto [dx, dy] : to) {
		if (check(x + dx, y + dy)) {
			dfs(x + dx, y + dy, id);
		}
	}
};