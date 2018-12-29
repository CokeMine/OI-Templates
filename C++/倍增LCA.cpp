#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int MAXN = 10000005;
const int MAXM = 10000005;

int cnt,n,m,s;

struct node {
    int next,to;
};

int head[MAXN],deepth[MAXN],fa[MAXN][22],lg[MAXN];

node e[MAXM << 1];

inline void add(int from,int to) {
    e[++cnt].next = head[from];
    e[cnt].to = to;
    head[from] = cnt;
}

inline void dfs(int now,int f) {
    deepth[now] = deepth[f] + 1;
    fa[now][0] = f;
    for(int i = 1;(1 << i) <= deepth[now];++i) fa[now][i] = fa[fa[now][i - 1]][i - 1];
    for(int i = head[now];i;i = e[i].next) {
        int v = e[i].to;
        if(v != f) dfs(v,now);
    }
}

inline int get_lca(int x,int y) {
    if(deepth[x] < deepth[y]) swap(x,y);
    while(deepth[x] > deepth[y]) x = fa[x][lg[deepth[x] - deepth[y]] - 1];
    if(x == y) return x;
    for(int k = lg[deepth[x]];k >= 0;--k) if(fa[x][k] != fa[y][k]) x = fa[x][k],y = fa[y][k];
    return fa[x][0];
    
}

inline void Init() {
    for(int i = 1;i <= n;++i) lg[i] = lg[i >> 1] + 1;
}

int main() {
    scanf("%d%d%d",&n,&m,&s);
    for(int i = 1;i <= n - 1;++i) {
        int from,to;
        scanf("%d%d",&from,&to);
        add(from,to);
        add(to,from);
    } 
    Init();
    dfs(s,0);
    for(int i = 1;i <= m;++i) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",get_lca(x,y));
    }
    return 0;
}  
