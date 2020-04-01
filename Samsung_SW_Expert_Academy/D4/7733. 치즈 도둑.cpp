#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int cheese[100][100];
int visited[100][100];
int n;
int flag=1;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
 
 
void bfs(int y, int x){
    queue<pair<int ,int>> q;
    q.push({y,x});
    while(!q.empty()){
        pair<int,int> temp;
        temp=q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int tx=dx[i]+temp.second;
            int ty=dy[i]+temp.first;
            if(tx<0||ty<0||tx>=n||ty>=n)
                continue;
            if(!visited[ty][tx]&&cheese[ty][tx]>flag){
                visited[ty][tx]=true;
                q.push({ty,tx});
            }
        }
    }
 
}
 
int main(){
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; ++t)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <n ; ++j)
                cin >> cheese[i][j];
        int result=1;
        int dump=0;
        flag=1;
        for (int k = 0; k < 100; ++k)
        {
            memset(visited,false,sizeof(visited));
            dump=0;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j <n ; ++j){
                    if(!visited[i][j]&&cheese[i][j]>flag){
                        visited[i][j]=true;
                        bfs(i,j);
                        dump++;
                    }
                }
 
            flag++;
 
            if(result<dump)
                result=dump;
             
        }
 
        cout<<"#"<<t<<" "<<result<<"\n";
 
    }
}