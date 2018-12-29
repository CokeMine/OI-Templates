#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;


const int MAXN = 100005; 
const int MAXM = 500005;

struct node {
    int nxt,to;
} e[MAXN];

int cnt,num,n,m,dfn[MAXN],low[MAXN],head[MAXN],ans;
int cut[MAXN],a[MAXN],color[MAXN];
int f[MAXN];
int x[MAXN],y[MAXN];
int tot;
bool vis[MAXN];

stack<int > s;

void add(int from,int to) {
    e[++cnt].nxt = head[from];
    e[cnt].to = to;
    head[from] = cnt;
}

void Tarjan(int u) {
    dfn[u] = low[u] = ++num;
    s.push(u);
    vis[u] = true;
    for(int i = head[u];i;i = e[i].nxt) {
        int v = e[i].to;
        if(!dfn[v]) {
            Tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(vis[v]) low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u] == low[u]) {
        tot++;
        while(s.top() != u) {
            int k = s.top();
            s.pop();
            vis[k] = false;
            color[k] = tot;
            cut[tot] += a[k];
        }
        s.pop();
        color[u] = tot;
        cut[tot] += a[u];
        vis[u] = false;
    }
}

void search(int u) {
    if(f[u]) return ;
    f[u] = cut[u];
    int Max = 0;
    for(int i = head[u];i;i = e[i].nxt) {
        int v = e[i].to;
        if(!f[v]) search(v);
        Max = max(Max,f[v]);
    }
    f[u] += Max;
}

void work() {
    for(int i = 1;i <= n;++i)
        if(!dfn[i]) Tarjan(i);
    memset(e,0,sizeof e);
    memset(head,0,sizeof head);
    cnt = 0;
    for(int i = 1;i <= m;++i)
        if(color[x[i]] != color[y[i]]) add(color[x[i]],color[y[i]]);
    for(int i = 1;i <= tot;++i)
        if(!f[i]) {
            search(i);
            ans = max(ans,f[i]);
        }
    printf("%d\n",ans);
}

int main() {
    cin >> n >> m;
    for(int i = 1;i <= n;++i) cin >> a[i];
    for(int i = 1;i <= m;++i) {
        cin >> x[i] >> y[i];
        add(x[i],y[i]);
    }
    work();
    return 0;
}
