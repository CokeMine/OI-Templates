#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream> 
using namespace std;
 
const int MAXN = 100000;
int prime[MAXN],tot;
bool vis[MAXN];

void get_phi(int list) {
    memset(vis,true,sizeof vis);
    vis[0] = vis[1] = false;
    phi[1] = 1;
    for(int i = 2;i <= list;++i){
        if(vis[i]) prime[++tot] = i,phi[i] = i - 1;
        for(int j = 1;j <= list && i * prime[j] <= list;++j){
           vis[i * prime[j]] = false;
           if(i % prime[j]) phi[i * prime[j]] = phi[i] * (prime[j] - 1);
           else {
           		phi[i * prime[j]] = phi[i] * prime[j];
           		break;
			}
        }
        phi[i] += phi[i - 1]; 
    }
}
 
int main() {
	int n;
	scanf("%d%d",&n);
	get_phi(n);
	return 0;
}
 

