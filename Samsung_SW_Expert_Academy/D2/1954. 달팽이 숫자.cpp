#include<iostream>
#include<cstring>
using namespace std;

//방향
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main(int argc, char** argv)
{
    int map[10][10];
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(map,0,sizeof(map));
        int n;
        cin >> n;
        int i=0,j=0,dir=0;
        map[0][0]=1;
        int cnt=2;
        int size=n*n;
 

        while(size>=cnt){
        	//앞으로 갈 곳 위치
            int ty=i+dy[dir];
            int tx=j+dx[dir];
            
            //갈 방향이 배열의 크기를 벗어나거나
            //이미 숫자가 쓰여진 경우 방향을 바꿈
            if(ty<0 || tx<0 || ty>=n ||tx>=n || map[ty][tx]>0){
            	dir+=1;
                if(dir==4)
                    dir=0;
                continue;
            }
            map[ty][tx]=cnt;
            i=ty;
            j=tx;
            cnt++;
        }

        //출력
        cout << "#"<<test_case<<"\n";
        for(i=0; i<n; i++){
        	for(j=0; j<n; j++){
            	cout<<map[i][j]<<" ";
            }
            cout<<"\n";
        }
      
	}
	return 0;
}