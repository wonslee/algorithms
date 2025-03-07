import java.io.*;
import java.util.*;


public class Main {
    static StringBuilder sb = new StringBuilder();
    static int N;
    static int[][] cnt;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 테스트케이스
        int T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {
            N = Integer.parseInt(br.readLine());
            fib(N);
        }
        
        System.out.println(sb);
        br.close();
    }

    private static void fib(int N) throws IOException {
            cnt = new int[N+1][2];

            // DP 초기 설정
            cnt[0][0] = 1;
            cnt[0][1] = 0;
            if (N >= 1){
                cnt[1][0] = 0;
                cnt[1][1] = 1;
            }
            
            // 피보나치 DP
            for (int i=2; i<=N; i++) {
                cnt[i][0] = cnt[i-1][0] + cnt[i-2][0];
                cnt[i][1] = cnt[i-1][1] + cnt[i-2][1];
            }

            sb.append(cnt[N][0]).append(" ")
                    .append(cnt[N][1]).append("\n");
    }



    // 한 줄에 여러 입력값이 있을 경우
    public static StringTokenizer tokenize(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        return st;
    }

    // 여러 줄에 하나의 입력값씩 있을 경우
//    public static String readLine(BufferedReader br) throws IOException {
//
//    }
}