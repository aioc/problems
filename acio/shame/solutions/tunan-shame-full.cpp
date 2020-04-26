#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define MAXN 500005
using namespace std;
int N, M, li, ri, A[MAXN], dp[MAXN];
vector<int> Ranges[MAXN], Val[MAXN];
vector<pair<int,pair<int,int> > > Pt;

class PersistentSegtree {
    int ST[MAXN * 40][3]; //point min relax, query min
    int R[MAXN*2], ver=1, pt=1;
public:
    void init() {
        ST[0][0] = 1<<30;
    }
    int put(int ind, int val, int l, int r, int cur) {
        if (ind < l || ind > r) {return(cur);}
        int v = pt, mid=(l+r)>>1;
        pt++;
        if (l == r) {
            ST[v][0]=min(ST[cur][0], val);
        } else {
            ST[v][1]=put(ind, val, l, mid, ST[cur][1]);
            ST[v][2]=put(ind, val, mid+1, r, ST[cur][2]);
            ST[v][0]=min(ST[ST[v][1]][0], ST[ST[v][2]][0]);
        }
        return(v);
    }
    int ask(int lo, int hi, int l, int r, int cur) {
        if (hi < l || lo > r) {return(1<<30);}
        else if (lo <=l && hi >= r) {return(ST[cur][0]);}
        else {
            int mid=(l+r)>>1;
            return(min(ask(lo, hi, l, mid, ST[cur][1]),
                       ask(lo, hi, mid+1, r, ST[cur][2])));
        }
    }
    void add(int a, int b) {
        R[ver] = put(a, b, 1, N+5, R[ver-1]);
        ver++;
    }
    int MEX(int l, int r) {
        int lo=-1, hi=Pt.size(); //lo is final okay point
        while (lo + 1 != hi) {
            int mid=(lo+hi)>>1;
            if (Pt[mid].first > l) {hi=mid;}
            else {lo=mid;}
        }
        return(ask(r, N+5, 1, N+5, R[lo+1]));
    }
} PST;

int main() {
    scanf("%d %d",&N,&M);
    for (int i=0; i<=N; i++) {
        Val[i].push_back(-1);
    }
    for (int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
        Val[A[i]].push_back(i);
    }
    for (int i=0; i<=N; i++) {
        Val[i].push_back(N+2);
    }
    for (int v=0; v<=N; v++) {
        for (int i=0; i<Val[v].size()-1; i++) {
            Pt.push_back({Val[v][i]+1, {Val[v][i+1]-1,v}});
        }
    }
    sort(Pt.begin(), Pt.end());
    PST.init();
    for (auto p: Pt) {
        PST.add(p.second.first, p.second.second);
    }
    for (int i=1; i<=M; i++) {
        scanf("%d %d",&li,&ri);
        Ranges[ri].push_back(li);
    }

    for (int i=1; i<=N; i++) {
        dp[i]=dp[i-1];
        for (auto l: Ranges[i]) {
            dp[i]=max(dp[i], dp[l-1] + PST.MEX(l, i));
        }
    }
    printf("%d\n", dp[N]);
}
