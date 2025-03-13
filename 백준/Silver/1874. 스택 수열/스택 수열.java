import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;


public class Main {
    public static void main(String[] args) throws IOException {
        // 입력
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] target = new int[n];
        // 배열 생성
        for (int i = 0; i < n; i++) {
            target[i] = scanner.nextInt();
        }

        // 스택 초기화. result 배열 초기화
        Stack<Integer> stack = new Stack<>();
        ArrayList<Character> result = new ArrayList<>();
        int number = 1, idx = 0;

        // 반복문
        do {
            // 스택이 비었거나, 타겟이 스택의 peek 보다 값이 높으면 삽입. + 연산
            if (stack.isEmpty() || target[idx] > stack.peek()) {
                stack.push(number++);   // 현재 number 삽입. number 1 증가 연산
                result.add('+');
                // 타겟이 스택의 peek 과 값이 같으면 빼기. - 연산
            } else if (target[idx] == stack.peek()) {
                stack.pop();
                result.add('-');
                // idx 1 증가 연산
                idx++;
            } else {
                System.out.println("NO");
                scanner.close();
                return;
            }
        } while (result.size() != n * 2);

        result.forEach(System.out::println);
        scanner.close();
    }

    // 한 줄에 여러 입력값이 있을 경우
    public static StringTokenizer tokenize(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        return st;
    }

}