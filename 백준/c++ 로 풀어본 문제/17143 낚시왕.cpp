#include <iostream>
#include <vector>
using namespace std;
int R,C,M;
int kingLocation=0; // 낚시왕 위치
int answer=0;

struct Shark
{
	int index;// 상어 번호 
	int y;// 위치 
	int x;// 위치 
	int speed;// 속력 
	int dir;// 방향 
	int size;// 크기
};

vector<int> map[101][101]; // 상어 번호 넣을 맵 
vector<Shark> shark; // 상어 정보

void input(){
	cin >> R >> C >> M;
	for (int i = 0; i < M; ++i)
	{
		int y,x,speed,dir,size;
		cin >> y >> x >> speed >> dir >> size;
		shark.push_back({i,y,x,speed,dir,size});
		map[y][x].push_back(i);
	}
}

// 상어 잡기 
void Hunt(){
	for (int i = 1; i <= R; ++i)
	{
		if(map[i][kingLocation].size()>0){
			answer+=shark[map[i][kingLocation][0]].size;
			shark[map[i][kingLocation][0]].size=-1;// 잡은 상어는 크기를 -1로 변경해서 예외 처리
			map[i][kingLocation].pop_back();
			break;
		}
	}
}

void MoveShark(){

	vector<int> tempMap[101][101]; // map에 복사할 임시 map
	for (int i = 0; i < shark.size(); ++i)
	{
		// 잡히거나 먹힌 상어는 제외
		if(shark[i].size==-1)
			continue;

		// 각 방향 별로 속력만큼 움직인다.
		// 벽을 만나면 flag 부호를 바꾸어 방향을 전환한다.

		if(shark[i].dir==1){
			int count=shark[i].speed;
			int flag=-1;
			while(count-- > 0){
				if(flag==-1&&shark[i].y==1){
					flag=1;
				}
				else if(flag==1&&shark[i].y==R){
					flag=-1;
				}

				shark[i].y+=flag;
			}
			if(flag==1){
				shark[i].dir=2;
			}

		}
		else if(shark[i].dir==2){
			int count=shark[i].speed;
			int flag=1;
			while(count-- > 0){
				if(flag==-1&&shark[i].y==1){
					flag=1;
				}
				else if(flag==1&&shark[i].y==R){
					flag=-1;
				}
				shark[i].y+=flag;
			}
			if(flag==-1){
				shark[i].dir=1;
			}
		}
		else if(shark[i].dir==3){
			int count=shark[i].speed;
			int flag=1;
			while(count-- > 0){
				if(flag==-1&&shark[i].x==1){
					flag=1;
				}
				else if(flag==1&&shark[i].x==C){
					flag=-1;
				}
				shark[i].x+=flag;
			}
			if(flag==-1){
				shark[i].dir=4;
			}
		}
		else if(shark[i].dir==4){
			int count=shark[i].speed;
			int flag=-1;
			while(count-- > 0){
				if(flag==-1&&shark[i].x==1){
					flag=1;
				}
				else if(flag==1&&shark[i].x==C){
					flag=-1;
				}
				shark[i].x+=flag;
			}
			if(flag==1){
				shark[i].dir=3;
			}
		}


		//상어가 위치할 공간에 다른 상어거 있다면
		//크기 비교 후 작은놈은 먹히고 큰놈만 위치에 남겨놓는다 
		if(tempMap[shark[i].y][shark[i].x].size()>0){
			if(shark[tempMap[shark[i].y][shark[i].x][0]].size>shark[i].size){
				shark[i].size=-1;
				continue;
			}
			else{
				shark[tempMap[shark[i].y][shark[i].x][0]].size=-1;
				tempMap[shark[i].y][shark[i].x].pop_back();
				tempMap[shark[i].y][shark[i].x].push_back(shark[i].index);

			}
		}
		else{
			tempMap[shark[i].y][shark[i].x].push_back(shark[i].index);
		}
		
	}

	// 복사
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if(map[i][j].size()>0)
				map[i][j].pop_back();
			if(tempMap[i][j].size()>0)
				map[i][j].push_back(tempMap[i][j][0]);
		}
	}

}

void solve(){
	while(1){
	kingLocation++;
	if(kingLocation>C)
		return;	
	Hunt();
	MoveShark();
	}
	

}

int main(){
	input();
	solve();
	cout << answer;
}