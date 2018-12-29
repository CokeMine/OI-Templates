#include <cstdio>
#include <iostream>
#include <algorithm>
#define ls(x) x << 1
#define rs(x) x << 1 | 1
#define MAXN 100005
#define LL long long
using namespace std;
 
LL tree[MAXN << 2],tag[MAXN << 2],a[MAXN],tag2[MAXN << 2];

LL MOD;


void push_up(LL k) {
    tree[k] = tree[ls(k)] + tree[rs(k)];
    tree[k] %= MOD;
}

inline void f(LL k,LL l,LL r,LL p) {
    tree[k] += p * (r - l + 1);
    tree[k] %= MOD;
    tag[k] += p;
    tag[k] %= MOD; 
}

void f_2(LL k,LL l,LL r,LL p) {
    tree[k] *= p;
    tree[k] %= MOD;
    tag[k] *= p;
    tag[k] %= MOD;
    tag2[k] *= p;
    tag2[k] %= MOD;
}

void push_down(LL k,LL l,LL r) {
    LL mid = (l + r) >> 1;
    if(tag2[k] != 1) {
        f_2(ls(k),l,mid,tag2[k]);
        f_2(rs(k),mid + 1,r,tag2[k]);
        tag2[k] = 1;
    }
    if(tag[k]) {
        f(ls(k),l,mid,tag[k]);
        f(rs(k),mid + 1,r,tag[k]);
        tag[k] = 0;
    }
}

void build(LL k,LL l,LL r) {
    tag[k] = 0;
    tag2[k] = 1;
    if(l == r) {
        tree[k] = a[l];
        return ;
    }
    LL mid = (l + r) >> 1;
    build(ls(k),l,mid);
    build(rs(k),mid + 1,r);
    push_up(k);
}

void Update_Add(LL k,LL l,LL r,LL x,LL y,LL p) {
    if(y < l or x > r) return ;
    if(l >= x and r <= y) {
        tag[k] += p;
        tag[k] %= MOD;
        tree[k] += p * (r - l + 1);
        tree[k] %= MOD;
        return ;
    }
    push_down(k,l,r);
    LL mid = (l + r) >> 1;
    if(x <= mid) Update_Add(ls(k),l,mid,x,y,p);
    if(y > mid) Update_Add(rs(k),mid + 1,r,x,y,p);
    push_up(k);
} 

LL Query(LL k,LL l,LL r,LL x,LL y) {
    if(y < l or x > r) return 0;
    if(l >= x and r <= y) return tree[k];
    push_down(k,l,r);
    LL mid = (l + r) >> 1;
    LL res = 0;
    if(x <= mid) res = (res + Query(ls(k),l,mid,x,y)) % MOD;
    if(y > mid) res = (res + Query(rs(k),mid + 1,r,x,y)) % MOD;
    return res % MOD;	
}

void Update_Cheng(LL k,LL l,LL r,LL x,LL y,LL p) {
    if(y < l or x > r) return ;
    if(l >= x and r <= y) {
        tag[k] *= p;
        tag[k] %= MOD;
        tree[k] *= p;
        tree[k] %= MOD;
        tag2[k] *= p;
        tag2[k] %= MOD;
        return ;
    }
    push_down(k,l,r);
    LL mid = (l + r) >> 1;
    if(x <= mid) Update_Cheng(ls(k),l,mid,x,y,p);
    if(y > mid) Update_Cheng(rs(k),mid + 1,r,x,y,p);
    push_up(k); 
}

int main() {
    LL n,m;
    scanf("%lld%lld%lld",&n,&m,&MOD);
    for(int i = 1;i <= n;++i) scanf("%lld",a + i);
    build(1,1,n);
    for(int i = 1;i <= m;++i) {
        int t;
        scanf("%d",&t);
        if(t == 1) {
            LL x,y,p;
            cin >> x >> y >> p;
            Update_Cheng(1,1,n,x,y,p);
        } 
        if(t == 2) {
            LL x,y,p;
            cin >> x >> y >> p;
            Update_Add(1,1,n,x,y,p); 
        }
        if(t == 3) {
            LL x,y;
            cin >> x >> y;
            cout << Query(1,1,n,x,y) << endl;
        }
    }
    return 0;
}
