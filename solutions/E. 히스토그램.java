import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int n = scanner.nextInt();
        int[] array = new int[n];
        
        int maxHeight = 0;
        for (int index = 0; index < n; index++) {
            array[index] = scanner.nextInt();
            maxHeight = Math.max(maxHeight, array[index]);
        }

        for (int height = maxHeight; height >= 1; height--) {
            for (int index = 0; index < n; index++) {
                String output;
                if (array[index] >= height) {
                    output = String.valueOf(array[index]);
                } else {
                    output = " ";
                }
                sb.append(output);
            }
            sb.append("\n");
        }
        System.out.println(sb);
        scanner.close();
    }
}
