import java.util.*;
import java.io.*;

class Code_4_02_2 {
	public static void main(String[] args) throws IOException {
		// 輸入（由於是高速的輸入輸出，使用 BufferedReader 代替 Scanner）
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int Q = Integer.parseInt(st.nextToken());
		int[] L = new int[Q + 1];
		int[] R = new int[Q + 1];
		int[] X = new int[Q + 1];
		for (int i = 1; i <= Q; i++) {
			st = new StringTokenizer(buff.readLine());
			L[i] = Integer.parseInt(st.nextToken());
			R[i] = Integer.parseInt(st.nextToken());
			X[i] = Integer.parseInt(st.nextToken());
		}
		
		// 階差的計算
		int[] B = new int[N + 2];
		for (int i = 1; i <= N + 1; i++) {
			B[i] = 0;
		}
		for (int i = 1; i <= Q; i++) {
			B[L[i]] += X[i];
			B[R[i] + 1] -= X[i];
		}
		
		// 計算並輸出答案
		String answer = "";
		for (int i = 2; i <= N; i++) {
			if (B[i] > 0) answer += "<";
			if (B[i] == 0) answer += "=";
			if (B[i] < 0) answer += ">";
		}
		System.out.println(answer);
	}
}
