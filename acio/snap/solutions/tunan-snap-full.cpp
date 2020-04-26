#include<iostream>
#include<vector>
#define MAXN 100005
using namespace std;
int N, K, L=1, V[MAXN];
bool has[MAXN], cyc[MAXN], vis[MAXN], vis2[MAXN];
int dp[MAXN], Ans, sum, pi;
vector <int> adj[MAXN];

void FindCycle(int u) {
    if (vis[u]) {
        cyc[u]=true;
        int cur = V[u];
        while (cur != u) {
            L++;
            cyc[cur]=true;
            cur=V[cur];
        }
    } else {
        vis[u]=true;
        FindCycle(V[u]);
    }
}

void f(int u, int prev) {
    for (auto v: adj[u]) {
        if (v != prev && !cyc[v]) {
            f(v,u);
            dp[u] += dp[v];
            if (has[v]) {
                dp[u]+=1;
                has[u]^=1;
            }
        }
    }
}

void eval(int u, bool b) {
    if (b) {sum++;}
    if (vis2[u]) {return;}
    vis2[u]=true;
    eval(V[u], b^has[u]);
}

int main() {
    scanf("%d %d",&N,&K);
    for (int i=1; i<=N; i++) {
        scanf("%d", &V[i]);
        adj[i].push_back(V[i]);
        adj[V[i]].push_back(i);
    }
    for (int i=1; i<=K; i++) {
        scanf("%d",&pi);
        has[pi]=true;
    }
    FindCycle(1);
    for (int i=1; i<=N; i++) {
        if (cyc[i]) {
            f(i,-1);
            Ans+=dp[i];
        }
    }
    for (int i=1; i<=N; i++) {
        if (cyc[i] && has[i]) {
            eval(i,false);
            break;
        }
    }
    printf("%d\n", Ans + min(sum, L-sum));
}
