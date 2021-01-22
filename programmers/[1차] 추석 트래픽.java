import java.util.*;

class Solution {
    public class TrafficTime implements Comparable<TrafficTime> {
        private int start;
        private int end;

        public TrafficTime(String s) {
            int time = 0;
            int ptime = 0;
            time += Integer.parseInt(s.substring(11, 13)) * 3600 * 1000;
            time += Integer.parseInt(s.substring(14, 16)) * 60 * 1000;
            time += Integer.parseInt(s.substring(17, 19)) * 1000;
            time += Integer.parseInt(s.substring(20, 23));

            String s2 = s.substring(24, s.length() - 1);
            Double d = Double.parseDouble(s2);
            ptime = (int) (d * 1000);
            this.start = time - ptime;
            this.end = time;
        }

        public int getStart() {
            return this.start;
        }

        public int getEnd() {
            return this.end;
        }

        @Override
        public int compareTo(TrafficTime t) {
            if (this.end < t.end)
                return -1;
            if (this.end == t.end)
                if (this.start < this.start)
                    return -1;
            return 1;
        }

    }

    public int solution(String[] lines) {
        ArrayList<TrafficTime> list = new ArrayList<>();
        for (int i = 0; i < lines.length; i++) {
            TrafficTime t = new TrafficTime(lines[i]);
            list.add(t);
        }
        Collections.sort(list);

        int answer = 1;
        for (int i = 0; i < list.size(); i++) {
            int cnt = 0;
            for (int j = i; j < list.size(); j++) {
                if (list.get(j).getStart() - list.get(i).getEnd() < 999) {
                    cnt++;
                }
            }
            if (cnt > answer)
                answer = cnt;
        }
        return answer;
    }
}