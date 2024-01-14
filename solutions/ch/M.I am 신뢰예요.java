import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

// M. I am 신뢰예요
public class Main {

    static int M;
    static int UpperBound(List<Integer> students, int target) {
        int lt = 0;
        int rt = M;
        while (lt < rt) {
            int mid = lt + (rt - lt) / 2;

            if (students.get(mid) <= target) {
                lt = mid + 1;
            } else {
                rt = mid;
            }
        }
        return lt;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        M = sc.nextInt();
        ArrayList<Integer> cats = new ArrayList<>();
        ArrayList<Integer> students = new ArrayList<>();
        for(int i = 0 ; i < N ; i ++){
            cats.add(sc.nextInt());
        }

        for(int i = 0 ; i < M ; i ++){
            students.add(sc.nextInt());
        }

        Collections.sort(students);
        String answer = "";
        for(int i = 0 ; i < N ; i ++) {
            answer += UpperBound(students, cats.get(i)) + " ";
        }
        System.out.println(answer);
    }
}
