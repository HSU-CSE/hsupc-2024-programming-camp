import java.util.Scanner;

// B. 뽀삐뽀삐뽀 뽀삐뽀
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int W = sc.nextInt();
        int B = sc.nextInt();
        int M = sc.nextInt();

        int answer = W + B - M;
        System.out.println(answer);
    }
}
