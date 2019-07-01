#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool check(string &passwd){
int ja = 0;
    int mo = 0;
    for (char x : passwd) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            mo += 1;
        } else {
            ja += 1;
        }
    }
    return ja >= 2 && mo >= 1;
}

void sol(int length,vector<char> &k,string passwd,int i){
	if (passwd.length()==length)// 모음 , 자음 조건 식별자
	{
		if (check(passwd)) {
            cout << passwd << '\n';
        }
        return;
	}
	if (i== k.size())
	{
		return;
	}

	sol(length,k,passwd+k[i],i+1);
	sol(length,k,passwd,i+1);

}


int main(){

int L,C;
cin >> L >> C;
vector<char> k(C);
for (int i = 0; i < C; i++)
{
	cin >>k[i];
}

sort(k.begin(),k.end());
sol(L,k,"",0);
return 0;
}