package boj;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		int[][] arr = new int[5][5];
		boolean[][] chk = new boolean[5][5];
		int bingo = 0;

		Scanner sc = new Scanner(System.in);
		
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		
		for(int i = 0; i < 25; i++) {
			int num = sc.nextInt();

			for(int j = 0; j < 5; j++) {
				for(int k = 0; k < 5; k++) {
					if(arr[j][k] == num) {
						chk[j][k] = true;
						
						bingo += chkBingo(j, k, chk);

						if(bingo >= 3) {
							System.out.println(i + 1);
							sc.close();
							return;
						}
					}
				}
			}
		}
		
		sc.close();

	}
	
	static int chkBingo(int j, int k, boolean[][] chk) {
		return row(j, chk) + col(k, chk) + cross(j, k, chk);
	}
	
	static int row(int j, boolean[][] chk) {
		int cnt = 0;
		
		for(int i = 0; i < 5; i++) {
			if(chk[j][i]) cnt++;
		}

		if(cnt == 5) return 1;
		else return 0;
	}
	
	static int col(int k, boolean[][] chk) {
		int cnt = 0;
		
		for(int i = 0; i < 5; i++) {
			if(chk[i][k]) cnt++;
		}

		if(cnt == 5) return 1;
		else return 0;
	}
	
	static int cross(int j, int k, boolean[][] chk) {
		int cnt = 0;
		
		// 중앙이면 대각선 2개 확인
		if(j == 2 && k == 2) {
			int result = 0;
			
			for(int i = 0; i < 5; i++) {
				if(chk[i][i]) cnt++;
			}
			
			if (cnt == 5) result++;
			cnt = 0;

			for(int i = 0; i < 5; i++) {
				if(chk[i][4 - i]) cnt++;
			}
			
			if (cnt == 5) {
				result++;
				cnt = 0;
			}

			return result;
		}
		// 0,0 -> 4,4 방향 대각선 확인
		else if(j == k) {
			for(int i = 0; i < 5; i++) {
				if(chk[i][i]) cnt++;
			}

			if (cnt == 5) return 1;
			else return 0;
		}
		// 0,4 -> 4,0 방향 대각선 확인
		else if(j + k == 4) {
			for(int i = 0; i < 5; i++) {
				if(chk[i][4 - i]) cnt++;
			}

			if (cnt == 5) return 1;
			else return 0;
		}
		// 대각선 불가
		else {
			return 0;
		}
	}
	
}
