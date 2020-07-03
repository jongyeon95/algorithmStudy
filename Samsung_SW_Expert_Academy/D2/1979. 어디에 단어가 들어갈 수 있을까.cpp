#include<iostream>
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    int map[15][15];
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n,k;
        int result=0;
        cin >> n >> k;

        //입력
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >>map[i][j];
            }
        }

        //가로에서 확인
        for(int i=0; i<n; i++){
            int flag=0;
            for(int j=0; j<n; j++){
                if(map[i][j]==1){
                    flag++;
                    if(flag>k)
                        flag=0;
                    if(j==n-1&&flag==k)
                        result++;
                }
                else{
                    if(flag==k)
                        result++;     
                    flag=0;
                }
            }
        }

        //세로에서 확인 
        for(int i=0; i<n; i++){
            int flag=0;
            for(int j=0; j<n; j++){
                if(map[j][i]==1){
                    flag++;
                    if(flag>k)
                        flag=0;
                    if(j==n-1&&flag==k)
                        result++;
                }
                else{
                    if(flag==k)
                        result++;     
                    flag=0;
                }
            }
        }
        cout<<"#"<<test_case<<" "<<result<<"\n";
 
         
    }
    return 0;
}