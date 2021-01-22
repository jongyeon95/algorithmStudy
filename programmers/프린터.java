import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        ArrayList<Integer> q = new ArrayList<>();
        for (Integer a : priorities) {
            q.add(a);
        }
        int al = location;
        int cnt = 0;
        while (true) {
            int temp = q.get(0);
            boolean check = true;
            for (int t : q) {
                if (t > temp) {
                    check = false;
                    break;
                }
            }

            q.remove(0);
            if (!check) {
                q.add(temp);
                if (al == 0) {
                    al = q.size() - 1;
                } else
                    al--;
            } else {
                cnt++;
                if (al == 0) {
                    break;
                } else {
                    al--;
                }
            }

        }
        return cnt;
    }
}