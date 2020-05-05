#include <iostream>

using namespace std;

int N;

const int MAX_N = 15;
const int MAX_B = (1 << MAX_N);
const int INF = 1e9;
int m[MAX_N+4][MAX_N];

bool seen[MAX_B+5][MAX_N+5];
int cache[MAX_B+5][MAX_N+5];

int dp(int b, int at) {
    if(at == N) {
        return 0;
    } else {
        if(!seen[b][at]) {
            seen[b][at] = true;
            int best = INF;
            for(int j = 0; j < N; j++) {
                if(!(b & (1 << j))) {
                    best = min(best, dp(b | (1<<j), at+1) + m[at][j]);
                }
            }
            cache[b][at] = best;
        }
        return cache[b][at];
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }
    cout << dp(0, 0) << "\n";
}
