import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        StringBuilder sb = new StringBuilder();
        sb.append("YES\n");
        int endPoint = s.nextInt() + s.nextInt();
        for(int i=0;i<n-1;i++){
            int a=s.nextInt();
            int b=s.nextInt();
            if(a>=endPoint)sb.append("YES\n");
            else sb.append("NO\n");
            endPoint=Math.max(endPoint,a+b);
        }
        System.out.println(sb.toString());
    }
}
