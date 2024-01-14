import java.util.Scanner;

// F. 꼬꼬는 꾸꾸를 만나고싶어
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        String answer = "";
        while(T -- > 0){
            int x = sc.nextInt();
            int y = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            answer += (y - x) % (a + b) == 0 ? (y - x) / (a + b) : -1;
            answer += "\n";
        }
        System.out.println(answer);
    }
}
