import java.util.*;

class Solution {
    public static int MAX = 10000000;
    public boolean check[];
    public boolean visited[] = new boolean[7];
    public HashSet<Integer> hs = new HashSet<Integer>();
    public String numbers;
    public String dfsString;


    public void init() {
        check = new boolean[MAX];
        for (int i = 0; i < 7; i++) {
            visited[i] = false;
        }
        for (int i = 0; i < MAX; i++) {
            check[i] = false;
        }
        check[0] = true;
        check[1] = true;
        for (int i = 2; i * i < MAX; i++) {
            if (check[i])
                continue;
            for (int j = i + i; j < MAX; j += i) {
                check[j] = true;
            }
        }
    }

    void dfs(String s) {
        for (int i = 0; i < numbers.length(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                String temp = s + numbers.charAt(i);
                hs.add(Integer.parseInt(temp));
                dfs(temp);
                visited[i] = false;
            }
        }
    }


    public int solution(String numbers) {
        int answer = 0;
        this.numbers = numbers;
        init();
        dfs("");
        Iterator<Integer> iter = hs.iterator();

        while (iter.hasNext()) {
            if (!check[iter.next()])
                answer++;

        }

        return answer;
    }
}