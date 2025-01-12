
import java.util.HashMap;
import java.util.Map;

public class engWordRelay {
    public static void main(String[] args)
    {
        int n = 5;
        String[] words = {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"};

        int[] answer = solution(n, words);

        for(int i = 0; i < answer.length; i++) {
            System.out.println(answer[i]);
        }
        
    }

    public static int[] solution(int n, String[] words) {
        int num = 1; // 사람 순서
        int order = 1; // 차례

        boolean flag = false;

        Map<String, Integer> map = new HashMap<>();

        for(int i = 0; i < words.length; i++) {
            if(i == 0) {
                map.put(words[i], 1);
                num++;
                continue;
            }

            if(num > n) {
                num = 1;
                order++;
            }

            int find = map.getOrDefault(words[i], 0); // 중복 확인

            if(find == 0) {
                // 중복 없으면 끝말잇기가 진행되는 단어인지 확인
                char before = words[i - 1].charAt(words[i - 1].length() - 1);
                char next = words[i].charAt(0);

                if(before == next) {
                    // 같으면 진행
                    num++;
                } else {
                    // 다르면 중단
                    flag = true;
                    break;
                }

                map.put(words[i], 1);
            } else {
                // 중복 있으면 for문 중단
                flag = true;
                break;
            }
        }

        if(num == n + 1 && order == (words.length / n) && words.length % n == 0 && flag == false) {
            // 정상 종료
            return new int[]{0, 0};
        } else {
            // 끝말잇기 실패
            return new int[]{num, order};
        }
    }
}
