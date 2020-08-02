#include <iostream>
using namespace std;
int N;
int price[1000000];
long long solution(){
    long long answer=0;
    int max_price=price[N-1], sum=0, count=0;
    for(int i=N-2;i>=0;--i){
        if(price[i]>=max_price){
            answer += max_price * count - sum;
            max_price=price[i];
            count=0; sum=0; continue;
        }
        count++;
        sum+=price[i];
        if(i==0){
            answer += max_price * count - sum;
        }
    }
    return answer;
}

int main(int argc, char** argv) {
    int test_case;
    int T;
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        for(int i=0;i<N;++i){
            cin >> price[i];
        }
        cout << "#" << test_case << " " << solution() << "\n";
    }
    return 0;
}