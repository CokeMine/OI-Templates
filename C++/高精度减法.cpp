#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

char x[100001],y[100001];
int a[100001],b[100001],c[100001];
bool vis;
int m,temp;

int main() {
    scanf("%s%s",&x,&y);
    int lena = strlen(x),lenb = strlen(y);
    for(int i = 0;i < lena;++i)
        a[lena - i - 1] = x[i] - '0';
    for(int i = 0;i < lenb;++i)
        b[lenb - i - 1]=y[i] - '0';
    if(lena > lenb) vis = 1;
    if(lena < lenb) vis = 0;
    if(lena == lenb) {
        string temp1 = x,temp2 = y;
        if(temp1 > temp2) vis = 1;
        if(temp1 == temp2) vis = 1;
        else vis = 0;
    }
    m = max(lena,lenb);
    if(vis) {
        for(int i = 0;i < m;++i)
        c[i]=a[i]-b[i];
    }
    else {
        for(int i = 0;i < m;++i)
        	c[i]=b[i]-a[i];
    }
    for(int i = 0;i <= m;++i) {
        if(c[i] < 0){
            c[i] += 10;
            c[i + 1]--;
        }
    }
    temp = m;
    for(int i = m;i >= 0;--i) {
        if(c[i]) break;
        temp--;
        if(i == 0 && c[i] == 0) {
            temp = 0;
            break;
        }
    }
    if(!vis) cout << "-";
    for(int i = temp;i >= 0;--i)
        cout << c[i];
    return 0;
}
