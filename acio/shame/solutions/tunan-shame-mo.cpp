#include <cstdio> 
#include <vector> 
#include <algorithm> 
#include <queue> 
#include <functional> 
using namespace std; 
  
  
int n,m; 
const int max_k = 500; 
  
int cm = 0; 
int a[200005]; 
  
struct range{ 
    int l; 
    int r; 
    long long w; 
}; 
  
vector<range> rv; 
  
priority_queue<int,vector<int>,greater<int>> pq; 
bool in_queue[200005]; 
int cnt[200005]; 
void add(int x, int p){ 
    // printf("added %d %d\n", x, p); 
    cnt[x]++; 
    while (cnt[pq.top()] != 0){ 
        in_queue[pq.top()] = false; 
        pq.pop(); 
    } 
} 
  
void remove(int x, int p){ 
    // printf("removed %d %d\n", x, p); 
  
    cnt[x]--; 
    if (!in_queue[x] && cnt[x] == 0){ 
        in_queue[x]=  true; 
        pq.push(x); 
    } 
} 
  
long long dp[200005]; 
  
  
/* 
query "are all the elements from 1 to x contained in this range?" 
  
*/
int main(){ 
    // freopen("test.in", "r", stdin); 
    scanf("%d %d", &n, &m); 
    pq.push(0); 
    in_queue[0] = true; 
    for (int i = 1; i <= n; i++){ 
        scanf("%d\n", &a[i]); 
        pq.push(i); 
        in_queue[i] = true; 
    } 
    for (int i = 1; i <= m; i++){ 
        int l,r; 
        scanf("%d %d", &l, &r); 
        rv.push_back({l,r,0}); 
    } 
  
    sort(rv.begin(),rv.end(),[](range l, range r){ 
        if (l.l/max_k == r.l/max_k){ 
            return l.r < r.r; 
        } 
        return l.l/max_k < r.l/max_k; 
    }); 
  
    int cl = 1; 
    int cr = 0; 
  
    for (int i = 0; i < m; i++){ 
        range cur = rv[i]; 
        if (cur.r > cr){ 
            for (int i = cr+1; i <= cur.r; i++){ 
                add(a[i],i); 
            } 
            cr = cur.r; 
        } 
        if (cur.l < cl){ 
            for (int i = cl-1; i >= cur.l; i--){ 
                add(a[i],i); 
            } 
            cl = cur.l; 
        } 
        if (cur.r < cr){ 
            for (int i = cr; i > cur.r; i--){ 
                remove(a[i],i); 
            } 
            cr = cur.r; 
        } 
  
        if (cur.l > cl){ 
            for (int i = cl; i < cur.l; i++){ 
                remove(a[i],i); 
            } 
            cl = cur.l; 
        } 
          
        rv[i].w = pq.top(); 
        // printf ("%d %d %d\n", rv[i].l, rv[i].r, rv[i].w); 
    } 
      
    sort(rv.begin(),rv.end(), [](range l, range r){ 
        return l.l > r.l; 
    }); 
  
    int cpt = 0; 
    for (int i = n; i >= 1; i--){ 
        dp[i] = dp[i+1]; 
        while (cpt < rv.size() && rv[cpt].l == i){ 
            dp[i] = max(dp[i], rv[cpt].w + dp[rv[cpt].r + 1]); 
            cpt++; 
        } 
    } 
    printf("%lld\n", dp[1]); 
}
