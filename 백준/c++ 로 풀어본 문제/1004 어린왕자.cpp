#include <iostream>
using namespace std;
int main(){
	int testcase;
	int x1,y1,x2,y2;
	int n;
	cin >> testcase;
	while(testcase--){
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		int result=0;
		for (int i = 0; i < n; ++i)
		 {
		 	int a,b,c;
		 	bool x1Check, x2Check;
		 	x1Check=false;
		 	x2Check=false;
		 	cin >> a >>b >>c;
		 	if((a-x1)*(a-x1)+(b-y1)*(b-y1)<c*c){
		 		x1Check=true;
		 	}
		 	if((a-x2)*(a-x2)+(b-y2)*(b-y2)<c*c){
		 		x2Check=true;
		 	}
		 	if(x1Check!=x2Check)
		 		result++;
		 } 
		 cout << result <<endl;

	}
}