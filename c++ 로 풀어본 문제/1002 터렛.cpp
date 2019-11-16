#include <iostream>
#include <cmath>
using namespace std;
int main(){
	
	int x1,x2,y1,y2,r1,r2,testcase;
	cin >> testcase;
	while(testcase--){
		cin >> x1 >> y1>>r1 >>x2>>y2>>r2;
		
		double disXY=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
		double disR=r2+r1;
		double disRminus=abs(r2-r1);
		
		if(disXY==0){
			if(disRminus==0)
				cout<<-1<<endl;
			else
				cout<<0<<endl;
		}
		else if(disRminus < disXY && disXY < disR)
			cout << 2 << endl;
		else if(disXY==disR || disXY==disRminus)
			cout << 1 << endl;
		else 
			cout << 0 <<endl;
		}
	

}