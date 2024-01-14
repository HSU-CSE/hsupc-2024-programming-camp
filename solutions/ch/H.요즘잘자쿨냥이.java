import java.util.Scanner;

// H. 요즘잘자쿨냥이
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        char[][] map = new char[N][M];
        for(int i = 0 ; i < N ; i ++){
            for(int j = 0 ; j < M ; j ++){
                map[i][j] = sc.next().charAt(0);
            }
        }
        int answer = 0;

        for(int i = 0 ; i < N ; i ++){
            for(int j = 0 ; j < M ; j ++){
                if(map[i][j] == 'C'){
                    answer ++;
                }
            }
        }
        System.out.println(answer);
    }
}
