#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
/*

*/
using namespace std;
int countFourDir(int n, int m, int x, int y, char board[][1002]) {
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
		if (board[nx][ny] == 'T')ret++;
	}
	return ret;
}
int main() {
	fast;
	int n, m; cin >> n >> m;
	char board[1002][1002];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << countFourDir(n, m, i, j, board) << ' ';
		}
		cout << endl;
	}
	return 0;
}