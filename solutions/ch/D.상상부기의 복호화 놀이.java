import java.util.Scanner;

// D. 상상부기의 복호화 놀이
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int key = sc.nextInt() % 26;
        key *= -1;
        if(key < 0){
            key += 26;
        }
        sc.nextLine();
        String input = sc.nextLine();
        String answer = "";


        for(int i = 0 ; i < input.length() ; i ++){
            char enc = input.charAt(i);
            if(enc != ' '){
                char dec = (char)(enc + key > 'Z' ? 'A' + ((enc + key) % ('Z' + 1)) : enc + key);
                answer += dec;
            }
            else answer += ' ';
        }
        System.out.println(answer);
    }
}
