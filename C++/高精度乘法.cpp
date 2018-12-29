#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int a[10001],b[10001],c[10001];
char x[10001],y[10001];

int main() {
    scanf("%s%s",&x,&y);
    int lena = strlen(x),lenb = strlen(y);
    for(int i = 0;i < lena;++i)
        a[lena - i - 1] = x[i] - '0';
    for(int i = 0;i < lenb;++i)
        b[lenb - i - 1] = y[i] - '0';
    for(int i = 0;i < lena;++i)
        for(int j = 0;j < lenb;++j) {
            c[i + j] += a[i] * b[j];
            c[i + j + 1] += c[i+j] / 10;
            c[i + j] %= 10;
        }	    
    int lenc = lena + lenb;
    while(lenc > 1 && c[lenc - 1] == 0) lenc--;
    lenc--;
    for(int i = lenc;i >= 0;--i)
        cout << c[i];
    return 0;	
}

