package boj;

import java.util.Scanner;

public class Boj1157 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		sc.close();
		
		int[] apb = new int[26];
		int maxCnt = 0;
		char maxApb = ' ';
		
		for(int i = 0; i < str.length(); i++) {
			int num = str.charAt(i);

			if(65 <= num && num <= 90) {	// 대문자
				apb[num - 65]++;
				maxCnt = Math.max(maxCnt, apb[num - 65]);
			}
			else {							// 소문자
				apb[num - 97]++;
				maxCnt = Math.max(maxCnt, apb[num - 97]);
			}
		}

		for(int i = 0; i < 26; i++) {
			if(apb[i] == maxCnt) {
				if(maxApb != ' ') {
					System.out.println("?");
					return;
				}
				else {
					maxApb = (char)(i + 65);
				}
			}
		}
		
		System.out.println(maxApb);
	}

}
