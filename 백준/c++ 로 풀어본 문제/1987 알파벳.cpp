#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
vector<string> map;
bool alphabet[26];
int r,c;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int result=0;
void dfs(int y, int x ,int count){
	if(count>result){
		result=count;
	}
	for (int i = 0; i < 4; ++i)
	{
		int ty=y+dy[i];
		int tx=x+dx[i];
		if (tx<0||ty<0||tx>=c||ty>=r)
			continue;
		if(!alphabet[map[ty][tx]-'A']){
			alphabet[map[ty][tx]-'A']=true;
			dfs(ty,tx,count+1);
			alphabet[map[ty][tx]-'A']=false;
		}
		
	}
}

int main(){
	cin >> r >> c;
	memset(alphabet,false,sizeof(alphabet));
	for (int i = 0; i < r; ++i)
	{
		string s;
		cin >> s;
		map.push_back(s);
	}
	alphabet[map[0][0]-'A']=true;
	dfs(0,0,1);
	cout << result;
}