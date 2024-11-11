#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int INF = 1E9 + 10;

struct Event {
    int type;
    int position;
    Event(int t, int pos) {
        type = t; position = pos;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    // segment of points part of atleast k segments
    // k = 1 for general union
    // k = n for segments part of every segment

    vector<Event> events;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        Event e(0, l), f(1, r);
        events.push_back(e);
        events.push_back(f);
    }

    sort(events.begin(), events.end(), [&] (Event e, Event f) {
        if (e.position != f.position) {
            return (e.position < f.position);
        } else {
            return (e.type < f.type);
        }
    });

    int L = INF, R = INF;
    int res = 0;

    vector<pair<int,int>> ans;

    for (auto e : events) {
        if (e.type) {
            res--;
            if (res == k - 1) {
                R = e.position;
                ans.push_back({L, R});
                L = INF; R = INF;
            }
        } else {
            res++;
            if (res == k) {
                L = e.position;
            }
        }
    }

    cout << ans.size() << endl;

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}