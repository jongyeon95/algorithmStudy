#include <iostream>
#include <cstring>
using namespace std;
int arr[51][51];
int n,m;
int r,c,d;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int result=0;
bool resultCheck=false;
void vaccum(){
	arr[r][c]=2;
	result++;
}
void turingLeft(){
	if(d==0)
		d=3;
	else
		d--;
}
void findDirtySpace(){
	bool check=true;
	if(arr[r][c]==0)
		vaccum();
	for (int i = 0; i < 4; ++i)
	{
		turingLeft();
		if(arr[r+dy[d]][c+dx[d]]==0){
			r+=dy[d];
			c+=dx[d];
			check=false;
			break;
		}
	}
	if (check)
	{
		if(arr[r-dy[d]][c-dx[d]]!=2)
			resultCheck=true;
		else{
			r-=dy[d];
			c-=dx[d];
		}
	}
}

int main(){

	memset(arr,-1,sizeof(arr));
	cin>>n>>m>>r>>c>>d;
	for (int i = 0; i <n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

	vaccum();
	while(!resultCheck)
		findDirtySpace();
	
	cout << result;
}