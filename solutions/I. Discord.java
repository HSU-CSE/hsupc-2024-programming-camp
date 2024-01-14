import java.util.Scanner;

// I. Discord
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();
        int answer = 0;
        for(int i = 0 ; i < N ; i ++){
            String input = sc.nextLine();
            char pre = ' ';
            boolean flag = true;
            for(int j = 0 ; j < input.length(); j ++){
                char cur = input.charAt(j);
                if(j == 0) {
                    pre = cur;
                    continue;
                }
                else{
                    int dif = pre > cur ? (cur + 7) - pre : cur - pre;
                    if(dif != 2 && dif != 4 && dif != 6){
                        flag = false;
                        break;
                    }
                }
                pre = cur;
            }
            if(!flag) answer ++;
        }
        System.out.println(answer);
    }
}
