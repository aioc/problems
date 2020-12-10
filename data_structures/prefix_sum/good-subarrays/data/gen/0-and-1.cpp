// 0s and 1s. 
// If second argument is 0, 20% chance of a 0, 80% chance of a 1
// If its 1, 5% chance of a 0, 95% chance of a 1
// Otherwise, 0.1% chance of a 0, 99.9% chance of a 1
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
	int type = atoi(argv[2]);
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		int val;
		if (type == 0) {
			val = rnd.next(0, 4);
		} else if (type == 1) {
			val = rnd.next(0, 19);
		} else {
			val = rnd.next(0, 999);
		}
		printf("%d%c", min(1, rnd.next(0, val)), " \n"[i+1==n]);
	}
}