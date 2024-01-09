import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static final int ALPHABET_SIZE = 26;
    static int key;
    static String word;
    static StringBuilder sb;

    public static void solve1() {
        //모듈러 연산으로 최적화 해준다.
        if (key >= 0) {
            key = key % ALPHABET_SIZE;
        } else {
            key = Math.abs(key) % ALPHABET_SIZE * -1;
        }

        for (int index = 0; index < word.length(); index++) {
            if (word.charAt(index) == ' ') {
                sb.append(' ');
                continue;
            }
            int output = word.charAt(index);
            output -= key;
            //벗어났을 때 처리
            if (output < 'A') output += ALPHABET_SIZE;
            else if (output > 'Z') output -= ALPHABET_SIZE;
            sb.append((char) output);
        }

        System.out.println(sb);
    }

    public static char Decryption(char src, int key) {
        int ret = src;

        for (int repeat = 0; repeat < Math.abs(key); repeat++) {
            if (key < 0) {
                ret++;
            } else {
                ret--;
            }
            if (ret > 'Z') {
                ret -= ALPHABET_SIZE;
            } else if (ret < 'A') {
                ret += ALPHABET_SIZE;
            }
        }

        return (char) ret;
    }

    public static void solve2() {
        for (int index = 0; index < word.length(); index++) {
            if (word.charAt(index) == ' ') {
                sb.append(' ');
                continue;
            }
            char ret = Decryption(word.charAt(index), key);
            sb.append(ret);
        }

        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        key = Integer.parseInt(br.readLine());
        word = br.readLine();
        sb = new StringBuilder();
        solve1();
        br.close();
    }
}