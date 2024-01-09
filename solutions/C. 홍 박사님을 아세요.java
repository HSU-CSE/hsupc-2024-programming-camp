import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word = scanner.next();
        int cnt = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == 'H') {
                cnt++;
            }
        }
        System.out.println(cnt);
        scanner.close();
    }
}