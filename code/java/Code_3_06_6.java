import java.util.*;

class Code_3_06_6 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int answer = func(N);
		System.out.println(answer);
	}
	static int func(int N) {
		// func(N) → func(N-1) → ... → func(0) → func(-1) → func(-2) → ... 會像這樣無限呼叫，程式無法正常運作
		return func(N - 1) * N;
	}
}
