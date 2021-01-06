
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 18

int C[MAXN];
int D[MAXN];
int SUM[1 << MAXN];
int A[1 << MAXN];

void solve(int N, int W, bool top) {
  if(!N) return;

  memset(A, 0, sizeof(int) << N);
  for(int i = 0; i < 1 << N; i++) {
    for(int j = SUM[i] = 0; j < N; j++) {
      if(i & 1 << j) {
        SUM[i] += C[j];
      }
    }
  }

  int all = (1 << N) - 1;
  for(int res = 1; ; res++) {
    if(res > 1) for(int i = 0; i < N; i++) {
      int s = all ^ 1 << i;
      int* B = A + (1 << i);
      for(int j = s; j; j = j - 1 & s) {
        B[j] = max(B[j], A[j]);
      }
    }
    if(SUM[all] - A[all] <= W) {
      if(top) cout << res << endl;
      for(int i = 0; i < 1 << N; i++) {
        if(A[i] == SUM[i] && SUM[all] - SUM[i] <= W) {
          cout << N - __builtin_popcount(i);
          int p = 0;
          for(int j = N - 1; j >= 0; j--) {
            if(~i & 1 << j) {
              cout << ' ' << D[j];
            }
          }
          for(int j = 0; j < N; j++) {
            if(i & 1 << j) {
              C[p] = C[j];
              D[p++] = D[j];
            }
          }
          cout << endl;
          solve(p, W, false);
          break;
        }
      }
      break;
    }
    for(int i = 0; i < 1 << N; i++) {
      A[i] = SUM[i] - A[i] <= W ? SUM[i] : 0;
    }
  }
}

int main() {
  freopen("skyscraper.in", "r", stdin);
  freopen("skyscraper.out", "w", stdout);

  int N, W; cin >> N >> W;
  for(int i = 0; i < N; i++) {
    cin >> C[i];
    D[i] = 1 + i;
  }
  reverse(C, C + N);
  reverse(D, D + N);

  solve(N, W, true);
}
