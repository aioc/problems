#include<iostream>

using namespace std;
int N, Q;

struct node {
    int l, r;
    long long int sum;
    long long int dirtySet;
    node *lc, *rc;

    node(int L, int R) : l{L}, r{R}, sum{0}, dirtySet{0}, lc{NULL}, rc{NULL} {}

    void clean(long long int newd) {
        dirtySet = newd;
        sum = (r-l+1)*newd;
        //cerr << "Cleaning " << l << " " << r << " now " << sum << "\n";
    }

    void push() {
        if(l != r) {
            if(!lc) {
                int mid = (l+r)/2;
                lc = new node(l, mid);
                rc = new node(mid+1, r);
            }
            if(dirtySet != 0) {
                lc->clean(dirtySet);
                rc->clean(dirtySet);
                dirtySet = 0;
            }
        }
    }

    long long int query(int ql, int qr) {
        push();
        if(qr < l || r < ql) {
            return 0;
        } else if(ql <= l && r <= qr) {
            //cerr << "SUM1 " << l << " " << r << ": " << sum << "\n";
            return sum;
        } else {
            long long int ans = lc->query(ql, qr) + 
                      rc->query(ql, qr);
            //cerr << "SUM2 " << l << " " << r << ": " << ans << "\n";
            return ans;
        }
    }

    void update(int ul, int ur, int uv) {
        push();
        if(ur < l || r < ul) {
            return;
        } else if(ul <= l && r <= ur) {
            clean(uv);
        } else {
            lc->update(ul, ur, uv);
            rc->update(ul, ur, uv);
            sum = lc->sum + rc->sum;
        }
        //cerr << "new sum " << l << " " << r << " is " << sum << "\n";
    }
};

node* rt;


int main() {
    cin >> N >> Q;
    rt = new node(1, N);
    for(int i = 1; i <= Q; i++) {
        long long int d, l, r;
        cin >> d >> l >> r;
        //cerr << "Sum of " << l << " " << r << " " << rt->query(l, r) << "\n";
        long long int apples = d*(r-l+1ll) - rt->query(l, r);
        cout << apples << "\n";
        //cerr << "Set " << l << " to " << r << " to " << d << "\n";
        rt->update(l, r, d);
    }
}
