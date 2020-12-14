#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

long long int N, K;
long long int bar[100069];

long long int pre[100069];
long long int suf[100069];

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", bar + i + 1);
    }

    for(int i = 1; i <= N; i++) {
        pre[i] = pre[i-1] + bar[i];
    }

    for(int i = N; i >= 0; i--) {
        suf[i] = suf[i+1] + bar[i];
    }
    
    long long int ans = -1;
    for(int i = 1; i <= N-1; i++) {
        long long int curpre = pre[i];
        long long int cursuf = suf[i+1];

        long long int curans = min(curpre, cursuf);
        ans = max(ans, curans);

    }
    printf("%lld\n", ans);
    return 0;
}
