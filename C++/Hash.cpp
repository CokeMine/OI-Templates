#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

typedef unsigned long long LL;

const int MAXN = 10015;
const int Base = 131;
const int Prime = 19260817;
const LL MOD = 212370440130137957;


int n;
int ans = 1;

char s[MAXN];
LL a[MAXN];

LL hash(char* );

int main() {
    cin >> n;
    for(int i = 1;i <= n;++i) {
        scanf("%s",s);
        a[i] = hash(s);
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i < n;++i)
        if(a[i] != a[i + 1]) ans++;
    printf("%d\n",ans);
    return 0;
}
LL hash(char s[]) {
    int len = strlen(s);
    LL cnt = 0;
    for(int i = 0;i < len;++i)
        cnt = (cnt * Base + (LL)s[i]) % MOD + Prime;
    return cnt;
}
