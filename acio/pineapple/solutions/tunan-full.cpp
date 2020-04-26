#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#define fi first
#define se second

using namespace std;
typedef pair<int, int> pii;

int N, left[300005], right[300005], lc[300005], rc[300005], dp[300005][2][2];
pii houses[300005];
vector<pii> s; // Index, determinant

void dfs(int i) {
	if (lc[i] >= 0) dfs(lc[i]);
	if (rc[i] >= 0) dfs(rc[i]);
	for (int l = 0; l <= 1; l++) {
		for (int r = 0; r <= 1; r++) {
			int val = 1;
			if (lc[i] >= 0) val += dp[lc[i]][l][1];
			if (rc[i] >= 0) val += dp[rc[i]][1][r];
			dp[i][l][r] = val;
		}
	}
	int val2 = 0;
	if (lc[i] >= 0) val2 += dp[lc[i]][1][0];
	if (rc[i] >= 0) val2 += dp[rc[i]][0][1];
	dp[i][1][1] = min(dp[i][1][1], val2);
}

int main() {
	scanf("%d", &N);
	int mi = -1, mv = -1;
	for (int i = 0; i < N; i++) {
		lc[i] = rc[i] = -1;
		int d, e;
		scanf("%d %d", &d, &e);
		houses[i] = { e, d };
	}
	sort(houses, houses+N);
	for (int i = 0; i < N; i++) {
		if (mv < houses[i].se) {
			mv = houses[i].se;
			mi = i;
		}
		int lastremoved = -1;
		while (s.size() && s.back().se < houses[i].se) {
			if (lastremoved >= 0) rc[s.back().fi] = lastremoved;
			right[s.back().fi] = i;
			lastremoved = s.back().fi;
			s.pop_back();
		}
		if (s.size()) left[i] = s.back().fi;
		if (lastremoved >= 0) lc[i] = lastremoved;
		s.push_back({ i, houses[i].se });
	}
	int lastelem = -1;
	while (s.size()) {
		if (lastelem >= 0) rc[s.back().fi] = lastelem;
		lastelem = s.back().fi;
		s.pop_back();
	}
	dfs(mi);
	printf("%d\n", dp[mi][1][1]);
}
