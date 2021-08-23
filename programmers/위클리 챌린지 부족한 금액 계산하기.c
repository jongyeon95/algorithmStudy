#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = -1;
    int cnt=1;
    long long totalPrice=0;
    while(cnt<=count){ 
        totalPrice+=cnt*price;
        cnt++;
    }
    if(money>=totalPrice)
        return 0;
    else
        return totalPrice-money;
}