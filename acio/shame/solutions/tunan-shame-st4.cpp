#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int N, M, seq[200005], l[200005], r[200005], pos[200005], lt[200005], rt[200005], ans;
vector<int> interv[200005];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", seq + i);
		if (pos[seq[i]] != 0) assert(false);
		pos[seq[i]] = i;
	}
	lt[0] = rt[0] = pos[0];
	for (int i = 1; i < N; i++) {
		lt[i] = min(lt[i-1], pos[i]);
		rt[i] = max(rt[i-1], pos[i]);
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", l+i, r+i);
		int lo = 0, hi = N;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (mid == 0 || (lt[mid-1] >= l[i] && rt[mid-1] <= r[i])) lo = mid;
			else hi = mid;
		}
		ans = max(ans, lo);
	}
	printf("%d\n", ans);
}
