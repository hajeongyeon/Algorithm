import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class info {
	int x, y;
	
	info(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Main {
	
	static int n, m;
	
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	
	static int[][] board;
	
	static Queue<info> tmt;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		m = sc.nextInt();
		n = sc.nextInt();
		
		board = new int[n][m];
		tmt = new LinkedList<info>();

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				board[i][j] = sc.nextInt();

				if (board[i][j] == 1) tmt.add(new info( i, j ));
			}
		}
		
		sc.close();
		
		System.out.println(BFS());
		
	}
	
	public static int BFS() {
		while (!tmt.isEmpty())
		{
			info tmp = tmt.remove();
			
			int x = tmp.x;
			int y = tmp.y;

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

				if(board[nx][ny] == 0) {
					tmt.add(new info(nx, ny));
					board[nx][ny] = board[x][y] + 1;
				}
				
			}
		}
		
		int answer = Integer.MIN_VALUE;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (board[i][j] == 0) return -1;
				
				answer = Math.max(answer, board[i][j]);
			}
		}

		if(answer == 1) return 0;
		else return answer - 1;
	}
	
}
