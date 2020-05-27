#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int row,col;
int map[8][8];
int cMap[8][8];

struct cctv
{
	int cctvNum;
	int y;
	int x;
	int dir;
};

int result=64;
vector<cctv> cctvInfo;


void input(){
	memset(map,0,sizeof(map));
	cin >> col >> row;
	for (int i = 0; i < col; ++i)
		for (int j = 0; j < row; ++j){
			cin >> map[i][j];
			if(map[i][j]!=0&&map[i][j]!=6){
				cctvInfo.push_back({map[i][j],i,j,0});
			}
		}
}

void cpyMap(){
	for (int i = 0; i < col; ++i)
		for (int j = 0; j < row; ++j)
			cMap[i][j]=map[i][j];
	
}

void fill(int index, cctv c){

	if(index==0){
		for (int i = c.y; i >= 0; i--)
		{
			if(cMap[i][c.x]==6)
				break;
			if(cMap[i][c.x]==0)
				cMap[i][c.x]=-1;
		}
	}
	else if(index==1){
		for (int i = c.x; i < row; ++i)
		{
			if(cMap[c.y][i]==6)
				break;
			if(cMap[c.y][i]==0)
				cMap[c.y][i]=-1;
		}

	}
	else if(index==2){
		for (int i = c.y; i < col; i++)
		{
			if(cMap[i][c.x]==6)
				break;
			if(cMap[i][c.x]==0)
				cMap[i][c.x]=-1;
		}
		
	}
	else if(index==3){
		for (int i = c.x; i >=0; i--)
		{
			if(cMap[c.y][i]==6)
				break;
			if(cMap[c.y][i]==0)
				cMap[c.y][i]=-1;
		}
		
	}


}


void search(){

	int count=0;

	for (int i = 0; i < cctvInfo.size(); ++i)
	{
		if(cctvInfo[i].cctvNum==1){
			fill(cctvInfo[i].dir,cctvInfo[i]);
		}
		else if(cctvInfo[i].cctvNum==2){
			if(cctvInfo[i].dir%2==0){
				fill(0,cctvInfo[i]);
				fill(2,cctvInfo[i]);
			}
			else{
				fill(1,cctvInfo[i]);
				fill(3,cctvInfo[i]);
			}
		}
		else if(cctvInfo[i].cctvNum==3){
			if(cctvInfo[i].dir==3){
				fill(0,cctvInfo[i]);
				fill(3,cctvInfo[i]);
			}
			else{
				fill(cctvInfo[i].dir,cctvInfo[i]);
				fill(cctvInfo[i].dir+1,cctvInfo[i]);
			}
		}
		else if(cctvInfo[i].cctvNum==4){
			for(int j=0; j<4; j++){
				if(j==cctvInfo[i].dir)
					continue;
				fill(j,cctvInfo[i]);
			}
			
		}
		else{
			fill(0,cctvInfo[i]);
			fill(1,cctvInfo[i]);
			fill(2,cctvInfo[i]);
			fill(3,cctvInfo[i]);
		}

	}


	for (int i = 0; i < col; ++i)
		for (int j = 0; j < row; ++j)
			if(cMap[i][j]==0) count++;


	if(result>count)
		result=count;
		
			

}


void dfs(int index){
	if(index==cctvInfo.size()){
		cpyMap();
		search();
		return;
	}

	for(int i=0; i<4; i++){
		cctvInfo[index].dir=i;
		dfs(index+1);
	}

}



int main(){
	input();
	dfs(0);
	cout << result;

	
}