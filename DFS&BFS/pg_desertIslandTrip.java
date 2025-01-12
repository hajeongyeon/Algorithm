import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    static int day = 0;
    static int row = 0;
    static int col = 0;
    
    public static int[] solution(String[] maps) {
        row = maps.length;
        col = maps[0].length();

        int[][] map = new int[row][col];
        boolean[][] visited = new boolean[row][col];

        List<Integer> days = new ArrayList<>();
        
        for (int i = 0; i < row; i++) {
            char[] ch = maps[i].toCharArray();

            for(int j = 0; j < ch.length; j++) {
                if(ch[j] == 'X') map[i][j] = 0;
                else map[i][j] = ch[j] - '0';
            }
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(!visited[i][j] && map[i][j] > 0) {
                    dfs(map, visited, i, j);
                    days.add(day);
                    day = 0;
                }
            }
        }

        if(days.isEmpty()) return new int[]{-1};

        Collections.sort(days);
        int[] answer = new int[days.size()];
        for (int i = 0; i < answer.length; i++) {
            answer[i] = days.get(i);
        }
        
        return answer;
    }

    public static void dfs(int[][] map, boolean[][] visited, int x, int y) {
        day += map[x][y];
        visited[x][y] = true;

        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= row || ny >= col) continue;

            if(!visited[nx][ny] && map[nx][ny] > 0) {
                dfs(map, visited, nx, ny);
            }
        }
    }
}
