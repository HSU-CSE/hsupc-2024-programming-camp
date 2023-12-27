#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
using namespace std;

int main() {
	fast;
	int n; cin >> n;
	int a, b; cin >> a >> b; 
	cout << "YES" << endl;
	int endPoint = a + b;

	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		if (a >= endPoint)cout << "YES" << endl;
		else cout << "NO" << endl;
		endPoint = max(endPoint, a + b);
	}
	return 0;
}