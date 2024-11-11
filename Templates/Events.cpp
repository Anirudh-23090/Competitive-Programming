#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr i64 INF = 1E9 + 10;

struct Event {
    int type;
    int position;
    Event(int t, int pos) {
        type = t; position = pos;
    }
};
 
void solve() {
    int n;
    cin >> n;
 
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

    int ans = 0;

    int res = 0;
    for (auto e : events) {
        if (e.type) {
            res--;
        } else {
            res++;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}