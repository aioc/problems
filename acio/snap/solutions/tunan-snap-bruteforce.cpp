#include<iostream>
#include<vector>
#include<queue>
#define MAXN 22
using namespace std;
int N, K, pi, V[MAXN];
int dist[1<<MAXN], init;
vector <int> adj[MAXN];
queue<int> Q;

int main() {
    scanf("%d %d",&N,&K);
    for (int i=1; i<=N; i++) {
        scanf("%d", &V[i]);
        adj[i].push_back(V[i]);
        adj[V[i]].push_back(i);
    }
    for (int i=1; i<=K; i++) {
        scanf("%d",&pi);
        init+=(1<<pi);
    }
    Q.push(init);
    while (Q.size()) {
        int B=Q.front();
        if (B == 0) {
            printf("%d\n", dist[B]);
            return(0);
        }
        Q.pop();
        for (int i=1; i<=N; i++) {
            if (B&(1<<i)) {
                int newB=B-(1<<i);
                for (auto v: adj[i]) {
                    int newM = newB^(1<<v);
                    if (newM != init && (!dist[newM] || dist[newM] > dist[B] + 1)) {
                        dist[newM] = dist[B] +1;
                        Q.push(newM);
                    }
                }
                break;
            }
        }
    }
}
