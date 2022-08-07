package boj;

import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		while(sc.hasNextLine()) {
			boolean flag = false;
			String str = sc.nextLine();
			
			if(str.equals(".")) break;
			
			Stack<Character> st = new Stack<Character>();
			
			for(int i = 0; i < str.length(); i++) {
				if(str.charAt(i) == '[' || str.charAt(i) == '(') 
					st.push(str.charAt(i));
				else if(str.charAt(i) == ']') {
					if(st.empty()) {
						flag = true;
						break;
					}
					
					char tmp = st.pop();
					
					if(tmp != '[') { 
						flag = true;
						break;
					}
				}
				else if(str.charAt(i) == ')') {
					if(st.empty()) {
						flag = true;
						break;
					}
					
					char tmp = st.pop();
					
					if(tmp != '(') { 
						flag = true;
						break;
					}
				}
			}
			
			if(!st.empty()) 
				flag = true;
			
			if(flag) System.out.println("no");
			else System.out.println("yes");
		}
		
		sc.close();
		
	}

}
