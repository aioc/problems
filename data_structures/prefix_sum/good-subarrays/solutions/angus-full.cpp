#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
#define OFFSET MAXN
typedef long long ll;
ll ans;
int amWith[MAXN*11], n, pre;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		amWith[OFFSET+pre-i+1]++;
		int a;
		scanf("%d", &a);
		pre += a;
		ans += amWith[OFFSET+pre-i];
	}
	printf("%lld\n", ans);
}