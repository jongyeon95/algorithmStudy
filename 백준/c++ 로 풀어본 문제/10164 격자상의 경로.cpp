#include <iostream>
#include <cstring>
using namespace std;

int map[15][15];

int main(){
	int col,row,circle;
	int circleNum;
	cin>>col>>row>>circle;
	memset(map,0,sizeof(map));
	map[0][0]=1;
	for (int i = 0; i < col; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			
			if(i==0&&j==0)
				continue;
			if(i-1>=0)
				map[i][j]+=map[i-1][j];
			if(j-1>=0)
				map[i][j]+=map[i][j-1];
		}
	}

	if(circle==0){
		cout<<map[col-1][row-1];
		return 0;
	}

	int circleY;
	int circleX;
	if(circle%row==0){
		circleX=row-1;
		circleY=circle/row-1;
	}
	else{
		circleX=circle%row-1;
		circleY=circle/row;
	}

	circleNum=map[circleY][circleX];
	
	
	memset(map,0,sizeof(map));
	map[circleY][circleX]=circleNum;
	for (int i = circleY; i < col; ++i)
	{
		for (int j = circleX; j < row; ++j)
		{
			
			if(i==circleY&&j==circleX)
				continue;
			if(i-1>=0)
				map[i][j]+=map[i-1][j];
			if(j-1>=0)
				map[i][j]+=map[i][j-1];
			
		}
	}

	cout<<map[col-1][row-1];

}