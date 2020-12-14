/* Input: N K answer */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int N, K, answer;
	vector<int> data;
	set<int> seen;

	scanf("%d%d%d",&N,&K,&answer);

	for (int i = 0; i <= K; i++) {
		data.push_back(i*answer);
		seen.insert(i*answer);
	}

	for (int i = K; i < N; i++) {
		int tmp;
		while (1) {
			tmp = 1+random()%(K*answer);
			if (seen.find(tmp)==seen.end()) break;
		}
		data.push_back(tmp);
		seen.insert(tmp);
	}

	sort(data.begin(),data.end());
	
	printf("%d %d\n",N,K);
	for (int i = 0; i < N; i++) {
        if(i != 0) {
            printf(" ");
        }
        printf("%d",data[i+1]-data[i]);
    }
    printf("\n");
}
