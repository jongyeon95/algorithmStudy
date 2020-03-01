#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int max=246913; // 최대값 
	bool num[246913];
	memset(num,true,sizeof(num)); 
	vector<int> v;
	int temp;
	while(1){
		cin >> temp;
		if(temp==0)
			break;
		else
			v.push_back(temp);
	}
		
	num[1]=false;
	for (int i = 2; i <= max; i++)
	{
		for(int j=i*2; j<=max;j+=i){
			if(!num[j])
				continue;
			num[j]=false;
		}
	}
	int j=0;
	while(1){
		if (j==v.size())
			break;
		int cnt=0;
		for (int i = v[j]+1; i <=2*v[j] ; i++)
		{
			if(num[i])
				cnt++;
		}
		cout << cnt << endl;
		j++;

	}

}