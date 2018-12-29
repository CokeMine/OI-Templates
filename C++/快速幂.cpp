#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
LL b,p,k;
LL power(LL a,LL b) {
    LL t = 1,y = a;
    while(b) {
        if (b & 1) t = t * y % k;
        y = y * y % k;
        b >>= 1;
	}
  return t; 
} 
int main() {
    cin >> b >> p >> k;
    cout << b << "^" << p << " mod " << k << "=" << power(b,p) << endl;
    return 0;
}
