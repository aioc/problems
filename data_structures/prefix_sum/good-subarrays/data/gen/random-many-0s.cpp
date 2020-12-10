// 36/45 chance of 0
// 1/45 each for 1-9
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		int val = rnd.next(0, 44);
		val = max(0, val-35);
		printf("%d%c", val, " \n"[i+1==n]);
	}
}