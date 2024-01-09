import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word = scanner.next();
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == 'H') {
                count++;
            }
        }
        System.out.println(count);
        scanner.close();
    }
}