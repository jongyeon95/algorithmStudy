#include <iostream>
#include <string>
using namespace std;

int main(){
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int mapsize;
		int bome[3][60];
		int x=0;
		int y=0;
		string bomexy;
		cin >> mapsize;
		int map[mapsize][mapsize];
		cin >> bomexy;
		for (int j = 0; j < bomexy.length(); j++)
		{
			if (bomexy[j]==',')
			{
				bome[y][x]=-1;
				x=0;
				y++;
				continue;
			}
			else{
			int temp=(int)bomexy[j]-'0'
			bome[y][x]=temp;
			}
		}

		




	}
}