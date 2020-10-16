#include <iostream>
#include <cstring>
using namespace std;
int blueMap[4][10];
int redMap[10][4];
int answer=0;


void move(int t, int y, int x){

	if(t==1){
		//blue
		for (int i =x ; i < 10; ++i)
		{
			if(i==9){
				blueMap[y][i]=1;
				break;
			}
			if(blueMap[y][i+1]!=0){
				blueMap[y][i]=1;
				break;
			}
		}
		//red
		for (int i = y; i < 10; ++i)
		{
			if(i==9){
				redMap[i][x]=1;
				break;
			}
			if(redMap[i+1][x]!=0){
				redMap[i][x]=1;
				break;
			}

		}
	}
	else if(t==2){//--
		//blue
		for (int i =x ; i < 10; ++i)
		{
			if(i==9){
				blueMap[y][i]=1;
				blueMap[y][i-1]=1;
				break;
			}
			if(blueMap[y][i+1]!=0){
				blueMap[y][i]=1;
				blueMap[y][i-1]=1;
				break;
			}
		}
		//red
		for (int i = y; i < 10; ++i)
		{
			if(i==9){
				redMap[i][x]=2;
				redMap[i][x+1]=3;
				break;
			}
			if(redMap[i+1][x]!=0||redMap[i+1][x+1]!=0){
				redMap[i][x]=2;
				redMap[i][x+1]=3;
				break;
			}

		}

	}
	else{// |
		//blue
		for (int i =x ; i < 10; ++i)
		{
			if(i==9){
				blueMap[y][i]=2;
				blueMap[y+1][i]=3;
				break;
			}
			if(blueMap[y][i+1]!=0||blueMap[y+1][i+1]!=0){
				blueMap[y][i]=2;
				blueMap[y+1][i]=3;
				break;
			}
		}
		//red
		for (int i = y; i < 10; ++i)
		{
			if(i==9){
				redMap[i][x]=1;
				redMap[i-1][x]=1;
				break;
			}
			if(redMap[i+1][x]!=0){
				redMap[i][x]=1;
				redMap[i-1][x]=1;
				break;
			}

		}

	}

}


bool checkBuleBlock(){
	bool totalCheck=false;
	for (int i = 4; i < 10; ++i)
	{
		bool check=true;
		for(int j=0; j<4; j++){
			if(blueMap[j][i]==0){
				check=false;
				break;
			}
		}

		if(check){
			totalCheck=true;
			answer++;
			for(int j=0; j<4; j++){
				blueMap[j][i]=0;
			}
		}
	}
	return totalCheck;
}

bool checkRedBlock(){
	bool totalCheck=false;
	for (int i = 4; i < 10; ++i)
	{
		bool check=true;
		for(int j=0; j<4; j++){
			if(redMap[i][j]==0){
				check=false;
				break;
			}
		}

		if(check){
			totalCheck=true;
			answer++;
			for(int j=0; j<4; j++){
				redMap[i][j]=0;
			}
			
		}
	}
	
	return totalCheck;
}


void moveRight(){
	bool isMove=true;
	while(isMove){
		isMove=false;
		for(int i=9; i>4; i--){
			for (int j = 0; j < 4; ++j)
			{
				if(blueMap[j][i]==0){
					if(blueMap[j][i-1]==1){
						blueMap[j][i]=1;
						blueMap[j][i-1]=0;
						isMove=true;
					}
					else if(blueMap[j][i-1]==2){
						if(blueMap[j+1][i]==0){
							blueMap[j][i]=2;
							blueMap[j+1][i]=3;
							blueMap[j][i-1]=0;
							blueMap[j+1][i-1]=0;
							isMove=true;
						}
					}
				}
			}
		}
	}
}


void moveDown(){
	bool isMove=true;
	while(isMove){
		isMove=false;
		for(int i=9; i>4; i--){
			for (int j = 0; j < 4; ++j)
			{
				if(redMap[i][j]==0){
					if(redMap[i-1][j]==1){
						redMap[i][j]=1;
						redMap[i-1][j]=0;
						isMove=true;
					}
					else if(redMap[i-1][j]==2){
						if(redMap[i][j+1]==0){
							redMap[i][j]=2;
							redMap[i][j+1]=3;
							redMap[i-1][j]=0;
							redMap[i-1][j+1]=0;
							isMove=true;
						}
					}
				}
			}
		}
	}
}

void clearBlocks(){
	
	while(1){
		if(!checkBuleBlock())
			break;
		moveRight();
	}
	
	while(1){
		if(!checkRedBlock())
			break;
		moveDown();
	}
	
}

void checkTopBlock(){
	int BCnt=0;
	for (int i = 4; i < 6; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(blueMap[j][i]!=0){
				BCnt++;
				break;
			}
		}
	}

	int RCnt=0;
	for (int i = 4; i < 6; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(redMap[i][j]!=0){
				RCnt++;
				break;
			}
		}
	}

	for (int i = 9; i >9-BCnt ; i--)
	{
		for (int j = 0; j <4; ++j)
		{
			blueMap[j][i]=0;
		}
	}

	for (int i = 9; i >9-RCnt ; i--)
	{
		for (int j = 0; j <4; ++j)
		{
			redMap[i][j]=0;
		}
	}

	if(BCnt>0)
		moveRight();
	if(RCnt>0)
		moveDown();

}


int main(){
	memset(blueMap,0,sizeof(blueMap));
	memset(redMap,0,sizeof(redMap));
	int n;
	cin >> n;
	while(n--){
		int t,y,x;
		cin >> t >> y >> x;
		move(t,y,x);
		clearBlocks();
		checkTopBlock();
		
	}
	int blockCnt=0;
	for (int i = 4; i < 10; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(redMap[i][j]!=0)
				blockCnt++;
			if(blueMap[j][i]!=0){
				blockCnt++;
			}
		}
	}
	cout<<answer<<endl;
	cout<<blockCnt;

}
