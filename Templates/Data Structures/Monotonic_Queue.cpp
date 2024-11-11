template<class T = int, class F = plus<T>>
struct monotonic_queue {
  struct node { T v, s; };
  vector<node> a, b;
  T e;
  F f;
 
  monotonic_queue(T e = T(), F f = F()) : e(e), f(f) {}
 
  void push(vector<node>& a, const T& v) {
    if (a.size())
      a.push_back({v, f(a.back().s, v)});
    else
      a.push_back({v, v});
  }
 
  void rotate() {
    while (a.size()) {
      push(b, a.back().v);
      a.pop_back();
    }
  }
 
  monotonic_queue& operator+= (const T& x) {
    push(a, x);
    return *this;
  }
 
  T operator() () const {
    T x = e;
    if (a.size()) x = f(x, a.back().s);
    if (b.size()) x = f(x, b.back().s);
    return x;
  }
 
  void pop() {
    if (!b.size())
      rotate();
    b.pop_back();
  }
};

// declaration format is monotonic_queue [name](identity element of the operation, function for the operation between two elements)
// operation should be commutative and associative