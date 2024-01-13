import java.util.Scanner;

// J. 세 정수
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        // C == 0 인 경우
        long answer = (2 * N + 1) * (2 * N + 1);
        int tmp = N / 2;
        answer += 2 * ((tmp * (2 * N + 1)) - (tmp * (tmp + 1) / 2));
        System.out.println(answer);
    }
}
