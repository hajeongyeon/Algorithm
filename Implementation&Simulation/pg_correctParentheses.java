import java.util.Stack;

public class correctParentheses {
    public static void main(String[] args)
    {
        String s = "())";

        boolean answer = solution(s);

        System.out.println(answer);
        
    }
    
    public static boolean solution(String s) {
        Stack<Character> st = new Stack<>();

        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '(') {
                st.push(s.charAt(i));
            } else {
                if(st.isEmpty()) return false;
                else st.pop();
            }
        }

        return st.isEmpty();
    }
}
