#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n;
int num[11];
int calculate[4];
bool check[10];
int maxAns=-1000000000; // 최대 결과
int minAns=1000000000; //최소 결과
vector<int> calV; // +(0) -(1) *(2) /(3) 조합을 만들기 위해 만든 벡터 
vector<int> start; // dfs() 함수에 시작 할때 넣을 빈 벡터 

void input(){
	cin >> n;
	for(int i=0; i < n; i++)
		cin >> num[i];
	for(int i=0; i < 4; i++){
		cin >> calculate[i];
		for(int j=0; j<calculate[i]; j++){
			calV.push_back(i);
		}
	}
	memset(check,false,sizeof(check));
}


void solve(vector<int> v){
	int tempResult=num[0];
	for(int i=0; i<v.size(); i++){
		if(v[i]==0){
			tempResult+=num[i+1];
		}
		else if(v[i]==1){
			tempResult-=num[i+1];
		}
		else if(v[i]==2){
			tempResult*=num[i+1];
		}
		else{
			tempResult/=num[i+1];
		}
	}
	if(tempResult>maxAns)
		maxAns=tempResult;
	if(tempResult<minAns)
		minAns=tempResult;
	
}

// 조합 만들기
void dfs(vector<int> v){
	
	if(v.size()==n-1){
		solve(v);
		return;
	}

	for(int i=0; i<calV.size(); i++){
		if(check[i])
			continue;
		check[i]=true;
		v.push_back(calV[i]);
		dfs(v);
		v.pop_back();
		check[i]=false;
	}
	
}




int main(){
	input();
	dfs(start);
	cout << maxAns << "\n" << minAns;
}