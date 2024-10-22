import java.util.*;

class Code_5_05_2 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] X = new int[N + 1];
		int[] Y = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			X[i] = sc.nextInt();
			Y[i] = sc.nextInt();
		}
		
		// 將左端x、右端x、下端y 和上端y 進行全搜尋（各自的編號為i,j,k,l）
		long answer = (1L << 62); // 設定成不可能的值
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {
					for (int l = 1; l <= N; l++) {
						int cl = X[i]; // 左端的 x 座標
						int cr = X[j]; // 右端的 x 座標
						int dl = Y[k]; // 下端的 y 座標
						int dr = Y[l]; // 上端的 y 座標
						if (check_numpoints(N, X, Y, cl, cr, dl, dr) >= K) {
							long area = (long)(cr - cl) * (dr - dl);
							answer = Math.min(answer, area);
						}
					}
				}
			}
		}
		
		// 輸出答案
		System.out.println(answer);
	}
	static int check_numpoints(int N, int[] X, int[] Y, int lx, int rx, int ly, int ry) {
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			// 判定長方形中是否包含點 (X[i],Y[i])
			if (lx <= X[i] && X[i] <= rx && ly <= Y[i] && Y[i] <= ry) {
				cnt += 1;
			}
		}
		return cnt;
	}
}
