package boj;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		char[] color = new char[5];
		int[] num = new int[5];
		
		int[] numChk = new int[10];
		int[] colorChk = new int[4]; // 0 : R / 1 : B / 2 : Y / 3 : G
		
		int max = 0;
		
		for(int i = 0; i < 5; i++) {
			String str = sc.next();
			color[i] = str.charAt(0);
			
			if(color[i] == 'R') colorChk[0]++;
			else if(color[i] == 'B') colorChk[1]++;
			else if(color[i] == 'Y') colorChk[2]++;
			else if(color[i] == 'G') colorChk[3]++;
			
			int n = sc.nextInt();
			num[i] = n;
			
			numChk[n]++;
			
			max = Math.max(max, n);
		}
		
		sc.close();
		
		// 연속 숫자 개수 확인
		int cont = 1;
		int maxCont = 0;
		for(int i = 1; i < 9; i++) {
			if(numChk[i] > 0 && numChk[i + 1] > 0) cont++;
			else {
				maxCont = Math.max(maxCont, cont);
				cont = 1;
			}
		}
		maxCont = Math.max(maxCont, cont);
		
		// 같은 숫자 개수 확인
		boolean doubleSame = false;
		boolean tripleSame = false;
		boolean quadSame = false;
		
		int quadNum = 0;
		int tripleNum = 0;
		int[] doubleNum = new int[2];
		
		for(int i = 1; i < 10; i++) {
			if(numChk[i] == 4) {
				quadSame = true;
				quadNum = i;
			}
			else if(numChk[i] == 3) {
				tripleSame = true;
				tripleNum = i;
			}
			else if(numChk[i] == 2) {
				doubleSame = true;
				if(doubleNum[0] > 0) doubleNum[1] = i;
				else doubleNum[0] = i;
			}
		}
		
		// 같은 색 확인
		boolean fullColor = false;
		for(int i = 0; i < 4; i++) {
			if(colorChk[i] == 5) { 
				fullColor = true;
				break;
			}
		}
		
		int score = 0;

		if(maxCont == 5 && fullColor) score = max + 900;
		else if(quadSame) score = quadNum + 800;
		else if(tripleSame && doubleSame) score = (10 * tripleNum) + doubleNum[0] + 700;
		else if(fullColor) score = max + 600;
		else if(maxCont == 5) score = max + 500;
		else if(tripleSame) score = tripleNum + 400;
		else if(doubleSame && doubleNum[1] > 0) score = (10 * doubleNum[1]) + doubleNum[0] + 300;
		else if(doubleSame) score = doubleNum[0] + 200;
		else score = max + 100;
		
		System.out.println(score);
	}
	
}
