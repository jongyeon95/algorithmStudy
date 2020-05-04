#include <iostream>
using namespace std;
 
int main() {
    int goal;
    cin>>goal;
    int count=0,stick=64;
    while(goal>0) {
        if(stick>goal)
        	stick=stick/2;
        else{
        	goal=goal-stick;
        	count++;
        }
    }
 
    cout<<count;
    return 0;
}