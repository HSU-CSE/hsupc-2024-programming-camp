#include <stdio.h>

int countFourDir(int n, int m, int x, int y, char board[][1002]) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int ret = 0;
    for (int index = 0; index < 4; index++) {
        int nx = x + dx[index];
        int ny = y + dy[index];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] == 'T') ret++;
    }

    return ret;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    char board[1002][1002];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            scanf(" %c", &board[r][c]);
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            printf("%d ", countFourDir(n, m, r, c, board));
        }
        printf("\n");
    }
    return 0;
}