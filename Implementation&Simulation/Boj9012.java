import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		
		for(int i = 0; i < n; i++) {
			String str = sc.next();
			boolean flag = false;
			
			Stack<Character> st = new Stack<>();
			
			for(int j = 0; j < str.length(); j++) {
				if(str.charAt(j) == '(') {
					st.push('(');
				}
				else {
					if(st.empty()) {
						flag = true;
						break;
					}
					
					st.pop();
				}
			}
			
			if(!st.empty()) flag = true;
			
			if(flag) System.out.println("NO");
			else System.out.println("YES");
		}
		
		sc.close();
		
	}

}
