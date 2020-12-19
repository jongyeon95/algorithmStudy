#include <iostream>
#include <string>
#include <map>
using namespace std;

char column[] ={'A','B','C','D','E','F','G','H'};

struct xy
{
	int y;
	int x;
};

xy k;
xy s;
string king;
string stone;
int moveCount;
map<string,pair<int,int>> m;

void input(){
	cin >> king >> stone >> moveCount;
	k.x=king[0]-'A';
	k.y=king[1]-'0';
	s.x=stone[0]-'A';
	s.y=stone[1]-'0';
	m.insert({"R",{0,1}});
	m.insert({"L",{0,-1}});
	m.insert({"B",{-1,0}});
	m.insert({"T",{1,0}});
	m.insert({"RT",{1,1}});
	m.insert({"LT",{1,-1}});
	m.insert({"RB",{-1,1}});
	m.insert({"LB",{-1,-1}});
}

int main(){
	input();
	while(moveCount--){
		string temp;
		cin >> temp;
		pair<int , int> command;
		command=m.find(temp)->second;
		int ty=command.first;
		int tx=command.second;
		
		if(ty+k.y>0&&ty+k.y<=8&&tx+k.x>=0&&tx+k.x<8){
			if(s.y==ty+k.y&&s.x==tx+k.x){
				if(ty+s.y>0&&ty+s.y<=8&&tx+s.x>=0&&tx+s.x<8){
					s.y+=ty;
					s.x+=tx;
					k.y+=ty;
					k.x+=tx;
				}
			}
			else{
				k.y+=ty;
				k.x+=tx;
			}
		}
		
	
	}
	
	cout<<column[k.x]<<k.y<<endl;
	cout<<column[s.x]<<s.y<<endl;

}