#include <iostream>
using namespace std;
//#=-1 , .=0; 0=1; R=2, B=3;
struct Ball
{
	int ry;
	int rx;
	int by;
	int bx;
};

int map[10][10];
int n,m;
Ball ball;
int YX[][2]={{0,-1},{-1,0},{0,1},{1,0}};
int answer=0;


void input(){
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin>>s;
		for (int j = 0; j < s.size(); ++j)
		{
			if(s[j]=='#')	map[i][j]=-1;
			else if(s[j]=='O')	map[i][j]=1;
			else if(s[j]=='R'){
				map[i][j]=0;
				ball.ry=i;
				ball.rx=j;
			}
			else if(s[j]=='B'){
				map[i][j]=0;
				ball.by=i;
				ball.bx=j;
			}	
			else map[i][j]=0;
		}
	}
}
Ball move(Ball b,int dir){

	//좌
	Ball temp;
	temp=b;
	bool blueCheck=false;
	bool redCheck=false;
	while(1){
		int ty=temp.ry+YX[dir][0];
		int tx=temp.rx+YX[dir][1];
		if(map[ty][tx]==-1){
			break;
		}
		else if(map[ty][tx]==1){
			redCheck=true;
			break;
		}
		else{
			temp.ry=ty;
			temp.rx=tx;
		}
	}

	while(1){
		int ty=temp.by+YX[dir][0];
		int tx=temp.bx+YX[dir][1];
		if(map[ty][tx]==-1){
			break;
		}
		else if(map[ty][tx]==1){
			blueCheck=true;
			break;
		}
		else{
			temp.by=ty;
			temp.bx=tx;
		}
	}
	
	if(blueCheck&&redCheck){
		temp.ry=-1;
		return temp;
	}
	else if(redCheck){
		temp.ry=-2;
		return temp;
	}
	else if(blueCheck){
		temp.ry=-1;
		return temp;
	}

	if(temp.ry==temp.by&&temp.rx==temp.bx){
		if(dir==0){
			if(b.bx<b.rx){
				temp.rx++;
			}
			else{
				temp.bx++;
			}
		}
		else if(dir==2){
			if(b.bx<b.rx){
				temp.bx--;
			}
			else{
				temp.rx--;
			}
		}
		else if(dir==1){
			if(b.by<b.ry){
				temp.ry++;
			}
			else{
				temp.by++;
			}
		}
		else if(dir==3){
			if(b.by<b.ry){
				temp.by--;
			}
			else{
				temp.ry--;
			}
		}

	}

	return temp;
	

}

void dfs(Ball b, int cnt){
	if(cnt>=10){
		return;
	}
	if(answer==1)
		return;
		
	for (int i = 0; i < 4; ++i)
	{
		Ball temp=move(b,i);
		if(temp.ry==-1){
			continue;
		}
		else if(temp.ry==-2){
			answer=1;
		}
		else{
			dfs(temp,cnt+1);
		}
	}


}

int main(){

	input();
	dfs(ball,0);
	
	cout<<answer;

}