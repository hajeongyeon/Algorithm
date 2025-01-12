
import java.util.ArrayList;

public class towerOfHanoi {

    static ArrayList<int[]> arrayList;
    
    public static void main(String[] args)
    {
        int n = 3;

        int[][] answer = solution(n);

        for (int[] answer1 : answer) {
            for (int j = 0; j < answer1.length; j++) {
                System.out.println(answer1[j]);
            }
        }
    }

    public static int[][] solution(int n) {
        arrayList = new ArrayList<>();

        hanoi(n, 1, 3, 2);

        int[][] answer = new int[arrayList.size()][2];
        for(int i = 0; i < arrayList.size(); i++) {
            int[] temp = arrayList.get(i);

            answer[i][0] = temp[0];
            answer[i][1] = temp[1];
        }

        return answer;
    }

    public static void hanoi(int n, int from, int to, int via) {
        int[] move = {from, to};

        if(n == 1) {
            arrayList.add(move);
        } else {
            hanoi(n - 1, from, via, to); // 출발지에 있는 n-1개의 원판을 경유지로 옮김
            arrayList.add(move); // 출발지에 있는 한 개의 원판을 도착지로 옮김
            hanoi(n - 1, via, to, from); // 경유지에 있는 n-1개의 원판을 도착지로 옮김
        }
    }
}
