#include <iostream>

using namespace std;

int rep[1234567];
bool safe[1234567];

int getRep(int a) {
    if(rep[a] == a) {
        return a;
    } else {
        return rep[a] = getRep(rep[a]);
    }
}

void join(int a, int b) {
    int ra = getRep(a);
    int rb = getRep(b);
    rep[ra] = rb;
    safe[rb] |= safe[ra];
}

int N, Q;
int main() {
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) {
        rep[i] = i;
    }
    for(int q = 0; q < Q; q++) {
        char t;
        int a, b;
        cin >> t;
        if(t == 'P') {
            cin >> a >> b;
            join(a, b);
        } else if(t == 'M') {
            cin >> a;
            safe[getRep(a)] = true;
        } else {
            cin >> a;
            cout << safe[getRep(a)] << "\n";
        }
    }
}
