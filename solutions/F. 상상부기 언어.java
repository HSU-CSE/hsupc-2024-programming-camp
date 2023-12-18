import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String word = br.readLine();//한줄 입력
        StringBuilder sb = new StringBuilder();//결과 쌓아놓기
        for(int i=0;i<word.length();i++){
            int value = word.charAt(i);
            if(value<=63)value-=32;
            value-=196;
            while(value<0)value+=127;
            sb.append((char)value);
        }
        System.out.println(sb);//한 번에 출력
    }
}