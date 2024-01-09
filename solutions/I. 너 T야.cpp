#include<iostream>

using namespace std;

int countFourDir(int n, int m, int x, int y, char board[][1002]) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] == 'T') ret++;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    char board[1002][1002];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> board[r][c];
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cout << countFourDir(n, m, r, c, board) << ' ';
        }
        cout << endl;
    }

    return 0;
}