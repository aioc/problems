#include<iostream>
#include<map>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000*1000*1000+7;

const int N = 10*1000*1000; 

int upto = 0;
ll v[N];
ll d[N];
map < ii, int > id;

inline int build (ii lr) {
  if (!id.count(lr)) {
    v[upto] = 0;
    d[upto] = 0;
    id[lr] = upto++;
  }
  return id[lr];
}

ll query (int a, int b, int i, int l, int r) {
  if (a >= r || b <= l)
    return 0;
  int m = (l+r)/2;
  if (d[i] != 0) {
    int j = build(ii(l,m));
    int k = build(ii(m,r));
    v[i] = d[i] * (r-l);
    if (r - l > 1) {
      d[j] = max(d[i],d[j]);
      d[k] = max(d[i],d[k]);
    }
    d[i] = 0;
  }
  if (a <= l && b >= r)
    return v[i];
  else if (r - l > 1) {
    int j = build(ii(l,m));
    int k = build(ii(m,r));
    return query(a,b,j,l,m) + query(a,b,k,m,r);
  } else
    return v[i];
}

void update (int a, int b, ll x, int i, int l, int r) {
  int m = (l+r)/2;
  if (d[i] != 0) {
    int j = build(ii(l,m));
    int k = build(ii(m,r));
    v[i] = d[i] * (r-l);
    if (r - l > 1) {
      d[j] = max(d[i],d[j]);
      d[k] = max(d[i],d[k]);
    }
    d[i] = 0;
  }
  if (a >= r || b <= l)
    return;
  else if (a <= l && b >= r) {
    int j = build(ii(l,m));
    int k = build(ii(m,r));
    v[i] = x * (r-l);
    if (r - l > 1) {
      d[j] = x;
      d[k] = x;
    }
  } else if (r - l > 1) {
    int j = build(ii(l,m));
    int k = build(ii(m,r));
    update(a,b,x,j,l,m);
    update(a,b,x,k,m,r);
    v[i] = v[j] + v[k];
  }
}

int main () {
  int n;
  cin >> n;
  build(ii(0,n));

  int q;
  cin >> q;
  while (q--) {
    int x, a, b;
    cin >> x >> a >> b;
    a--;
    int i = build(ii(a,b));
    ll h = query(a,b,0,0,n);
//    cerr << h << '\n';
    cout << 1LL*(b-a)*x-h << '\n';
    update(a,b,x,0,0,n);
  }
//  cerr << upto << '\n';
}
