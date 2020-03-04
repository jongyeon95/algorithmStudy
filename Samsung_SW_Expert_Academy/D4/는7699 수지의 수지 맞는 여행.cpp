#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int r,c;
char arr[20][20];
bool alpha[26];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int maxNum;


void dfs(int x, int y, int total){

		if (maxNum<total)
		{
			maxNum=total;
		}
	
		for (int i = 0; i < 4; ++i)
		{
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(tx<0||ty<0||tx>=c||ty>=r)
				continue;
			if(alpha[arr[ty][tx]-'A']==false){
				alpha[arr[ty][tx]-'A']=true;
				dfs(tx,ty,total+1);
				alpha[arr[ty][tx]-'A']=false;
			}
		}

}

int main(){
	cin.tie(0);
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		memset(alpha,false,sizeof(alpha));
		maxNum=0;
		cin >> r >> c;
		getchar();
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
					arr[i][j]=getchar();
			}	
			getchar();
		}

		alpha[arr[0][0]-'A']=true;
		dfs(0,0,1);

		printf("#%d %d\n",t,maxNum);



	}
}