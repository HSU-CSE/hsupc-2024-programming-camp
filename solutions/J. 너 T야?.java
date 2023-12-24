import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
    static int N, M;

    // 배열의 범위를 넘어섰는지 확인하는 함수
    static boolean OOB(int y, int x){
        if(y >= 0 && y < N && x >= 0 && x < M) return false;
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
        for(int i = 0 ; i < N ; i ++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < M ; j ++){
                char mbti = st.nextToken().charAt(0);
                mbtiMap[i][j] = mbti;
            }
        }


        // 모든 칸을 탐색하면서 인접한 "T" 수 확인

        int[][] answer = new int[N][M]; // 인접한 "T"인 사람의 수

        for(int i = 0 ; i < N ; i ++){
            for(int j = 0 ; j < M ; j ++){
                int cur = 0; // 현재 칸의 인접한 "T"인 사람 수
                // 인접한 칸을 탐색
                for(int k = 0 ; k < 4 ; k ++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    // 배열의 범위를 넘어가지 않고, 인접한 사람이 "T"이면 결과 값 증가
                    if(!OOB(ny, nx) && mbtiMap[ny][nx] == 'T'){
                        cur ++;
                    }
                }
                answer[i][j] = cur; // 결과를 배열에 추가
            }
        }

        // 결과 값 배열을 Stringbuilder로 변경
        for(int i = 0 ; i < N ; i ++){
            for(int j = 0 ; j < M ; j ++){
                sb.append(answer[i][j] + " ");
            }
            sb.append("\n");
        }

        // 결과 값 출력
        System.out.println(sb);
    }
}
