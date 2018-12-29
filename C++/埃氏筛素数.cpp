#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


bool is_prime(int x) {
	if(x == 1 || x == 0) return false;
	for(int i = 2;i * i <= x;++i)
		if(x % i == 0) return false;
	return true;
} 

int main() {
	int n;
	cin >> n;
	if(is_prime(n)) puts("Yes");
	else puts("No");
}
