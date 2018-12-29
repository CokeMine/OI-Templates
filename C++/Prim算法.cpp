#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

static const int MAXN = 5005;
static const int MAXM = 200005;

struct node {
    int next,to,dis;
};

node e[MAXM << 1];

int head[MAXN],vis[MAXN],dis[MAXN];
int n,m,cnt,num,sum;

inline void add(int from,int to,int dis) {
    e[++cnt].next = head[from];
    e[cnt].to = to;
    e[cnt].dis = dis;
    head[from] = cnt;
}

void Prim_Heap(int s) {
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    priority_queue <pair <int ,int >, vector < pair <int ,int > >, greater < pair <int ,int > > > Q;
    dis[s] = 0;
    Q.push(make_pair(0,s));
    while(!Q.empty()) {
        int u = Q.top().second;
        int d = Q.top().first;
        Q.pop();
        if(vis[u]) continue;
        num++;
        sum += d; 
        vis[u] = true;
        for(int i = head[u];i;i = e[i].next) {
            int v = e[i].to;
            if(dis[v] > e[i].dis) {
                dis[v] = e[i].dis;
                Q.push(make_pair(dis[v],v));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1;i <= m;++i) {
        int from,to,dis;
        cin >> from >> to >> dis;
        add(from,to,dis);
        add(to,from,dis);
    }
    Prim_Heap(1);
    if(num == n) printf("%d\n",sum);
    else puts("orz");
    return 0;
} 
