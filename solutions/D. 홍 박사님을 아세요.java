import java.util.Scanner;

public class Main {
  static boolean compare(String word, int idx) {
    String words = "Hong";
    int i = idx;
    for (; i - idx < words.length() && i < word.length(); i++) {
      if (words.charAt(i - idx) != word.charAt(i))
        return false;
    }
    if (i != idx + 4)
      return false;
    return true;
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    String word = s.next();
    int cnt = 0;
    for (int i = 0; i < word.length(); i++) {
      if (word.charAt(i) == 'H') {
        boolean ret = compare(word, i);
        if (ret) {
          i += 3;
          cnt++;
        }
      }
    }
    System.out.println(cnt);
  }
}