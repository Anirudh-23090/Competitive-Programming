vector<int> b = a, c = a;
sort(b.begin(), b.end());
b.erase(unique(b.begin(), b.end()), b.end());

vector<int> cnt(b.size());

sort(c.begin(), c.end());

for (int i = 0, j = 0; i < n; i++) {
    if (i == 0 || c[i] == c[i - 1])
        cnt[j]++;
    else
        cnt[++j]++;
}