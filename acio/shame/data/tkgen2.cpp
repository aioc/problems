#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

deque<int> seq;
int N, M, S, type, lim, seed, res[500005], buf[500005];
vector<int> reg[1005];

int main() {
	scanf("%d %d %d %d %d %d", &N, &M, &S, &type, &lim, &seed);
	srand(seed ^ N ^ M ^ lim);
	if (S == 1) assert(N <= 100 && M <= 1000);
	if (S == 2) assert(N <= 1000);
	if (S == 3) assert(N <= 50000 && M <= 50000);
	if (S == 4) assert(N == lim);
	printf("%d %d\n", N, M);
	if (type == 0) {
		// Pure randomness
		if (S == 4) {
			// Random permutation
			for (int i = 1; i <= N; i++) res[i] = i;
			random_shuffle(res+1, res+N+1);
		} else {
			for (int i = 1; i <= N; i++) res[i] = rand() % lim;
		}
		for (int i = 1; i <= N; i++) {
			if (i == 1) printf("%d", res[i]);
			else printf(" %d", res[i]);
		} printf("\n");
		for (int i = 0; i < M; i++) {
			int a = (rand() % N) + 1, b = (rand() % N) + 1;
			if (a > b) swap(a, b);
			printf("%d %d\n", a, b);
		}
	} else if (type == 1) {
		// Decreasing then increasing (MEX max case breaker)
		int center = 0;
		for (int i = 1; i <= N; i++) buf[i] = i % lim;
		sort(buf+1, buf+1+N);
		for (int i = 1; i <= N; i++) {
			if (rand() & 1) {
				seq.push_front(buf[i]);
				center++;
			} else seq.push_back(buf[i]);
		}
		int cnt = 1;
		for (int x : seq) {
			res[cnt++] = x;
		}
		int shufflerate = (int)sqrt((double)N);
		// Randomly shuffle every 4 elements
		for (int i = 1; i+shufflerate-1 <= N; i += shufflerate) {
			random_shuffle(res + i, res + i + shufflerate);
		}
		for (int i = 1; i <= N; i++) {
			if (i == 1) printf("%d", res[i]);
			else printf(" %d", res[i]);
		} printf("\n");
		for (int i = 0; i < M; i++) {
			printf("%d %d\n", (rand() % center) + 1, (rand() % (N-center+1)) + center);
		}
	} else if (type == 2) {
		// Buckets of elements (Recommended to set limit to about half N)
		int buckets = (int)sqrt((double)N);
		for (int i = 1; i <= N; i++) reg[rand() % buckets].push_back(i % lim);
		int cnt = 1;
		for (int i = 0; i < buckets; i++) {
			sort(reg[i].begin(), reg[i].end());
			for (int x : reg[i]) res[cnt++] = x;
		}
		for (int i = 1; i <= N; i++) {
			if (i == 1) printf("%d", res[i]);
			else printf(" %d", res[i]);
		} printf("\n");
		for (int i = 0; i < M; i++) {
			int a = (rand() % N) + 1, b = (rand() % N) + 1;
			if (a > b) swap(a, b);
			printf("%d %d\n", a, b);
		}
	} else {
		// Logarithmic
		for (int i = 1; i <= N; i++) res[i] = __builtin_ctz(rand());
		for (int i = 1; i <= N; i++) {
			if (i == 1) printf("%d", res[i]);
			else printf(" %d", res[i]);
		} printf("\n");
		for (int i = 0; i < M; i++) {
			int a = (rand() % N) + 1, b = (rand() % N) + 1;
			if (a > b) swap(a, b);
			printf("%d %d\n", a, b);
		}
	}
}
