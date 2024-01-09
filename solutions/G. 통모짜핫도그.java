import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int nextInt(StringTokenizer st) {
        return Integer.parseInt(st.nextToken());
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());

        sb.append("YES\n");
        StringTokenizer st = new StringTokenizer(br.readLine());
        int endPoint = nextInt(st) + nextInt(st);
        for (int repeat = 0; repeat < n - 1; repeat++) {
            st = new StringTokenizer(br.readLine());
            int s = nextInt(st);
            int b = nextInt(st);
            if (s >= endPoint) {
                sb.append("YES");
            } else {
                sb.append("NO");
            }
            endPoint = Math.max(endPoint, s + b);
            sb.append("\n");
        }
        
        System.out.println(sb);
    }
}
