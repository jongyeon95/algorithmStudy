#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

deque<int> sawTooth[4];
vector<pair<int,int>> command;
bool check[4];
int rotateDir[4];
int k;

void input(){

	for (int i = 0; i < 4; ++i){
		string s;
		cin >> s;
		for (int j = 0; j < 8; ++j)
				sawTooth[i].push_back(s[j]-'0');
	}

	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		int a,b;
		cin >> a >> b;
		command.push_back({a,b});
	}

}

void rotate(){
	for (int i = 0; i < 4; ++i)
	{
		if(check[i]){
			if(rotateDir[i]==1){
				int temp=sawTooth[i].back();
				sawTooth[i].push_front(temp);
				sawTooth[i].pop_back();
			}
			else if(rotateDir[i]==-1){
				
				int temp=sawTooth[i].front();
				sawTooth[i].push_back(temp);
				sawTooth[i].pop_front();
			}
			

		}
	}

}


void solve(){

for(int i=0; i<k; i++){
	
	memset(check,false,sizeof(check));
	memset(rotateDir,0,sizeof(rotateDir));
	check[command[i].first-1]=true;
	rotateDir[command[i].first-1]=command[i].second;

	for (int j = command[i].first-1; j < 3; ++j)
	{
		if(sawTooth[j][2]!=sawTooth[j+1][6]){
			check[j+1]=true;
			rotateDir[j+1]=rotateDir[j]*-1;
		}
		else
			break;
	}
	for (int j = command[i].first-1; j > 0; j--)
	{
		if(sawTooth[j][6]!=sawTooth[j-1][2]){
			check[j-1]=true;
			rotateDir[j-1]=rotateDir[j]*-1;
		}
		else
			break;
	}
	
	rotate();
}



}

int main(){

	input();
	solve();
	int flag=1;
	int result=0;
	for (int i = 0; i < 4; ++i)
	{
		
		if(sawTooth[i][0]==1){
			result+=flag;
		}
		flag*=2;
	}



	cout << result;


	
}