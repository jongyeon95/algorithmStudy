#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int bucket[1000];
char result[1000];
//bool resultCheck=true;
bool resultCheck2=true;
vector<pair<pair<int,char>,bool>> v;

bool compare(pair<pair<int,char>,bool> p1, pair<pair<int,char>,bool> p2){

   if(p1.first.second==p2.first.second)
      return p1.first.first < p2.first.first;
   return p1.first.second < p2.first.second;

}

void InitResult(int n){
	for (int i = 0; i < n; i++)
   {
      result[i]='!';
   }
}


void InitCard(int n){
	for (int i = 0; i < n; i++)
   {
      int tempInt;
      char tempChar;
      cin >> tempInt >> tempChar;
      v.push_back(pair<pair<int,char>,bool>(make_pair(tempInt,tempChar),true));
   }
}

void InitBucket(int n){
	for(int i=0; i<n; i++){
		cin >>bucket[i];
	}
}


void solve(int start){
	if(resultCheck2){
		bool temp=true;
		if(start==n){
			for (int i = 0; i < n; ++i){
				if(result[i]=='!'){temp=false;}}
			if(temp){
				resultCheck2=false;
				return;
			}		
		}
		else{
		for(int i=0;i<n;i++){
			if(resultCheck2){
				if(v[i].second){
					if(v[i].second&&bucket[start]<=v[i].first.first){
						result[start]=v[i].first.second;
						v[i].second=false;
						solve(start+1);
						v[i].second=true;
						}
					}
				}
			}
		}
		if(result[start]=='!'){return;}
	}
}


int main(){
   
   cin >> n;
   InitCard(n);
   InitBucket(n);
   InitResult(n);
   sort(v.begin(),v.end(),compare);
   
   solve(0);

if(!resultCheck2){
	for (int i = 0; i < n; i++){
      cout <<result[i];
   }
}
   else
   	cout << -1;

}