#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define CREATE_FUNCTOR(name, expr) \
template <typename T>\
struct name {\
    constexpr T operator ()(const T& x, const T& y) const { return expr; }\
}
 
CREATE_FUNCTOR(Min, std::min(x, y));
CREATE_FUNCTOR(Max, std::max(x, y));
 
template <typename T, class Op = Min<T>>
struct Sparse {
    Op op;
    vector<vector<T>> table;
 
    template <typename U = T>
    void build(const vector<U>& a) {
        table.assign(a.size(), {});
        for (int i = 0; i < (int)a.size(); ++i) {
            table[i] = {a[i]};
        }
        for (int l = 1, j = 0; 2 * l <= (int)a.size(); ++j, l <<= 1) {
            for (int i = 0; i + 2 * l <= (int)a.size(); ++i) {
                table[i].push_back(op(table[i][j], table[i + l][j]));
            }
        }
    }
 
    Sparse() {}
 
    template <typename U = T>
    explicit Sparse(const vector<U>& a) {
        build(a);
    }

    template <typename U = T>
    Sparse(const vector<U>& a, Op&& _op): op(_op) {
        build(a);
    }
 
    T get(int l, int r) const {
        assert(r > l);
        const int b = 31 - __builtin_clz(r - l);
        return op(table[l][b], table[r - (1 << b)][b]);
    }
};

void solve() {
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}