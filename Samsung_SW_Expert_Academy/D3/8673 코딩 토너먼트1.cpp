#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
	int testcase;
	int cnt=1;
	cin >> testcase;
	while(testcase--){
		int K;
		int result=0;
		vector<int> v;
		cin >> K;

		for (int i = 0; i < pow(2,K); i++)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}


		for (int i = 0; i < K; i++)
		{
			for (int j = 0; j < v.size()-1; j++)
			{
				result+=abs(v[j]-v[j+1]);
				if(v[j]>=v[j+1])
					v.erase(v.begin()+j+1);
				else
					v.erase(v.begin()+j);
			}
			/* code */
		}
		cout <<"#"<<cnt<<" "<<result <<endl;
		cnt++;





	}

}