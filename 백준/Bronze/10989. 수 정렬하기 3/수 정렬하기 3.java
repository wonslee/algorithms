import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        // N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
        //첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.
        final int MIN = 1;
        final int MAX = 10_000_001;
        int N = Integer.parseInt(br.readLine());
        int[] inputs = new int[N];
        int[] counts = new int[10_000_001];

        for (int i = 0; i < N; i++) {
            int input = Integer.parseInt(br.readLine());
            inputs[i] = input;
        }

        // 버퍼 리더 닫기 (왜? 성능 때문에?)
        br.close();

        // 인풋 배열을 돌면서, 카운트 배열의 각 칸에 해당하는 만큼 + 1
        // 시간 복잡도 = O(N)
        for (int i = 0; i < N; i++) {
            counts[inputs[i]]++;
        }

        for (int i = MIN; i < MAX; i++) {
            for (int j = 0; j < counts[i]; j++) {   // count만큼 반복
                sb.append(i).append("\n");
            }
        }

        System.out.print(sb);
    }

}