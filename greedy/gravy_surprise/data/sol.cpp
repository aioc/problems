#include <iostream>

using namespace std;
int N, K;
long long int MAX;
long long int a[1000005];
bool valid(long long int x) {
    long long int cur = 0;
    int g = 0;
    for(int i = 1; i <= N; i++) {
        cur += a[i];
        if(cur >= x) {
            cur = 0;
            g++;
        }
    }
    return g >= K;
}
int main() {
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        MAX += a[i];
    }
    long long int l = 0;
    long long int r = MAX;
    while(l != r) {
        long long int m = (l+r)/2;
        if(l+1 == r) {
            if(valid(r)) {
                l++;
            } else {
                r--;
            }
        } else if(valid(m)) {
            l = m;
        } else {
            r = m-1;
        }
    }
    cout << l << "\n";
    return 0;
}
