#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1000001;
const int MAXM = 2000001;
const int INF = 0x3f3f3f3f;
const int MOD = 100003;

struct node {
	int nxt,to;
};

node e[MAXM << 1];

int cnt;
int n,m;
int s = 1;
int head[MAXN],dis[MAXN],ans[MAXN],last[MAXN];
bool vis[MAXN];
queue <int> q;


void Dijkstra_Heap() {
	priority_queue <pair <int ,int > ,vector <pair <int ,int > >,greater <pair <int ,int > > > Q;
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0;
	ans[1] = 1;
	Q.push(make_pair(0,s));
	while(!Q.empty()) {
		int u = Q.top().second;
		Q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u];i;i = e[i].nxt) {
			int v = e[i].to;
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				ans[v] = ans[u];
				if(!vis[v]) Q.push(make_pair(dis[v],v));
			}
			else if(dis[v] == dis[u] + 1) {
				ans[v] += ans[u];
				ans[v] %= MOD;
			}
		}
	}
}

void add(int from,int to) {
	e[++cnt].nxt = head[from];
	e[cnt].to = to;
	head[from] = cnt;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;++i) {
		int from,to;
		scanf("%d%d",&from,&to);
		add(from,to);
		add(to,from);
	}
	Dijkstra_Heap();
	for(int i = 1;i <= n;++i)
		printf("%d\n",ans[i]);
	return 0;
} 

