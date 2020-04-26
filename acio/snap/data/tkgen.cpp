#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define MAXN 100005
using namespace std;
int N,K,S,C,T,V[MAXN],P[MAXN];
int seed;
vector<int> Tree[MAXN];
int rng(int l, int r) {
    int res=rand()%(r-l+1);
    return(res + l);
}

int Perm[MAXN], Pos[MAXN], Cycle;

void disp() {
    printf("%d %d\n",N,K);
    for (int i=1; i<=N; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
    for (int i=1; i<=K; i++) {
        printf("%d ", P[i]);
    } printf("\n");
}

void puttokens() {
    for (int i=1; i<=N; i++) {
        Pos[i]=i;
    }
    random_shuffle(Pos+1, Pos+N+1);
    for (int i=1; i<=K; i++) {
        P[i]=Pos[i];
    }
}

void gen(int c, int t) { //c is length of cycle
    assert(c >= 3 && t <= c);
    random_shuffle(Perm+1, Perm+N+1);
    for (int i=1; i<c; i++) {
        V[Perm[i]]=Perm[i+1];
    }
    V[Perm[c]]=Perm[1];
    random_shuffle(Perm+1, Perm+c+1);
    for (int i=1; i<=t; i++) {
        Tree[i].push_back(Perm[i]);
    }
    for (int i=c+1; i<=N; i++) {
        int t_num = rng(1, t);
        V[Perm[i]]=Tree[t_num][rng(0, Tree[t_num].size()-1)];
        Tree[t_num].push_back(Perm[i]);
    }
    puttokens();
}

int main() {
	// N, K, subtask, cycle length, tree count
     //scanf("%d %d %d %d %d %d",&N,&K,&S,&C,&T,&seed);
	 scanf("%d %d %d %d", &N, &K, &S, &seed);
	 srand(seed);
     assert(N >= 3 && (K%2 == 0));
     for (int i=1; i<=N; i++) {
        Perm[i]=i;
     }
     if (S == 1) {assert(N<=20);}
     if (S == 3) {assert(K == N);}
     if (2<=S && S<=4) {assert(N<=1000);}
     if (S == 2) {
        for (int i=1; i<=N; i++) {
            V[i]=((i)%N)+1;
        }
        puttokens();
     } else {
        if (true || S <= 20) {
            int cyc=rng(3,N);
            gen(cyc, rng(1,cyc));
        } else {
            //gen(C, T);
        }
     }
     disp();
}
