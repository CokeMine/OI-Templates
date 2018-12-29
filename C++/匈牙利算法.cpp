#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
const int MAXM = 1e8;
const int MAXN = 1005;
 
struct node {
	int to,next;
};
 
node e[MAXM];
 
bool used[MAXN];
int head[MAXN],cnt,n,m,ee,Ans,Matched[MAXN];
 
void add(int from,int to) {
	e[++cnt].next = head[from];
	e[cnt].to = to;
	head[from] = cnt;
}
 
inline bool dfs(int u) {
	for(int i = head[u];i;i = e[i].next) {
		int v = e[i].to;
		if(!used[v]) {
			used[v] = true;
			if(!Matched[v] || dfs(Matched[v])) {
				Matched[v] = u;
				return true;
			}
		}
	}
	return false;
}
 
int main() {
	cin >> n >> m >> ee;
	for(int i = 1;i <= ee;++i) {
		int from,to;
		cin >> from >> to;
		if(from > n or to > m) continue;
		add(from,to);
	}
	for(int i = 1;i <= n;++i) {
		memset(used,false,sizeof used);
		if(dfs(i)) Ans++;
	}
	cout << Ans << endl;
	return 0;
}
