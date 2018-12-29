#include<cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
char a1[1001],b1[1001];
int a[1001],b[1001];
int c[1001];
int m;
int main() {
    scanf("%s%s",&a1,&b1);
    if(a1[0] == '0' && b1[0] == '0') {
        cout << "0";
        return 0;
    }
    for(int i = 0;i < strlen(a1);++i)
        a[strlen(a1) - i - 1] = a1[i] - '0';
    for(int i = 0;i < strlen(b1);++i)
        b[strlen(b1) - i - 1] = b1[i] - '0';
    m = max(strlen(a1),strlen(b1));
    for(int i = 0;i < m;++i)
        c[i] = a[i] + b[i];
    for (int i = 0;i <= m;++i) {
        c[i + 1] = c[i + 1] + c[i] / 10;
        c[i] = c[i] % 10;
    }
    m++;
    while(!c[m]) m--;
    for(int i = m;i >= 0;--i)
        cout << c[i];
    return 0;
}
