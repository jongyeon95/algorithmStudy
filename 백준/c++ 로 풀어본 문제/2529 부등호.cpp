#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool check[10];
string question="";
string maxResult="0000000000";
string minResult="9999999999";
int k;

void dfs(string t,int flag){
	if(t.size()==k+1){
		if(t.compare(maxResult)>0)
			maxResult=t;
		if (t.compare(minResult)<0)
			minResult=t;
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		if(!check[i]){
			if(question[flag]=='>'){
				if(t[flag]-'0'>i){
					check[i]=true;
					string temp=t;
					temp+=i+'0';
					dfs(temp,flag+1);
					check[i]=false;
				}
			}
			else{
				if(t[flag]-'0'<i){
					check[i]=true;
					string temp=t;
					temp+=i+'0';
					dfs(temp,flag+1);
					check[i]=false;
				}
			}
		}
	}

}

int main(){
	memset(check,false,sizeof(check));
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		char c;
		cin >> c;
		question+=c;
	}
	
	for (int i = 0; i < 10; ++i)
	{
		string temp="";
		check[i]=true;
		temp+=i+'0';
		dfs(temp,0);
		check[i]=false;
		
	}

	cout << maxResult << endl << minResult;



}