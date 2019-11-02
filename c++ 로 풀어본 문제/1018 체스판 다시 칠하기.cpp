#include <iostream>
#include <cstring>
using namespace std;
int result=64;// 최대 다 다시 칠해도 64
int n,m;
char Wstart[8]={'W','B','W','B','W','B','W','B'}; // W 줄 시작 
char Bstart[8]={'B','W','B','W','B','W','B','W'}; // B 줄 시작 
char OriginMap[50][50];

void solve(int StartX, int StartY){
	char TempMap[8][8]; // 8*8 복사할  임시 체스판 
	int TempResult=0;
	int x=StartX;
	int y=StartY;

	for (int i = 0; i < 8; i++){ // 초기화 
		for (int j = 0; j < 8; j++){
			TempMap[i][j]=OriginMap[x][y];
			y++;
		}
		y=StartY;
		x++;
	}

	for (int i = 0; i < 8; i++){ // W로 시작했을때 
		for (int j = 0; j < 8; j++){
			if(i%2==0){
				if(TempMap[i][j]!=Wstart[j])
					TempResult++;
			}
			else{
				if(TempMap[i][j]!=Bstart[j])
					TempResult++;
			}
			
		}
	}

	if(TempResult<result){
		result=TempResult;
	}
	TempResult=0;

	for (int i = 0; i < 8; i++){ // B로 시작했을때 
		for (int j = 0; j < 8; j++){
			if(i%2==0){
				if(TempMap[i][j]!=Bstart[j])
					TempResult++;
			}
			else{
				if(TempMap[i][j]!=Wstart[j])
					TempResult++;
			}
			
		}
	}

	if(TempResult<result){
		result=TempResult;
	}
	TempResult=0;

}



int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> OriginMap[i][j];
		}
	}

	for(int i=0;i<=n-8;i++){
		for(int j=0;j<=m-8;j++){
			solve(i,j);
		}
	}

	cout << result;



}