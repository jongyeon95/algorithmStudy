#include <iostream>
#include <cstring>
using namespace std;
int laptop[40][40];
int sticker[40][40];
int n,m,k; // 세로 , 가로 , 스티커수

void Rotate(int ysize , int xsize){
	int temp[40][40];
	int i,z,j;
	memset(temp,0,sizeof(temp));
	for (i = 0; i < xsize; ++i)
	{
		for (j = ysize-1,z= 0; j >=0 , z<ysize; --j, ++z)
		{
			temp[i][j]=sticker[z][i];
		}
	}
	

	memset(sticker,0,sizeof(sticker));
	for (i = 0; i < 40; ++i)
	{
		for (j = 0; j <40; ++j)
		{
			if(temp[i][j]==1)
				sticker[i][j]=1;
		}
	}


}
bool IsAble(int ysize , int xsize ,int startY,int startX){

	
	for (int i = 0; i < ysize; ++i)
	{
		for (int j = 0; j < xsize; ++j)
		{
			if(laptop[startY+i][startX+j]==1&&sticker[i][j]==1)
				return false;
		}
	}

	for (int i = 0; i < ysize; ++i)
	{
		for (int j = 0; j < xsize; ++j)
		{
			if(sticker[i][j]==1){
				laptop[startY+i][startX+j]=1;
			}
			
		}
		
	}


	return true;
}

bool findLocate(int ysize , int xsize){
	for (int i = 0; i < n-ysize+1; ++i)
	{
		for (int j = 0; j <m-xsize+1; ++j)
		{
			if(IsAble(ysize,xsize,i,j)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	cin >> n>>m>>k;
	for (int input = 0; input < k; ++input)
	{
		int ysize , xsize;
		cin >> ysize >> xsize;
		memset(sticker,0,sizeof(sticker));
		for (int y = 0; y < ysize; ++y)
		{
			for (int x = 0; x < xsize; ++x)
			{
				cin >> sticker[y][x];
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			
			
			if(findLocate(ysize,xsize)){
				break;

			}
			Rotate(ysize,xsize);
			int temp;
			temp=ysize;
			ysize=xsize;
			xsize=temp;
		}
	}

	int result=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(laptop[i][j]==1)
				result++;
		}
	}

	cout << result;
}