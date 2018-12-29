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
const int MAXM = 100005;

struct node {
    int nxt,to;
} e[MAXN << 1];

int cnt,cmt,n,m,dfn[MAXN],low[MAXN],head[MAXN],ans;
bool cut[MAXN];

void add(int from,int to) {
    e[++cnt].nxt = head[from];
    e[cnt].to = to;
    head[from] = cnt;
}
void Tarjan(int u,int fa) {
    dfn[u] = low[u] = ++cmt;
    int child = 0;
    for(int i = head[u];i;i = e[i].nxt) {
        int v = e[i].to;
        if(!dfn[v]) {
            Tarjan(v,fa);
            low[u] = min(low[u],low[v]);
            if(low[v] >= dfn[u] && u != fa) cut[u] = true;
            if(u == fa) child++;
        }
        else low[u] = min(low[u],dfn[v]);
    }
    if(u == fa && child >= 2) cut[fa]=true;
}

void work() {
    for(int i = 1;i <= n;++i)
        if(!dfn[i]) Tarjan(i,i);
    for(int i = 1;i <= n;++i) if(cut[i]) ans++;
    cout << ans << endl;
    for(int i = 1;i <= n;++i) if(cut[i]) cout << i << " ";
}

int main() {
    cin >> n >> m;
    for(int i = 1;i <= m;++i) {
        int from,to;
        cin >> from >> to;
        add(from,to);
        add(to,from); 
    }
    work();
    return 0;
}
