/*
 * Input: N K min_value max_value
 */

#include <cstdio>
#include <cstdlib>

int main() {
	int N, K, min, max;
	scanf("%d%d%d%d",&N,&K,&min,&max);
	/* Deterministic seed. */
	srand(N*K*min*max);
	
	printf("%d %d\n",N,K);
	if (min == max) {
		for (int i = 0; i < N; i++) {
            if(i != 0) {
                printf(" ");
            }
            printf("%d",min);
        }
	} else {
		for (int i = 0; i < N; i++) {
            if(i != 0) {
                printf(" ");
            }
            printf("%d",min+rand()%(max-min+1));
        }
	}
    printf("\n");
}
