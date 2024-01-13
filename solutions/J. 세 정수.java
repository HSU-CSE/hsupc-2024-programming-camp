import java.util.Scanner;

// J. 세 정수
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        // C == 0 인 경우
        long answer = (2 * N + 1) * (2 * N + 1);
        int tmp = N / 2;
        for(int a = -N ; a <= N ; a ++){
            for(int b = -N ; b <= N ; b ++){
                int c = -2 * (a + b);
                if(c <= N && c >= -N && c != 0){
                    answer ++;
                }
            }
        }
        System.out.println(answer);
    }
}