#include <iostream>
#include <queue>
using namespace std;
int n;
int result;
int map[16][16];
int dx[3]={0,1,1};
int dy[3]={1,1,0};

struct xy
{
  int y;
  int x;
  int dir;
  
};

void bfs(int y, int x, int dir){
  queue<xy> q;
  q.push({y,x,dir});
  while(!q.empty()){
    xy temp= q.front();
    q.pop();
    if(temp.y==n-1&&temp.x==n-1)
      result++;
    for (int i = 0; i < 3; ++i)
    {
        int ty=temp.y+dy[i];
        int tx=temp.x+dx[i];
        if(ty<0||tx<0||ty>=n||tx>=n)
          continue;
        if(temp.dir!=1){
          if(temp.dir!=i&&i!=1)
            continue;
        }
        if(i==1){
          bool check=false;
          for (int j = 0; j < 3; ++j)
          {
            int tty=temp.y+dy[j];
            int ttx=temp.x+dx[j];
            if(map[tty][ttx]!=0)
              check=true;
          }
          if(check)
            continue;
        }
        if(map[ty][tx]==0)
          q.push({ty,tx,i});
    }
  }
}


int main(){
  cin.tie(0);
  cout.sync_with_stdio(false);
  cin >> n;
  result=0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> map[i][j];
    }
  }
  bfs(0,1,2);
  cout << result;

}