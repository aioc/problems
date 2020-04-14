#include <bits/stdc++.h>
using namespace std;

#define fo(i,s,t) for(int i = s; i <= t; ++ i)
#define fd(i,s,t) for(int i = s; i >= t; -- i)
#define bf(i,s) for(int i = head[s]; i; i = e[i].next)
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define VI vector<int>
#define sf scanf
#define pf printf
#define fp freopen
#define SZ(x) ((int)(x).size())
#ifdef MPS
#define D(x...) printf(x)
#else
#define D(x...)
#endif
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int inf = 1<<29;
const ll INF = 1ll<<60;
const db Inf = 1e20;
const db eps = 1e-9;

void gmax(int &a,int b){a = (a > b ? a : b);}
void gmin(int &a,int b){a = (a < b ? a : b);}

const int maxn = 100050;

int n, q, a[maxn], mx;
struct tree{int l, r, a, b, c, d;}t[maxn<<2];
char op[2];
bool f;
//maintain a rangetree
//a - calculating the maximum sum which contains the beginning of the inteval and the end
//b - ... not containing the beginning but contain the end 
//c - .. containing the beginning but not the end
//d - .. not containing both

void merge(int k, int ls, int rs)
{
	// first half interval and second half
	//case 1. not containing the end, and not containing the beginning
	if(k == mx+1) ++ k;
	t[k].a = max(t[ls].a + t[rs].b, t[ls].c + max(t[rs].a, t[rs].b));
	t[k].b = max(max(0, t[ls].b) + t[rs].b, max(0, t[ls].d) + max(t[rs].a, t[rs].b));
	t[k].c = max(t[ls].a + max(0, t[rs].d), t[ls].c + max(0, max(t[rs].c, t[rs].d)));
	t[k].d = max(max(0, t[ls].b) + max(0, t[rs].d), max(0, t[ls].d) + max(0, max(t[rs].c, t[rs].d)));
	t[k].a = (t[k].a < 0 ? -inf : t[k].a);
	t[k].b = (t[k].b < 0 ? -inf : t[k].b);
	t[k].c = (t[k].c < 0 ? -inf : t[k].c);
	t[k].d = (t[k].d < 0 ? -inf : t[k].d);
	if(k == mx+2) t[k-1] = t[k];
}
void build(int l, int r, int k = 1)
{
	mx = max(mx, k);
	t[k].l = l; t[k].r = r; 
	if(l == r) 
	{
		t[k].a = a[l]; 
		t[k].c = t[k].b = -inf;
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, k<<1);
	build(mid+1, r, k<<1|1);
	merge(k, k<<1, k<<1|1);
}
void upd(int pos, int r, int k = 1)
{
	if(t[k].l == t[k].r)
	{
		t[k].a = r;
		return;
	}
	int mid = t[k].l + t[k].r >> 1;
	if(pos <= mid) upd(pos, r, k<<1);
	else upd(pos, r, k<<1|1);
	merge(k, k<<1, k<<1|1);
}
void ask(int l, int r, int k = 1)
{
	if(l <= t[k].l && t[k].r <= r)
	{
		if(!f) {f = true; t[mx+1] = t[k];}
		else merge(mx+1, mx+1, k);
		// pf("%d %d %d %d %d %d\n",t[k].l,t[k].r,t[mx+1].a,t[mx+1].b,t[mx+1].c,t[mx+1].d);
		return;
	}
	int mid = t[k].l + t[k].r >> 1;
	if(r <= mid) ask(l, r, k<<1);
	else if(l > mid) ask(l, r, k<<1|1);
	else {ask(l,mid,k<<1); ask(mid+1,r,k<<1|1);}
}
int main()
{
	#ifdef MPS	
		fp("1.in","r",stdin);
		fp("1.out","w",stdout);
	#endif
	sf("%d",&n);
	sf("%d",&q);
	fo(i,1,n) sf("%d",&a[i]);
	build(1,n);
	while(q--)
	{
		int l, r;
		sf("%s",op+1);
		sf("%d%d",&l,&r);
		if(op[1] == 'U') upd(l, r);
		else 
		{
			f = false; ask(l,r); 
			pf("%d\n",max(t[mx+1].a,max(t[mx+1].b,max(t[mx+1].c,t[mx+1].d))));
		}
	}
	return 0;
}
