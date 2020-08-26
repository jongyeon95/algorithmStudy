#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int arr[n][n];
    memset(arr,0,sizeof(arr));
    for(int i=0; i<n; i++){
        int temp=arr1[i];
        int cnt=0;
        while(temp>0){
            arr[i][n-cnt-1]+=temp%2;
            temp/=2;
            cnt++;
        }
        temp=arr2[i];
        cnt=0;
         while(temp>0){
            arr[i][n-cnt-1]+=temp%2;
            temp/=2;
            cnt++;
        }
    }
    for(int i=0; i<n;i++){
        string s="";
        for(int j=0; j<n; j++){
            if(arr[i][j]>0){
                s+="#";
            }
            else{
                s+=" ";
            }
        }
        answer.push_back(s);
    }
    return answer;
}