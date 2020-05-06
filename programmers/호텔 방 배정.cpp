#include <string>
#include <vector>
#include <map>
using namespace std;

map<long, long> room_map;

long long findRoom(long long num) {
	if (room_map[num] == 0) {
		return num;
	}
	else {
		room_map[num] = findRoom(room_map[num]);
		return room_map[num];
	}
}


vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	long long roomN;
	long long other;

	for(int i = 0; i < room_number.size(); i++){
		roomN = room_number[i];
		if(room_map[roomN] == 0){
			answer.push_back(roomN);
			room_map[roomN] = findRoom(roomN + 1);
		}
		else{ 
			other = findRoom(roomN);
			answer.push_back(other);
			room_map[other] = findRoom(other + 1);
		} 
	}
	return answer; 
}