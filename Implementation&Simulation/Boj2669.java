package boj;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		boolean[][] arr = new boolean[101][101];
		int answer = 0;
		
		for(int i = 0; i < 4; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int d = sc.nextInt();
			
			for(int j = a; j < c; j++) {
				for(int k = b; k < d; k++) {
					arr[j][k] = true;
				}
			}
		}
		
		sc.close();
		
		for(int i = 1; i < 101; i++) {
			for(int j = 1; j < 101; j++) {
				if(arr[i][j]) answer++;
			}
		}
		
		System.out.println(answer);

	}
	
}
