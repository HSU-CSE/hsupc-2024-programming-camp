import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int N;
    static int M;

    // 배열의 범위를 넘어섰는지 확인하는 함수
    static boolean OOB(int y, int x) {
        if (y >= 0 && y < N && x >= 0 && x < M) return false;
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder(); // 출력할 결과 표

        char[][] mbtiMap = new char[N][M]; // MBTI 표

        // 입력 값 받기
        for (int r = 0; r < N; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < M; c++) {
                char mbti = st.nextToken().charAt(0);
                mbtiMap[r][c] = mbti;
            }
        }


        // 모든 칸을 탐색하면서 인접한 "T" 수 확인

        int[][] answer = new int[N][M]; // 인접한 "T"인 사람의 수

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                int cur = 0; // 현재 칸의 인접한 "T"인 사람 수
                // 인접한 칸을 탐색
                for (int index = 0; index < 4; index++) {
                    int ny = r + dy[index];
                    int nx = c + dx[index];
                    // 배열의 범위를 넘어가지 않고, 인접한 사람이 "T"이면 결과 값 증가
                    if (!OOB(ny, nx) && mbtiMap[ny][nx] == 'T') {
                        cur++;
                    }
                }
                answer[r][c] = cur; // 결과를 배열에 추가
            }
        }

        for (int r = 0; r < N; r++) {
            for (int j = 0; j < M; j++) {
                sb.append(answer[r][j]).append(" ");
            }
            sb.append("\n");
        }

        // 결과 값 출력
        System.out.println(sb);
        br.close();
    }
}
