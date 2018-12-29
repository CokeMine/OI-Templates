#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;


int gcd(int a,int b) {
	if(!b) return a;
	else return gcd(b,a % b);
}

int main() {
	int x,y;
	cin >> x >> y;
	cout << gcd(x,y) << endl;
}
