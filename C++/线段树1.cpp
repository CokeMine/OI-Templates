#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define ls(x) x << 1
#define rs(x) x << 1 | 1
#define LL long long
using namespace std;

static const int MAXN = 100001;

LL tree[MAXN << 2];
LL tag[MAXN << 2];
LL a[MAXN];

int n,m;

void push_up(LL k) {
    tree[k] = tree[ls(k)] + tree[rs(k)];
}

inline void f(LL k,LL l,LL r,LL p) {
    tag[k] += p;
    tree[k] += p * (r - l + 1);
}

void push_down(LL k,LL l,LL r) {
    LL mid = (l + r) >> 1;
    f(ls(k),l,mid,tag[k]);
    f(rs(k),mid + 1,r,tag[k]);
    tag[k] = 0; 
}

void build(LL k,LL l,LL r) {
    tag[k] = 0;
    if(l == r) {
        tree[k] = a[l];
        return ;
    }
    LL mid = (l + r) >> 1;
    build(ls(k),l,mid);
    build(rs(k),mid + 1,r);
    push_up(k);
}

void update(LL k,LL l,LL r,LL x,LL y,LL p) {
    if(y < l || x > r) return ;
    if(x <= l && y >= r) {
        tree[k] += p * (r - l + 1);
        tag[k] += p;
        return ;
    }
    push_down(k,l,r);
    LL mid = (l + r) >> 1;
    if(x <= mid) update(ls(k),l,mid,x,y,p);
    if(y > mid) update(rs(k),mid + 1,r,x,y,p);
    push_up(k);
}

LL Query(LL k,LL l,LL r,LL x,LL y) {
    LL res = 0;
    if(y < l || x > r) return 0;
    if(x <= l && y >= r) return tree[k];
    LL mid = (l + r) >> 1;
    push_down(k,l,r);
    if(x <= mid) res += Query(ls(k),l,mid,x,y);
    if(y > mid) res += Query(rs(k),mid + 1,r,x,y);
    return res;
}


int main() {
    cin >> n >> m;
    for(int i = 1;i <= n;++i) cin >> a[i];
    build(1,1,n);
    for(int i = 1;i <= m;++i) {
        int t;
        cin >> t;
        if(t == 1) {
            LL x,y,k;
            cin >> x >> y >> k;
            update(1,1,n,x,y,k);
        }
        if(t == 2) {
            LL x,y;
            cin >> x >> y;
            cout << Query(1,1,n,x,y) << endl;
        }
    }
}
