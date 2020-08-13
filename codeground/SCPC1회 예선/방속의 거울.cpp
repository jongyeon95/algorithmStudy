
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int Answer;

int dirY[]={0,1,0,-1};//오른 , 아래 , 왼 ,위 
int dirX[]={1,0,-1,0};

int mirror[3][4]{
	{0,1,2,3},
	{3,2,1,0},
	{1,0,3,2}
};

int main(int argc, char** argv)
{
	int T, test_case;


	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		int n;
		int dir=0;
		Answer = 0;
		cin >> n;
		bool check[n][n];
		memset(check,false,sizeof(check));
		string arr[n];
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			arr[i]=s;
		}
		int x,y;
		x=0;
		y=0;
		while(1){
			int ty,tx;
		
			if(!check[y][x]&&arr[y][x]!='0'){
				check[y][x]=true;
				Answer++;
			}
			dir=mirror[arr[y][x]-'0'][dir];
			ty=y+dirY[dir];
			tx=x+dirX[dir];
			if(ty<0||tx<0||ty>=n||tx>=n){
				break;
			}
			
			
			y=ty;
			x=tx;
		}
	
	
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}