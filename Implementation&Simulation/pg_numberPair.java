public class numberPair {
    public static void main(String[] args)
    {
        String X = "5525";
        String Y = "1255";

        String answer = solution(X, Y);

        System.out.println(answer);
        
    }

    public static String solution(String X, String Y) {
        /*
         * String 클래스는 불변의 문자열
         * 한 번 생성된 String 객체의 내용은 변경할 수 없으며, 문자열의 변경이 필요한 경우 새로운 String 객체가 생성됨
         * String 객체는 불변하기 때문에, 문자열 연산이 빈번하게 발생하는 상황에서는 성능 저하의 원인이 될 수 있음
         * 예를 들어, 반복문 내에서 문자열을 변경하는 작업을 수행할 경우, 매번 새로운 String 객체가 생성되어 메모리 사용량이 증가하고, 가비지 컬렉션의 부하가 커질 수 있음
         * 따라서 문자열을 자주 변경해야 하는 상황에서는 String 클래스의 사용을 피하고 StringBuffer나 StringBuilder 클래스를 사용
         * 
         * StringBuffer와 StringBuilder 클래스는 가변(mutable) 문자열
         * 이 클래스들을 사용하면 문자열의 추가, 삭제, 수정 작업을 하나의 객체 내에서 수행할 수 있으며, 이로 인해 성능이 향상됨
         * 내부적으로 문자열을 배열로 관리하기 때문에, 문자열 변경 작업 시 새로운 객체 생성 없이 기존 배열을 재사용
         * 메모리 사용량을 줄이고, 성능을 향상시킴
         * 
         * StringBuffer와 StringBuilder의 주요 차이점은 동기화(synchronization) 지원 여부
         * StringBuffer는 멀티스레드 환경에서 안전하게 사용할 수 있도록 동기화를 지원하지만, StringBuilder는 동기화를 지원하지 않음
         * 단일 스레드 환경에서는 StringBuilder가 더 높은 성능 제공
         * 
         * 문자열의 변경이 빈번한 상황에서는 StringBuffer나 StringBuilder의 사용을 고려해야 함
         * 특히, 멀티스레드 환경에서는 StringBuffer를, 단일 스레드 환경에서는 StringBuilder를 사용하는 것을 권장
         */
        StringBuilder answer = new StringBuilder();

        int[] arrX = new int[10];
        int[] arrY = new int[10];

        countArray(X, arrX);
        countArray(Y, arrY);

        for(int i = arrX.length - 1; i >= 0; i--) {
            while(arrX[i] >= 1 && arrY[i] >= 1) {
                arrX[i]--;
                arrY[i]--;

                answer.append(i);
            }
        }

        if(answer.toString().equals("")) return "-1";
        else if(answer.toString().startsWith("0")) return "0";
        else return answer.toString();
    }

    public static void countArray(String str, int[] arr) {
        for(int i = 0; i < str.length(); i++) {
            int num = str.charAt(i) - '0';
            arr[num]++;
        }
    }
}
