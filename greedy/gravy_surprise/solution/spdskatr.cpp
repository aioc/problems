#include <cstdio>
#include <cstdlib>

int N, K;
int bar[100069];

int possible(long long limit) {
    long long count = 0;
    long long s = 0;
    for (int i = 0; i < N; i++) {
        s += bar[i];
        if (s > limit) {
            count++;
            s = 0;
        }
    }
    return count >= K;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", bar + i);
    }
    long long lo = 0;
    long long hi = 1e11+1;
    while (lo != hi) {
        long long mid = (lo + hi) / 2;
        if (!possible(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    printf("%lld", lo);
    return 0;
}
