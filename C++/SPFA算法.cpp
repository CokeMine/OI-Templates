#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;

const int MAXN = 100005;
const int MAXM = 500005;

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

void Spfa() {
	queue <int > Q;
	Q.push(s);
	vis[s] = true;
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		vis[u] = false;
		for(int i = head[u];i;i = e[i].nxt) {
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].dis) {
				dis[v] = dis[u] + e[i].dis;
				if(!vis[v]) {
					Q.push(v);
					vis[v] = true;
				}
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
    Spfa();
    for(int i = 1;i <= n;++i) {
		if(dis[i] == INF) dis[i] = 2147483647;
		cout << dis[i] << " ";
	} 
    puts("");
    return 0;
}
