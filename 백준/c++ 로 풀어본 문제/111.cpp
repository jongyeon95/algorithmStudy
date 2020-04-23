#include <iostream>
#include <vector>
using namespace std;
int arr[9][9];
int flag=0;
vector<pair<int,int>> v;
void init(){
	for (int i=0; i<9; ++i)
		for(int j=0; j<9; j++){
			cin >> arr[i][j];
			if(arr[i][j]==0){
				v.push_back({i,j});
				flag++;
			}
		}
}

bool NumCheck(int num , int y , int x){
	

	for (int i=0; i<9; ++i){
		if(arr[i][x]==num&&i!=x)
			return false;
	}
	
	for (int i=0; i<9; ++i){
		if(arr[y][i]==num&&i!=y)
			return false;
	}
	
	int tx=(x/3)*3;
	int ty=(y/3)*3;

	for (int i = ty; i < ty+3; ++i)
	{
		for (int j = tx; j <tx+3; ++j)
		{
			if(i!=y&&j!=x&&arr[i][j]==num)
				return false;
		}
	}
	
	return true;
}

bool dfs(int cnt){
	if(cnt==v.size())
		return true;

	for (int i = 1; i < 10; ++i)
	{
		if(NumCheck(i,v[cnt].first,v[cnt].second)){
			arr[v[cnt].first][v[cnt].second]=i;
			if(dfs(cnt+1))
				return true;
			else
				arr[v[cnt].first][v[cnt].second]=0;
		}
		
	}

	return false;

}

int main(){
	
	init();
	dfs(0);
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout<< arr[i][j] << " ";
		}
		cout<<endl;
	}
	
}