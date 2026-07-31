#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
const long long INF = 2e18;

struct node {
  int p = 0, c[2] = {0, 0}, pp = 0;
  bool flip = 0;
  int sz = 0, ssz = 0, vsz = 0;
  long long val = 0, sum = 0, lazy = 0, subsum = 0, vsum = 0;
  long long xsum = 0, mn = INF, mx = -INF;
  node() {}
  node(long long x) {
    val = x; sum = x;
    xsum = x; mn = x; mx = x;
    sz = 1; lazy = 0;
    ssz = 1; vsz = 0;
    subsum = x; vsum = 0;
  }
};

struct PathRes {
  long long sum, xsum, mn, mx;
};

struct LCT {
  vector<node> t;
  LCT() {}
  LCT(int n) : t(n + 1) {
    t[0].mn = INF;
    t[0].mx = -INF;
    t[0].xsum = 0;
    t[0].sum = 0;
  }

  int dir(int x, int y) { return t[x].c[1] == y; }
  
  void set(int x, int d, int y) {
    if (x) t[x].c[d] = y, pull(x);
    if (y) t[y].p = x;
  }
  
  void pull(int x) {
    if (!x) return;
    int &l = t[x].c[0], &r = t[x].c[1];
    push(l); push(r);
    t[x].sum = t[l].sum + t[r].sum + t[x].val;
    t[x].xsum = t[l].xsum ^ t[r].xsum ^ t[x].val;
    t[x].mn = min({t[x].val, t[l].mn, t[r].mn});
    t[x].mx = max({t[x].val, t[l].mx, t[r].mx});
    t[x].sz = t[l].sz + t[r].sz + 1;
    t[x].ssz = t[l].ssz + t[r].ssz + t[x].vsz + 1;
    t[x].subsum = t[l].subsum + t[r].subsum + t[x].vsum + t[x].val;
  }
  
  void push(int x) { 
    if (!x) return;
    int &l = t[x].c[0], &r = t[x].c[1];
    if (t[x].flip) {
      swap(l, r); 
      if (l) t[l].flip ^= 1; 
      if (r) t[r].flip ^= 1;
      t[x].flip = 0;
    }
    if (t[x].lazy) {
      t[x].val += t[x].lazy;
      t[x].sum += t[x].lazy * t[x].sz;
      t[x].mn += t[x].lazy;
      t[x].mx += t[x].lazy;
      t[x].subsum += t[x].lazy * t[x].ssz;
      t[x].vsum += t[x].lazy * t[x].vsz;
      if (l) t[l].lazy += t[x].lazy;
      if (r) t[r].lazy += t[x].lazy;
      t[x].lazy = 0;
    }
  }
  
  void rotate(int x, int d) { 
    int y = t[x].p, z = t[y].p, w = t[x].c[d];
    swap(t[x].pp, t[y].pp);
    set(y, !d, w);
    set(x, d, y);
    set(z, dir(z, y), x);
  }
  
  void splay(int x) { 
    for (push(x); t[x].p;) {
      int y = t[x].p, z = t[y].p;
      push(z); push(y); push(x);
      int dx = dir(y, x), dy = dir(z, y);
      if (!z) rotate(x, !dx); 
      else if (dx == dy) rotate(y, !dx), rotate(x, !dx); 
      else rotate(x, dy), rotate(x, dx);
    }
  }
  
  void make_root(int u) {
    access(u);
    int l = t[u].c[0];
    t[l].flip ^= 1;
    swap(t[l].p, t[l].pp);
    t[u].vsz += t[l].ssz;
    t[u].vsum += t[l].subsum;
    set(u, 0, 0);
  }
  
  int access(int _u) {
    int last = _u;
    for (int v = 0, u = _u; u; u = t[v = u].pp) {
      splay(u); splay(v);
      t[u].vsz -= t[v].ssz;
      t[u].vsum -= t[v].subsum;
      int r = t[u].c[1];
      t[u].vsz += t[r].ssz;
      t[u].vsum += t[r].subsum;
      t[v].pp = 0;
      swap(t[r].p, t[r].pp);
      set(u, 1, v);
      last = u;
    }
    splay(_u);
    return last;
  }
  
  void link(int u, int v) {
    make_root(v);
    access(u); splay(u);
    t[v].pp = u;
    t[u].vsz += t[v].ssz;
    t[u].vsum += t[v].subsum;
  }
  
  void cut(int u) {
    access(u);
    t[t[u].c[0]].p = 0;
    t[u].c[0] = 0;
    pull(u);
  }
  
  int get_parent(int u) {
    access(u); splay(u); push(u);
    u = t[u].c[0]; push(u);
    while (t[u].c[1]) {
      u = t[u].c[1]; push(u);
    }
    splay(u);
    return u;
  }
  
  int find_root(int u) {
    access(u); splay(u); push(u);
    while (t[u].c[0]) {
      u = t[u].c[0]; push(u);
    }
    splay(u);
    return u;
  }
  
  bool connected(int u, int v) {
    return find_root(u) == find_root(v);
  }
  
  int depth(int u) {
    access(u); splay(u);
    return t[u].sz;
  }
  
  int lca(int u, int v) {
    if (u == v) return u;
    if (depth(u) > depth(v)) swap(u, v);
    access(v); 
    return access(u);
  }
  
  int is_root(int u) {
    return get_parent(u) == 0;
  }
  
  int component_size(int u) {
    return t[find_root(u)].ssz;
  }
  
  int subtree_size(int u) {
    int p = get_parent(u);
    if (p == 0) return component_size(u);
    cut(u);
    int ans = component_size(u);
    link(p, u);
    return ans;
  }
  
  long long component_sum(int u) {
    return t[find_root(u)].subsum;
  }
  
  long long subtree_sum(int u) {
    int p = get_parent(u);
    if (p == 0) return component_sum(u);
    cut(u);
    long long ans = component_sum(u);
    link(p, u);
    return ans;
  }
  
  long long subtree_query(int u, int root) {
    int cur = find_root(u);
    make_root(root);
    long long ans = subtree_sum(u);
    make_root(cur);
    return ans;
  }
  
  PathRes query_path(int u, int v) {
    int cur = find_root(u);
    make_root(u); access(v);
    PathRes ans = {t[v].sum, t[v].xsum, t[v].mn, t[v].mx};
    make_root(cur);
    return ans;
  }
  
  void upd_point(int u, long long x) {
    access(u); splay(u);
    t[u].val += x;
    pull(u);
  }
  
  void upd_path(int u, int v, long long x) {
    int cur = find_root(u);
    make_root(u); access(v);
    t[v].lazy += x;
    make_root(cur);
  }
};