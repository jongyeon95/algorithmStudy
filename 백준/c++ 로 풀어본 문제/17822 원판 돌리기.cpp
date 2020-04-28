#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
const int MAX = 52;

struct Pan {
    deque <int> dq;
};
Pan pan[MAX];
int n, m, t;

void turn(int x, int d, int k){

    for (int i = 0; i < k; i++) {
        if (d == 0) {
            int temp = pan[x].dq.back();
            pan[x].dq.pop_back();
            pan[x].dq.push_front(temp);
        }
        else {
            int temp = pan[x].dq.front();
            pan[x].dq.pop_front();
            pan[x].dq.push_back(temp);
        }
    }

}
 
void deleteNum() {

    int flag = 0;
    // 좌, 우, 위, 아래 확인
    // 좌, 우 확인
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                //끝, 처음 비교
                if (pan[i].dq.front() == 0 || pan[i].dq.back() == 0) continue;
                if (abs(pan[i].dq.front()) == abs(pan[i].dq.back())) {
                    if (pan[i].dq[0] > 0) pan[i].dq[0] *= -1;
                    if (pan[i].dq[j] > 0) pan[i].dq[j] *= -1;
                    flag = 1;
                }
            }
            else {
                //좌, 우 비교
                if (pan[i].dq[j] == 0 || pan[i].dq[j+1] == 0) continue;
                if (abs(pan[i].dq[j]) == abs(pan[i].dq[j + 1])) {
                    if (pan[i].dq[j] > 0) pan[i].dq[j] *= -1;
                    if (pan[i].dq[j+1] > 0) pan[i].dq[j+1] *= -1;
                    flag = 1;
                }
            }
 
        }
    }

    // 위, 아래 확인
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
 
            if ( pan[i].dq[j] == 0 || pan[i+1].dq[j] == 0) continue;
            if ( abs(pan[i].dq[j]) == abs(pan[i + 1].dq[j]) ) {
                if (pan[i].dq[j] > 0) pan[i].dq[j] *= -1;
                if (pan[i+1].dq[j] > 0)pan[i+1].dq[j] *= -1;
                flag = 1;
            }
 
        }
    }
 
    // 하나도 바뀌지 않은게 있다면 평균 값 처리.
    if (flag == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (pan[i].dq[j] < 0) pan[i].dq[j] = 0;
            }
        }

        return;
    }
    else {
        //원판에 지워지지 않은 숫자의 갯수
        double cnt = 0;
        //원판에 지워지지 않은 숫자의 총합
        double sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (pan[i].dq[j] == 0) continue;
                cnt++;
                sum += pan[i].dq[j];
            }
        }
        //평균 값
        double avg = sum / cnt;
       
        //평균 값 보다 크면 -1, 작으면 +1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (pan[i].dq[j] > avg && pan[i].dq[j]>0) pan[i].dq[j] -= 1;
                else if (pan[i].dq[j] < avg && pan[i].dq[j]>0) pan[i].dq[j] += 1;
            }
        }
    }

}

 
int main() {
 
    cin >> n >> m >> t;
    
    //원판 입력
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            pan[i].dq.push_back(temp);
        }
    }
 
    //원판 돌리기
    for (int i = 0; i < t; i++) {
        int x, d, k;
        cin >> x >> d >> k;
        
        // x의 배수 만큼 돌리기
        int temp = x;
        while (true) {
            if (temp > n) break;
            turn(temp, d, k);
            temp = temp + x;
        }
 
        // 인접한 수 지우기
        deleteNum();
    }
 
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (pan[i].dq[j] > 0) sum += pan[i].dq[j];
        }
    }
    cout << sum << endl;
 
    return 0;
}
