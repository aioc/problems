// Given: n, value
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
	int n = atoi(argv[1]), k = atoi(argv[2]);
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		printf("%d%c", k, " \n"[i+1==n]);
	}
}