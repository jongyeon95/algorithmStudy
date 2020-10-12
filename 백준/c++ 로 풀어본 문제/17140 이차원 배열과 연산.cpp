#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
int r,c,k;
int answer=-1;
int arr[100][100];
struct Number
{
	int num;
	int cnt;
	
};

bool cmp(Number a, Number b){
	if(a.cnt==b.cnt){
		return a.num<b.num;
	}
	return a.cnt<b.cnt;
}

void solved(int cnt, int y, int x){
	while(cnt<=100){
		if(cnt>100){
			answer=-1;
			return;
		}


		if(arr[r-1][c-1]==k){
			answer=cnt;
			return;
		}


		int ty=0;
		int tx=0;
		int temp[100][100];
		memset(temp,0,sizeof(temp));

		if(y>=x){
			for (int i = 0; i < y; ++i)
			{
				map<int,int> m;
				vector<Number> Ntemp;
				for (int j = 0; j < x; ++j)
				{
					if(arr[i][j]==0)
						continue;
					if(m.find(arr[i][j])==m.end()){
						m.insert({arr[i][j],1});
					}
					else{
						m[arr[i][j]]++;
					}
				}
				map<int, int>::iterator iter;
				for (iter=m.begin(); iter !=m.end(); iter++)
				{
					Number n={iter->first,iter->second};
					Ntemp.push_back(n);
				}
				sort(Ntemp.begin(), Ntemp.end(), cmp);
				int flag=0;
				for (int j = 0; j < Ntemp.size(); j++)
				{
					if(flag>=100)
						break;
					temp[i][flag]=Ntemp[j].num;
					flag++;
					temp[i][flag]=Ntemp[j].cnt;
					flag++;
				}
				if(flag>tx){
					tx=flag;
				}
			}
			ty=y;
		}
		else{
			for (int i = 0; i < x; ++i)
			{
				map<int,int> m;
				vector<Number> Ntemp;
				for (int j = 0; j < y; ++j)
				{
					if(arr[j][i]==0)
						continue;
					if(m.find(arr[j][i])==m.end()){
						m.insert({arr[j][i],1});
					}
					else{
						m[arr[j][i]]++;
					}
				}
				map<int, int>::iterator iter;
				for (iter=m.begin(); iter !=m.end(); iter++)
				{
					Number n={iter->first,iter->second};
					Ntemp.push_back(n);
				}

				sort(Ntemp.begin(), Ntemp.end(), cmp);
				int flag=0;
				for (int j = 0; j < Ntemp.size(); j++)
				{
					if(flag>=100)
						break;
					temp[flag][i]=Ntemp[j].num;
					flag++;
					temp[flag][i]=Ntemp[j].cnt;
					flag++;
				}
				if(flag>ty){
					ty=flag;
				}
			}
			tx=x;
		}

		memset(arr,0,sizeof(arr));
		for (int i = 0; i < ty; ++i)
		{
			for (int j = 0; j < tx; ++j)
			{
				arr[i][j]=temp[i][j];
			}
		}

		y=ty;
		x=tx;
		cnt++;
	}
	
}

int main(){
	
	memset(arr,0,sizeof(arr));

	cin >> r >> c >> k;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> arr[i][j];
		}
	}
	solved(0,3,3);
	cout << answer;


}