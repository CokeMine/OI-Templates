#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream> 
using namespace std;
 
const int MAXN = 100000;
int prime[MAXN],tot;
bool vis[MAXN];

void is_prime(int list) {
    memset(vis,true,sizeof vis);
    vis[0] = vis[1] = false;
    for(int i = 2;i <= list;++i){
        if(vis[i]) prime[++tot] = i;
        for(int j = 1;j <= list && i * prime[j] <= list;++j){
           vis[i * prime[j]] = false;
           if(i % prime[j] == 0) break;
        }
    }
}
 
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	is_prime(n);
	for(int i = 1;i <= m;++i){
		int x;
		scanf("%d",&x);
		if(vis[x]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
 

