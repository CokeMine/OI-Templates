#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
 
static const int MAXN = 31000015;
 
char s[MAXN];
char new_s[MAXN];
int p[MAXN];
 
int Init() {  //初始化并返回new_s长度 
	int len = strlen(s);
	new_s[0] = '$';
	new_s[1] = '#';
	int j = 2;
	for(int i = 0; i < len;++i) {
		new_s[j++] = s[i];
		new_s[j++] = '#';
	}
	new_s[j] = '\0';
	return j;
}
 
int Manacher() {
	int len = Init();
	int max_len = -1;
	int id = 0,mx = 0; 
	for(int i = 1;i < len;++i) {
		if(i < mx) p[i] = min(p[2 * id - i],mx - i); // 2 * id - i指i关于id的对称点j
		else p[i] = 1;
		while(new_s[i - p[i]] == new_s[i + p[i]]) p[i]++;
		if(mx < i + p[i]) {
			id = i;
			mx = i + p[i];
		}
		max_len = max(max_len,p[i] - 1);
	}
	return max_len;
}
 
int main() {
	scanf("%s",s);
	printf("%d\n",Manacher());
	return 0;
} 
