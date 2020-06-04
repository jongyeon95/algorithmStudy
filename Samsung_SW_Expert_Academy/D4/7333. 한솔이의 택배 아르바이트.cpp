#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; ++t)
	{
		int n;
		cin >> n;
		deque<int> d;
		int result=0;
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			d.push_back(temp);
		}
		sort(d.begin(),d.end());

		while(d.size()>0){


			int temp=50/d.back();

			if(d.back()*d.size()<50){
				break;
			}

			if(50%d.back()==0){
				temp--;
			}

			if(d.back()==50){
				result++;
				d.pop_back();
				continue;
			}

			d.pop_back();
			
			for(int i=0; i<temp; i++){
				d.pop_front();
			}
			result++;
		}
		if(result==0){
			result++;
		}

		cout <<"#"<<t<<" "<<result <<"\n";
	}


}