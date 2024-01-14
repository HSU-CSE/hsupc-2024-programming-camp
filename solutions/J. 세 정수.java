import java.util.Scanner;

public class Main {
    public static void solve1(int N) {
        // C == 0 인 경우
        long answer = (2 * N + 1) * (2 * N + 1);
        int tmp = N / 2;
        for (int a = -N; a <= N; a++) {
            for (int b = -N; b <= N; b++) {
                int c = -2 * (a + b);
                if (c <= N && c >= -N && c != 0) {
                    answer++;
                }
            }
        }
        System.out.println(answer);
    }

    public static void solve2(int N) {
        // C == 0 인 경우
        long answer = (2 * N + 1) * (2 * N + 1);
        int tmp = N / 2;
        answer += 2 * ((tmp * (2 * N + 1)) - (tmp * (tmp + 1) / 2));
        System.out.println(answer);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        solve1(N);
        sc.close();
    }
}