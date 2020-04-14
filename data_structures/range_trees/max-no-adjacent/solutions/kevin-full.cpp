#include<iostream>
#include<algorithm>

using namespace std;

struct data {
    int all;
    int suffix;
    int prefix;
    int inner;
};

data combine(data left, data right) {
    data d;
    d.all = max(left.prefix + right.all, left.all + right.suffix);
    d.suffix = max(left.inner + right.all, left.suffix + right.suffix);
    d.prefix = max(left.prefix + right.prefix, left.all + right.inner);
    d.inner = max(left.inner + right.prefix, left.suffix + right.inner);
    return d;
}

data EMPTY_DATA;

struct rt {
    rt *lc, *rc;

    int l, r;

    data d;

    rt(int L, int R) {
        l = L;
        r = R;
        d.all = 0;
        d.suffix = 0;
        d.prefix = 0;
        d.inner = 0;
        if(l != r) {
            int m = (l+r)/2;
            lc = new rt(l, m);
            rc = new rt(m+1, r);
        } else {
            lc = NULL;
            rc = NULL;
        }
    }

    void update(int i, int x) {
        if(i < l || r < i) {
            return;
        } else {
            if(l != r) {
                lc->update(i, x);
                rc->update(i, x);
                d = combine(lc->d, rc->d);
            } else {
                d.all = x;
                d.inner = 0;
                d.prefix = 0;
                d.suffix = 0;
            }
        }
    }

    data query(int ql, int qr) {
        //cerr << "Data at " << l << ", " << r << " is " << d.all << "\n";
        if(qr < l || r < ql)  {
            return EMPTY_DATA;
        } else if(ql <= l && r <= qr) {
            return d;
        } else {
            return combine(lc->query(ql, qr), rc->query(ql, qr));
        }
    }

};
int N, B;
int main() {
    cin >> N >> B;
    rt* RT = new rt(1, N);
    //cerr << "Built\n";
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        RT->update(i+1, x);
    }
    //cerr << "First add\n";
    for(int i = 0; i < B; i++) {
        char op;
        int p1, p2;
        cin >> op >> p1 >> p2;
        if(op == 'U') {
            //cerr << "Update\n";
            RT->update(p1, p2);
        } else {
            //cerr << "Query\n";
            cout << RT->query(p1, p2).all << "\n";
        }
    }
}
