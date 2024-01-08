#include <stdio.h>
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
	int n, m; scanf("%d %d", &n, &m);
	char board[1002][1002];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", countFourDir(n, m, i, j, board));
		}
		printf("\n");
	}
	return 0;
}