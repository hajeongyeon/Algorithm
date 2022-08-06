import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int answer = 0;
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		boolean[][] chk = new boolean[n + 1][n + 1];

		for(int i = 0; i < m; i++) {
			int tmp1 = sc.nextInt();
			int tmp2 = sc.nextInt();
			
			chk[tmp1][tmp2] = true;
			chk[tmp2][tmp1] = true;
		}
		
		sc.close();
		
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(chk[i][j]) continue;
				
				for(int k = j + 1; k <= n; k++) {
					if(chk[i][k] || chk[j][k]) continue;
					
					answer++;
				}
			}
		}
		
		System.out.println(answer);
	}

}
