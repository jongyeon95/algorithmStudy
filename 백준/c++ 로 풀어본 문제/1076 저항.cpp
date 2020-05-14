#include <iostream>
#include <cmath>

using namespace std;

int ohm[3];

int main() {
    string input[3];
    string color[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    
    
    for(int i=0; i<3; i++){
        cin >> input[i];
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<10; j++){
            if(input[i] == color[j]) {
                ohm[i] = j;
                break;
            }
        }       
    }
    
    int num = ohm[0]*10 + ohm[1];
    
    if(num == 0) {
        cout << "0\n";
        return 0;
    } else {
        cout << num;
        for(int i=0; i<ohm[2]; i++){
            cout << "0";
        }
        cout << "\n";
    }   
    return 0;}