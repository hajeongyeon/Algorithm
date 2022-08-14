package boj;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int[][] arr = new int[n][m];
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		
		BFS(n, m, arr);

		sc.close();

	}
	
	public static class Pair {
        int x, y;
        
        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
        
        public int getX(){
            return x;
        }
        
        public int getY(){
            return y;
        }
        
        public void setX(int x){
            this.x = x;
        }
        
        public void setY(int y){
            this.y = y;
        }
        
    }
	
	static void BFS(int n, int m, int[][] arr) {
		boolean[][] visited = new boolean[n][m];
		Queue<Pair> queue = new LinkedList<Pair>();
		
		int[] dx = new int[] {1, -1, 0, 0};
		int[] dy = new int[] {0, 0, 1, -1};
		
		int cnt = 0;
		int area = 0;
		int max = 0;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				
				if(visited[i][j] || arr[i][j] == 0) continue;
				
				area = 0;
				cnt++;
				
				queue.offer(new Pair(i, j));
				visited[i][j] = true;
				
				while(!queue.isEmpty()) {
					Pair p = queue.poll();
					area++;
					
					for(int k = 0; k < 4; k++) {
						int nx = p.x + dx[k];
						int ny = p.y + dy[k];
						
						if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						
						if(arr[nx][ny] == 1 && !visited[nx][ny]) {
							queue.offer(new Pair(nx, ny));
							visited[nx][ny] = true;
						}
					}
				}
				
				if(area > max) max = area;
			}
		}
		
		System.out.println(cnt);
		System.out.println(max);
	}
	
}
