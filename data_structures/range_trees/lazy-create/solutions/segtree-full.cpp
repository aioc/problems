#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>

using namespace std;

// Bounds:
// N up to 1e9
// Q up to 1e5
//
// Query:
// - Range Update
// - Range Increment
// - Range Sum Query
// - Range Max Query
// 

struct ST { long long m, s; };
// op == 0 -> no operation
// op == 1 -> set
// op == 2 -> increment
struct QU { long long op, val; };

int N, Q, cnt = 2; // 0 is null node, 1 is root node
ST st[10000005];
QU lazy[10000005];
int lc[10000005], rc[10000005];


ST stc(ST l, ST r) {
	return { max(l.m, r.m), l.s + r.s };
}

// Push i down to u
void pushdown(int i, int u) {
	if (lazy[i].op == 1) {
		lazy[u] = { 1, lazy[i].val };
	} else if (lazy[i].op == 2) {
		if (lazy[u].op == 0) {
			lazy[u].op = 2;
			lazy[u].val = lazy[i].val;
		} else {
			// In any other case, we just increment
			lazy[u].val += lazy[i].val;
		}
	}
}

void lu(int ind, int lo, int hi) {
	if (lazy[ind].op == 1) {
		st[ind].m = lazy[ind].val;
		st[ind].s = (hi - lo) * lazy[ind].val;
	} else if (lazy[ind].op == 2) {
		st[ind].m += lazy[ind].val;
		st[ind].s += (hi - lo) * lazy[ind].val;
	}
	pushdown(ind, lc[ind] == 0 ? lc[ind] = cnt++ : lc[ind]);
	pushdown(ind, rc[ind] == 0 ? rc[ind] = cnt++ : rc[ind]);
	lazy[ind] = { 0LL, 0LL };
}

void seg_upd(int lo, int hi, int l, int r, int op, int v, int ind) {
	lu(ind, lo, hi);
	if (lo >= r || hi <= l) return;
	if (lo >= l && hi <= r) {
		lazy[ind] = { op, v };
		lu(ind, lo, hi);
		return;
	}
	int mid = (lo + hi) / 2;
	if (lc[ind] == 0) lc[ind] = cnt++;
	if (rc[ind] == 0) rc[ind] = cnt++;
	seg_upd(lo, mid, l, r, op, v, lc[ind]);
	seg_upd(mid, hi, l, r, op, v, rc[ind]);
	st[ind] = stc(st[lc[ind]], st[rc[ind]]);
}

long long seg_max(int lo, int hi, int l, int r, int ind) {
	if (ind == 0) return 0;
	lu(ind, lo, hi);
	if (lo >= r || hi <= l) return 0;
	if (lo >= l && hi <= r) return st[ind].m;
	int mid = (lo + hi) / 2;
	return max(seg_max(lo, mid, l, r, lc[ind]), seg_max(mid, hi, l, r, rc[ind]));
}

long long seg_sum(int lo, int hi, int l, int r, int ind) {
	lu(ind, lo, hi);
	if (lo >= r || hi <= l) return 0;
	if (lo >= l && hi <= r) return st[ind].s;
	int mid = (lo + hi) / 2;
	return seg_sum(lo, mid, l, r, lc[ind]) + seg_sum(mid, hi, l, r, rc[ind]);
}

int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < Q; i++) {
		char op;
		int a, b, c;
		scanf(" %c", &op);
		if (op == 'A') {
			scanf("%d %d %d", &a, &b, &c);
			seg_upd(0, N, a, b+1, 2, c, 1);
		} else if (op == 'S') {
			scanf("%d %d %d", &a, &b, &c);
			seg_upd(0, N, a, b+1, 1, c, 1);
		} else if (op == 'T') {
			scanf("%d %d", &a, &b);
			printf("%lld\n", seg_sum(0, N, a, b+1, 1));
		} else {
			scanf("%d %d", &a, &b);
			printf("%lld\n", seg_max(0, N, a, b+1, 1));
		}
	}
	assert(cnt <= 10000000);
}
