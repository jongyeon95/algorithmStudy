import java.util.*;

class Car implements Comparable<Car> {
    private int start;
    private int end;

    public Car(int start, int end) {
        this.start = start;
        this.end = end;
    }

    int getStart() {
        return this.start;
    }

    int getEnd() {
        return this.end;
    }

    @Override
    public int compareTo(Car car) {
        if (this.start < car.start) {
            return -1;
        } else if (this.start == car.start) {
            if (this.end < car.end) {
                return -1;
            }
            return 0;
        } else {
            return 1;
        }
    }
}


class Solution {
    public int solution(int[][] routes) {
        ArrayList<Car> car = new ArrayList<>();
        for (int i = 0; i < routes.length; i++) {
            int a = routes[i][0];
            int b = routes[i][1];
            Car c = new Car(a, b);
            car.add(c);
        }
        Collections.sort(car);
        int cnt = 0;
        for (int i = 0; i < car.size(); i++) {
            int end = car.get(i).getEnd();
            int start = car.get(i).getStart();
            for (int j = i + 1; j < car.size(); j++) {
                if (car.get(j).getStart() > end) {
                    cnt++;
                    i = j - 1;
                    break;
                } else if (car.get(j).getEnd() < end) {
                    end = car.get(j).getEnd();
                }
            }
        }


        int answer = cnt + 1;
        return answer;
    }
}