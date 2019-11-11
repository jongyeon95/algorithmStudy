#include <iostream>
#include <vector>

using namespace std;
int main(){
	int testcase;
	cin >> testcase;
	while(testcase--){
		int n;
		vector<pair<int,int>> v;
		cin >> n;
		int division=2;
		while(1){
			if(n==1)
				break;
			if(n%division==0){
				n/=division;
				bool check=true;
				for (int i = 0; i < v.size(); i++)
				{
					if(v[i].first==division){
						v[i].second++;
						check=false;
						break;
					}
				}
				if(check)
					v.push_back(pair<int,int>(division,1));
			}
			else
				division++;

		}

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i].first << " " << v[i].second << " \n";
		}
	}

}