import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


// 1번 upperBound 구현 코드
public class Main {
    static int nextInt(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
    static int upperBound(int target,int[] array,int size){
        int left=0,right = size-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(array[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int n = nextInt(st);
        int m = nextInt(st);

        int[] cats = new int[n];
        st = new StringTokenizer(br.readLine());
        
        for(int i=0;i<n;i++)
            cats[i] = nextInt(st);

        int[] students = new int[m];
        st = new StringTokenizer(br.readLine());
        
        for(int i=0;i<m;i++)
            students[i] = nextInt(st);
        
        Arrays.sort(students);

        for(int i=0;i<n;i++){
            int target = cats[i];
            int cnt = upperBound(target,students,m);
            sb.append(cnt).append(" ");
        }
        System.out.println(sb.toString());
    }
}
