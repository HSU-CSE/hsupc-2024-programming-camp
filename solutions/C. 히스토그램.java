import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int n = s.nextInt();
        int[] array = new int[n];
        int maxHeight = 0;
        for(int i=0;i<n;i++){
            array[i] = s.nextInt();
            maxHeight = Math.max(maxHeight,array[i]);
        }

        for(int height = maxHeight; height>0;height--){
            for(int index=0;index<n;index++){
                String output = " ";
                if(array[index]>=height){
                    output = array[index] + "";
                }
                sb.append(output);
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());
        s.close();
    }
}
