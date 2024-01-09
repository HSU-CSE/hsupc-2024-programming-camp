import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int nextInt(StringTokenizer st) {
        return Integer.parseInt(st.nextToken());
    }

    static int upperBound(int target, int[] array, int size) {
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (array[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int n = nextInt(st);
        int m = nextInt(st);

        int[] cats = new int[n];
        st = new StringTokenizer(br.readLine());

        for (int index = 0; index < n; index++) {
            cats[index] = nextInt(st);
        }

        int[] students = new int[m];
        st = new StringTokenizer(br.readLine());

        for (int index = 0; index < m; index++) {
            students[index] = nextInt(st);
        }

        Arrays.sort(students);

        for (int index = 0; index < n; index++) {
            int target = cats[index];
            int count = upperBound(target, students, m);
            sb.append(count).append(" ");
        }

        System.out.println(sb);
        br.close();
    }
}
