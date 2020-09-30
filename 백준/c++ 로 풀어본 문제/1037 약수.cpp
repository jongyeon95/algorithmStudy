#include <iostream>

using namespace std;
int main(){
	int n;
	cin >> n;
	
	int max,min;

	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;
		if(i==0){
			max=temp;
			min=temp;
		}
		if(temp>max)
			max=temp;
		if(temp<min)
			min=temp;
	}
	cout<< max*min;
}