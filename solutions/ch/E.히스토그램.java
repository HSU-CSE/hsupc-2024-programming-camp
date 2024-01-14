import java.util.Scanner;

// E. 히스토그램
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] arr = new int[N];
        int max = Integer.MIN_VALUE;
        String answer = "";
        for(int i = 0 ; i < N ; i ++){
            int input = sc.nextInt();
            max = Math.max(input, max);
            arr[i] = input;
        }
        for(int i = max ; i > 0 ; i --){
            for(int j = 0 ; j < N ; j ++){
                if(arr[j] >= i){
                    answer += arr[j];
                }
                else{
                    answer += " ";
                }
            }
            answer += "\n";
        }
        System.out.println(answer);
    }
}
