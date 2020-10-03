#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool check[4000001];
vector<int> v;
void init(){
	memset(check,false,sizeof(check));
	for(int i=2; i<=4000000; i++){
		if(check[i])
			continue;
		v.push_back(i);
		for(int j=i+i; j<=4000000;j+=i){
			check[j]=true;
		}
	}

}
int main(){
	init();
	int n;
	int result=0;
	int backFlag=0;
	int answer=0;
	cin >> n;
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i]>n)
			break;
		
		while(result<=n&&backFlag<v.size()){
			result+=v[backFlag];
			backFlag++;
			if(result==n){
				answer++;
				break;
			}
		}
		result-=v[i];
		if(result==n){
			answer++;
		}
	}
	cout<<answer;

}