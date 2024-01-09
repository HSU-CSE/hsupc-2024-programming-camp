import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static final HashMap<String, Integer> map = new HashMap<>();

    public static class Error {
        private String time;
        private int user;

        public Error(String time, int user) {
            this.time = time;
            this.user = user;
        }

        public int getUser() {
            return user;
        }

        public String getTime() {
            return time;
        }
    }

    public static void errorAdd(List<Error> errors, Error newError, boolean[] Already) {
        int user = newError.getUser();
        if (Already[user]) return;
        errors.add(newError);
        Already[user] = true;
    }

    public static boolean make(String title, int user) {
        boolean is_valid = map.containsKey(title);
        map.put(title, user);
        if (is_valid) {
            return false;
        }

        return true;
    }

    public static boolean start(String title, int user) {
        int User = map.get(title);
        if (User != user) {
            return false;
        }

        return true;
    }

    public static boolean end(String title, int user) {
        int User = map.get(title);
        map.remove(title);
        if (User != user) {
            return false;
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer log;
        List<Error> errors = new ArrayList<>();
        boolean[] check = new boolean[10002];

        int n = Integer.parseInt(br.readLine());
        String title;
        for (int repeat = 0; repeat < n; repeat++) {
            boolean is_valid = true;
            log = new StringTokenizer(br.readLine());
            String time = log.nextToken();
            int user = Integer.parseInt(log.nextToken());
            String mode = log.nextToken();
            switch (mode) {
                case "make" -> {
                    title = log.nextToken();
                    is_valid = make(title, user);
                }
                case "start" -> {
                    title = log.nextToken();
                    is_valid = start(title, user);
                }
                case "into" -> {
                    title = log.nextToken();
                }
                case "end" -> {
                    title = log.nextToken();
                    is_valid = end(title, user);
                }
            }
            if (!is_valid) {
                errorAdd(errors, new Error(time, user), check);
            }
        }

        for (Error output : errors) {
            sb.append(output.getTime() + " " + output.getUser() + "\n");
        }

        System.out.println(sb);
        br.close();
    }
}