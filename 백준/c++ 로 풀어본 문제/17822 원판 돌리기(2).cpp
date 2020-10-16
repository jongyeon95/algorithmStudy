#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;
vector<deque<int>> circle;
int n,m,t;

void input(){
	cin >> n >> m>> t;
	circle.resize(n+1);
	for(int i=1; i<=n; i++){
		for(int j=0;j<m;j++){
			int temp;
			cin >> temp;
			circle[i].push_back(temp);
		}
	}
}

void move(int x, int d, int k){

	for(int i=x; i<circle.size(); i+=x){
		for(int j=0; j<k; j++){
			if(d==0){
				int temp=circle[i].back();
				circle[i].pop_back();
				circle[i].push_front(temp);
			}
			else{
				int temp=circle[i].front();
				circle[i].pop_front();
				circle[i].push_back(temp);
			}
		}
	}


}

void checkCircle(){
	bool check[51][50];
	bool IsSame=false;
	memset(check,false,sizeof(check));
	for(int i=1; i<circle.size(); i++){
		for(int j=0; j<circle[i].size(); j++){
			if(circle[i][j]==-1)
				continue;
			if(j==0){
				if(circle[i][0]==circle[i].back()){
					check[i][0]=true;
					check[i][circle[i].size()-1]=true;
					IsSame=true;
				}
			}
			if(j<circle[i].size()-1){
				if(circle[i][j]==circle[i][j+1]){
					check[i][j]=true;
					check[i][j+1]=true;
					IsSame=true;
				}
			}
			if(i>1){
				if(circle[i][j]==circle[i-1][j]){
					check[i-1][j]=true;
					check[i][j]=true;
					IsSame=true;
				}
			}
		}
	}
	

	if(IsSame){
		for (int i = 1; i <circle.size(); ++i)
		{
			for(int j=0; j<circle[i].size(); j++){
				if(check[i][j])
					circle[i][j]=-1;
			}
		}
	}
	else{
		double count=0;
		double total=0;
		for (int i = 1; i <circle.size(); ++i)
		{
			for(int j=0; j<circle[i].size(); j++){
				if(circle[i][j]!=-1){
					count++;
					total+=circle[i][j];
				}
			}
		}
		
		double compareNum=total/count;
		

		for (int i = 1; i <circle.size(); ++i)
		{
			for(int j=0; j<circle[i].size(); j++){
				if(circle[i][j]==-1)
					continue;
				if(circle[i][j]<compareNum){
					circle[i][j]++;
				}
				else if(circle[i][j]>compareNum)
					circle[i][j]--;
			}
		}

	}

	


}

int printAnswer(){
	int answer=0;
	for(int i=1; i<circle.size(); i++){
		for (int j = 0; j < circle[i].size(); ++j)
		{
			if(circle[i][j]!=-1){
				answer+=circle[i][j];
			}
		}
	}
	return answer;
}

int main(){
	input();
	for (int i = 0; i < t; ++i)
	{
		int x,d,k;
		cin >> x>>d>>k;
		move(x,d,k);
		checkCircle();
	}
	cout<<printAnswer();


}