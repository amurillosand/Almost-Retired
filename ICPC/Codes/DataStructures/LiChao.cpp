struct Fun {
  lli m = 0, c = inf;
  lli operator ()(lli x) const { return m * x + c; }
};

struct LiChao {
  Fun f;
  lli l, r;
  LiChao *L, *R;

  LiChao(int l, int r, Fun f = {}) :
    l(l), r(r), f(f), L(0), R(0) {}

  void add(Fun &g) {
    if (f(l) <= g(l) && f(r) <= g(r))
      return;
    if (g(l) < f(l) && g(r) < f(r)) {
      f = g;
      return;
    }
    lli m = (l + r) / 2;
    if (g(m) < f(m))
      swap(f, g);
    if (g(l) <= f(l)) 
      L = L ? (L->add(g), L) : new LiChao(l, m, g);
    else 
     R = R ? (R->add(g), R) : new LiChao(m + 1, r, g);
  }

  lli query(lli x) {
    if (l == r) 
      return f(x);
    int m = (l + r) / 2;
    if (x <= m)
      return min(f(x), L ? L->query(x) : inf);
    return min(f(x), R ? R->query(x) : inf);
  }
};