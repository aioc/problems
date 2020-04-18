#include<bits/stdc++.h>
using namespace std;

const int N = 1001001;
int p[N];
int r[N];
bool c[N];

void init (int n) {
  for (int i = 0; i < n; i++) {
    p[i] = i;
    r[i] = 1;
    c[i] = false;
  }
}

int find (int x) {
  if (p[x] == x) {
    return x;
  } else {
    bool tmp = c[p[x]];
    p[x] = find(p[x]);
    c[p[x]] |= tmp;
  }
}

void join (int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  if (r[x] < r[y]) {
    p[x] = y;
    c[y] |= c[x];
    r[y] += r[x];
  } else {
    p[y] = x;
    c[x] |= c[y];
    r[x] += r[y];
  }
}

int main (void) {
  int n; cin >> n;
  int q; cin >> q;
  init(n);
  for (int i = 0; i < q; i++) {
    char t; scanf(" %c",&t);
    if (t == 'P') {
      int x, y; cin >> x >> y;
      join(x,y);
    }
    if (t == 'M') {
      int x; cin >> x;
      c[p[x]] = true;
      find(x);
    }
    if (t == 'C') {
      int x; cin >> x;
      x = find(x);
      cout << (c[x] ? 1 : 0) << '\n';
    }
  }
}
