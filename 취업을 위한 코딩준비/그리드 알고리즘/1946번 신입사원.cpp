#include <iostream>
#include <algorithm>
using namespace std;
bool comp(int *a, int *b)
{
 if (a[0] < b[0])
  return true;
 else
  return false;
}
int main(){
	int Tcase;
	cin >> Tcase;
	for(int i=0; i<Tcase; i++){
		int N;
		cin >> N;
		int emp[N][2];
		for(int j=0; j<N;j++){
			cin >> emp[j][0];
			cin >> emp[j][1];
		}
		sort(emp,emp+N,comp);
		cout<< emp << "\n";
	}

} ing..
