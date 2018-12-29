#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

struct node {
	int nxt,to,dis;
};

int s,n,m,cnt,head[MAXN],dis[MAXN];
bool vis[MAXN];
node e[MAXM << 1];

void add(int from,int to,int dis) {
    e[++cnt].nxt = head[from];
    e[cnt].to = to;
    e[cnt].dis = dis;
    head[from] = cnt;
}

void Dijkstra() {
    memset(dis,0x3f,sizeof dis);
    dis[s] = 0;
    priority_queue <pair <int ,int >,vector <pair <int ,int > >,greater <pair <int ,int > > > Q;
    Q.push(make_pair(0,s));
    while(!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = head[u];i;i = e[i].nxt) {
            int v = e[i].to;
            if(dis[v] > dis[u] + e[i].dis) {
                dis[v] = dis[u] + e[i].dis;
                if(!vis[v]) Q.push(make_pair(dis[v],v));
            }
        }
    }
}

int main() {
	cin >> n >> m >> s;
	for(int i = 1;i <= m;++i) {
        int from,to,dis;
        scanf("%d%d%d",&from,&to,&dis);
        add(from,to,dis);
    }
    Dijkstra();
    for(int i = 1;i <= n;++i) cout << dis[i] << " ";
    puts("");
    return 0;
}
