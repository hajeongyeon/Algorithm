import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int num = sc.nextInt();
		int answer = 0;
		
		for(int i = 0; i < num; i++) {
			String str = sc.next();
			boolean []apb = new boolean[26];
			boolean chk = false;
			char curr = ' ';
			
			for(int j = 0; j < str.length(); j++) {
				if(curr != str.charAt(j) && apb[str.charAt(j) - 'a']) {
					chk = true;
					break;
				}
				
				curr = str.charAt(j);
				apb[str.charAt(j) - 'a'] = true;
			}
			
			if(!chk) answer++;
		}
		
		System.out.println(answer);
		
		sc.close();
	}

}
