import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int W = scanner.nextInt();
        int B = scanner.nextInt();
        int M = scanner.nextInt();

        int result = W + B - M;
        
        System.out.println(result);

        scanner.close();
    }
}
