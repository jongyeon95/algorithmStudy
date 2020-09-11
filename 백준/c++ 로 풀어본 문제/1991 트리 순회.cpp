#include <iostream>
using namespace std;
char node[26][3];
int n;

void dfsA(int index){

	cout<<node[index][0];
	if(node[index][1]!='.')
		dfsA(node[index][1]-'A');
	if(node[index][2]!='.')
		dfsA(node[index][2]-'A');
}

void dfsB(int index){

	if(node[index][1]!='.')
		dfsB(node[index][1]-'A');
	
	cout<<node[index][0];
	
	if(node[index][2]!='.')
		dfsB(node[index][2]-'A');
}

void dfsC(int index){

	if(node[index][1]!='.')
		dfsC(node[index][1]-'A');
	
	if(node[index][2]!='.')
		dfsC(node[index][2]-'A');

	cout<<node[index][0];
	
}

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i){
		char temp;
		cin >> temp;
		node[temp-'A'][0]=temp;
		cin >> node[temp-'A'][1] >> node[temp-'A'][2];
	}

	dfsA(0);
	cout<<endl;
	dfsB(0);
	cout<<endl;
	dfsC(0);
		
}