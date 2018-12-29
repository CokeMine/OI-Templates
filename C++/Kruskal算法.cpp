#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

struct node{
    int x,y,w;
};
node a[MAXN];

int fa[5005],n,m,ans,cnt;

int find(int x){
    if(fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

bool cmp(node a,node b){
    return a.w < b.w; 
}

void Kruskal() {
	for(int i = 1;i <= n;i++)
        fa[i] = i;
    sort(a + 1,a + 1 + m,cmp);
    for(int i = 1;i <= m;++i){
        int fx = find(a[i].x);
		int fy = find(a[i].y);
        if(rand() & 1) swap(fx,fy);
        if(fx == fy) continue;
        ans += a[i].w;
        fa[fy] = fx;
        cnt++;
        if(cnt == n - 1) break;
    }
}

int main(){
    scanf ("%d%d",&n,&m);
    for(int i = 1;i <= m;++i)
    	scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
    Kruskal();
    printf("%d\n",ans);
    return 0;
}
