#include <iostream>
#include <string>
using namespace std;
int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		string s;
		cin >> s;
		int arr[4];
		int size=s.size()-1;
		int outputFront;
		int outputBack;
		bool check=false;
		arr[0]=0;
		for (int i = 1; i < 4; ++i)
		{
			arr[i]=s[i-1]-'0';
		}
		if(arr[3]>4){
			arr[2]+=1;
			if(arr[2]==10){
				arr[2]=0;
				arr[1]+=1;
				if(arr[1]==10){
					arr[1]=0;
					arr[0]=1;
					outputFront=1;
					outputBack=0;
					check=true;
					size+=1;
				}

			}
		}
		if(!check){
			outputFront=arr[1];
			outputBack=arr[2];
		}
		cout<<"#"<<t<<" "<<outputFront<<"."<<outputBack<<"*10^"<<size<<"\n";


	}

}