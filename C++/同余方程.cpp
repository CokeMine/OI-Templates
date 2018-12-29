#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef long long LL;

int a,b,x,y,d;

void ex_gcd(int& ,int& ,int ,int );
void ex_gcd_work();
int euler(int );
LL fast_pow(LL ,LL ,LL );
void euler_work();

int main() {
    cin >> a >> b;
    //ex_gcd_work();
    euler_work();
}

void ex_gcd(int &x,int &y,int a,int b) {
    if(b == 0) {
        y = 0;
        x = 1;		
    }
    else {
        ex_gcd(y,x,b,a % b);
        y -= x * (a / b);
    }
}
void ex_gcd_work() {
    ex_gcd(x,y,a,b);
    cout << (x + b) % b << endl;
}
int euler(int n) {
    int res = n;
    for(int i = 2;i * i <= n;++i) {
        if(n % i == 0) res = res / i * (i - 1);
        while(n % i == 0) n /= i;
    }
    if(n > 1) res = res / n * (n - 1);
    return res;
}
LL fast_pow(LL a,LL b,LL MOD) {
    LL res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res % MOD;
}
void euler_work() {
    int e = euler(b) - 1;
    cout << fast_pow(a,e,b) << endl;
}
