import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine()); //한줄에 들어온 문자열을 나눈다
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        if(a == b) bw.write("==");
        else if(a > b) bw.write(">");
        else bw.write("<");

        bw.close();
        br.close();
    }

    public static void main(String[] args) throws Exception {
        solution();
    }
}
