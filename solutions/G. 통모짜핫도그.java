import java.util.Scanner;

// G. 통모짜핫도그
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int endTime = -1;
        int answer = 0;
        for(int i = 0 ; i < N ; i ++){
            int start = sc.nextInt();
            int end = sc.nextInt();
            if(i == 0){
                endTime = end + start;
                answer ++;
            }
            else{
                if(start < endTime);
                else{
                    answer ++;
                    endTime = start + end;
                }
            }
        }
        System.out.println(answer);
    }
}
