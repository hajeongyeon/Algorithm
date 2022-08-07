package boj;

import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	
	static int F, S, G, U, D;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		F = sc.nextInt();
		S = sc.nextInt();
		G = sc.nextInt();
		U = sc.nextInt();
		D = sc.nextInt();
		
		sc.close();
		
		boolean[] visited = new boolean[F + 1];
		int[] arr = new int[F + 1];
		
		BFS(visited, arr);
		
	}
	
	static void BFS(boolean[] visited, int[] arr) {
		
		LinkedList<Integer> q = new LinkedList<Integer>();
		
		q.push(S);
		visited[S] = true;
		
		while(!q.isEmpty()) {
			int now = q.poll();

			if(now == G) {
				System.out.println(arr[now]);
				return;
			}
			
			int down = now - D;
			int up = now + U;

			if(down > 0 && !visited[down]) {
				q.add(down);
				arr[down] = arr[now] + 1;
				visited[down] = true;
			}
			
			if(up <= F && !visited[up]) {
				q.add(up);
				arr[up] = arr[now] + 1;
				visited[up] = true;
			}
		}
		
		System.out.println("use the stairs");
	}

}
