public class bestSet {
    public static void main(String[] args)
    {
        int n = 5;
        int s = 13;

        int[] answer = solution(n, s);

        for(int i = 0; i < answer.length; i++) {
            System.out.println(answer[i]);
        }
    }

    public static int[] solution(int n, int s) {
        double dn = (double)n;
        double ds = (double)s;

        double x = Math.floor(s / n);

        if(x == 0) return new int[]{-1};

        int[] answer = new int[n];

        if(x == ds / dn) {
            for(int i = 0; i < n; i++) answer[i] = s / n;
        } else {
            int num = s % n; // 3
            for(int i = 0; i < n; i++) {
                if(i < n - num) answer[i] = s / n;
                else answer[i] = (s / n) + 1;
            }
        }

        return answer;
    }
}
