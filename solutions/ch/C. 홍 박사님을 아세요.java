import java.util.Scanner;

// C. 홍 박사님을 아세요?
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        int answer = 0;
        for(int i = 0 ; i < input.length() ; i += 4){
            if(input.charAt(i) == 'H'){
                answer ++;
            }
        }
        System.out.println(answer);
    }
}
