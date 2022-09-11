class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] task = new int[101];
        int day = 0;

        for(int i = 0; i < progresses.length; i++) {
            while(progresses[i] + (speeds[i] * day) < 100) day++;
            task[day]++;
        }
        
        int cnt = 0;

        for (int idx : task) {
            if (idx != 0) cnt++;
        }
        
        int[] answer = new int[cnt];
        cnt = 0;

        for (int idx : task){
            if (idx != 0)  answer[cnt++] = idx;
        }
        
        return answer;
    }
}
