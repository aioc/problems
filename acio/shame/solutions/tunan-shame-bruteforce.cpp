#include<iostream>
#include<vector>
#define MAXN 1005
using namespace std;
int N, M, A[MAXN];
int dp[MAXN], Mex[MAXN][MAXN],li, ri;
int has[MAXN], pt;
vector<int> Ranges[MAXN];
int main() {
    scanf("%d %d",&N,&M);
    for (int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i=1; i<=M; i++) {
        scanf("%d %d",&li,&ri);
        Ranges[ri].push_back(li);
    }
    for (int l=1; l<=N; l++) {
        for (int i=0; i<=N; i++) {
            has[i]=0;
        }
        pt=0;
        for (int r=l; r<=N; r++) {
            has[A[r]]=1;
            while (has[pt]) {pt++;}
            Mex[l][r]=pt;
        }
    }

    for (int i=1; i<=N; i++) {
        dp[i]=dp[i-1];
        for (auto l: Ranges[i]) {
            dp[i]=max(dp[i], dp[l-1] + Mex[l][i]);
        }
    }
    printf("%d\n", dp[N]);
}
