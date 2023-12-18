import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int key = Integer.parseInt(br.readLine());
        String word = br.readLine();
        StringBuilder sb = new StringBuilder();
        //모듈러 연산으로 최적화 해준다.
        if(key>=0)key%=26;
        else key = -((-key)%26);
        for(int i=0;i<word.length();i++){
            if(word.charAt(i)== ' ') {
                sb.append(' ');
                continue;
            }
            int output = word.charAt(i);
            output-=key;
            //벗어났을 때 처리
            if(output<65)output+=26;
            else if(output>90)output-=26;
            sb.append((char)output);
        }
        System.out.println(sb);
    }
}