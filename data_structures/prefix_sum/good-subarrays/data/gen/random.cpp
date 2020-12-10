#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		printf("%d%c", rnd.next(0, 9), " \n"[i+1==n]);
	}
}