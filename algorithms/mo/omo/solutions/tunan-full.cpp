#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#define SQRT 400
using namespace std;

struct query {
	int l, r, ind;
} qu[100005];
int N, Q, a[100005], freq[100005], ans[100005], elems;
set<int> occ;
vector<int> vocc;
void check(int i) {
	if (freq[a[i]] & 1) elems++;
	else elems--;
}
int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a+i);
		occ.insert(a[i]);
	}
	for (int x : occ) vocc.push_back(x);
	for (int i = 1; i <= N; i++) {
		a[i] = distance(vocc.begin(), lower_bound(vocc.begin(), vocc.end(), a[i]));
	}
	for (int i = 0; i < Q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		qu[i] = { l, r, i };
	}
	sort(qu, qu+Q, [](query x, query y) {
		if (x.l / SQRT == y.l / SQRT) {
			return x.r < y.r;
		}
		return x.l / SQRT < y.l / SQRT;
	});
	int lp = 1, rp = 0;
	for (int i = 0; i < Q; i++) {
		while (rp < qu[i].r) {
			freq[a[rp+1]]++;
			check(rp+1);
			rp++;
		}
		while (lp > qu[i].l) {
			freq[a[lp-1]]++;
			check(lp-1);
			lp--;
		}
		while (rp > qu[i].r) {
			freq[a[rp]]--;
			check(rp);
			rp--;
		}
		while (lp < qu[i].l) {
			freq[a[lp]]--;
			check(lp);
			lp++;
		}
		ans[qu[i].ind] = elems <= 1;
	}
	for (int i = 0; i < Q; i++) {
		if (ans[i]) printf("YES\n");
		else printf("NO\n");
	}
}
