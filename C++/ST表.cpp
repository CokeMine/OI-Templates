#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 10;

int Max[MAXN][22];
int Min[MAXN][22];
int lg[MAXN];

int n,m;

void Init() {
	lg[0] = -1;
	for(int i = 1;i <= n;++i) lg[i] = lg[i >> 1] + 1;
    for(int i = 1;i <= n;++i) scanf("%d",&Max[i][0]);
    for(int i = 1;i <= n;++i) Min[i][0] = Max[i][0];
    for(int j = 1;j <= 21;++j)
        for(int i = 1;i + (1 << j) - 1 <= n;++i) {
            Max[i][j] = max(Max[i][j - 1],Max[i + (1 << (j - 1))][j - 1]);
            Min[i][j] = min(Min[i][j - 1],Min[i + (1 << (j - 1))][j - 1]);
        }
}

int QueryMax(int l,int r) {
    int k = lg[r - l + 1];
    return max(Max[l][k],Max[r - (1 << k) + 1][k]);
}

int QueryMin(int l,int r) {
    int k = lg[r - l + 1];
    return min(Min[l][k],Min[r - (1 << k) + 1][k]);
}

int main() {
    scanf("%d%d",&n,&m);
    Init();
    for(int i = 1;i <= m;++i) {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",QueryMax(l,r));
    }
    return 0;
}
