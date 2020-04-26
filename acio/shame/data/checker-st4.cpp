#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>

using namespace std;

int N, M, seq[200005], seen[2000005];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", seq+i);
		if (seq[i] >= 200000 || seen[seq[i]]) assert(false);
		seen[seq[i]] = 1;
	}
}
