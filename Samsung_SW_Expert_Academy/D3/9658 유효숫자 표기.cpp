#include <iostream>
#include <string>
using namespace std;
int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; ++t)
    {
        string s;
        cin >> s;
        int arr[3];
        int size=s.size()-1;
        bool check=false;
        arr[0]=0;
        for (int i = 0; i < 3; ++i)
        {
            arr[i]=s[i]-'0';
        }
        if(arr[2]>4){
            arr[1]+=1;
            if(arr[1]==10){
                arr[0]+=1;
                if(arr[0]==10){
                    arr[0]=1;
                    arr[1]=0;
                    check=true;
                    size+=1;
                }
            }
        }
        if(!check){
            if(arr[1]==10)
                arr[1]=0;
        }
        printf("#%d %d.%d*10^%d\n",t,arr[0],arr[1],size);
 
 
    }
 
}