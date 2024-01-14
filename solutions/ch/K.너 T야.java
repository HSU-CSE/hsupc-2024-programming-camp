import java.util.Scanner;

// K. 너 T야?
public class Main {

    static int[] dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
    static int N, M;
    static boolean OOB(int y, int x){
        if(y >= 0 && y < N && x >= 0 && x < M) return false;
        else return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        char[][] map = new char[N][M];
        int[][] answer = new int[N][M];
        for(int i = 0 ; i < N ; i ++){
            for(int j = 0 ; j < M ; j ++){
                map[i][j] = sc.next().charAt(0);
            }
        }

        for(int i = 0 ; i < N ; i ++){
            for(int j = 0 ; j < M ; j ++){
                int cnt = 0;
                for(int k = 0 ; k < 4 ; k ++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(!OOB(ny, nx) && map[ny][nx] == 'T'){
                        cnt ++;
                    }
                }
                answer[i][j] = cnt;
            }
        }

        String output = "";
        for(int i = 0 ; i < N ; i ++){
            for(int j = 0 ; j < M ; j ++){
                output += answer[i][j] + " ";
            }
            output += "\n";
        }
        System.out.println(output);
    }
}
