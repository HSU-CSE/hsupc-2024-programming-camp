import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int nextInt(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        sb.append("YES\n");

        StringTokenizer st = new StringTokenizer(br.readLine());
        int endPoint = nextInt(st) + nextInt(st);
        for(int i=0;i<n-1;i++){
            st = new StringTokenizer(br.readLine());
            int s=nextInt(st);
            int b=nextInt(st);
            if(s>=endPoint)sb.append("YES\n");
            else sb.append("NO\n");
            endPoint=Math.max(endPoint,s+b);
        }
        System.out.println(sb.toString());
    }
}
