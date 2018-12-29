#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1000005;
const int MAXM = 1000005;

char a[MAXN],b[MAXM];
int next[MAXM];

int lena,lenb;

void kmp1() {
    int j = 0;
    for(int i = 2;i <= lenb;++i) {
        while(j && b[j + 1] != b[i]) j = next[j];
        if(b[j + 1] == b[i]) j++;
        next[i] = j;
    }
}

void kmp2() {
    int j = 0;
    for(int i = 1;i <= lena;++i) {
        while(j && b[j + 1] != a[i]) j = next[j];
        if(b[j + 1] == a[i]) j++;
        if(j == lenb) {
            cout << i - lenb + 1 <<endl;
            j = next[j];
        }
    }
}

int main() {
    scanf("%s%s",a + 1,b + 1);
    lena = strlen(a + 1);
    lenb = strlen(b + 1);
    kmp1();
    kmp2();
    for(int i = 1;i <= lenb;++i) cout << next[i] << " ";
}
