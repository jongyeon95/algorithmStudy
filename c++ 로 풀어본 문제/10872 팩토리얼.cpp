#include <iostream>
using namespace std;

void Factorial(int k){
   int result=1;
   for(int i=k; i>1; i--){
      result*=i;
   }
   cout << result;
}

int main() {
   int n;
   cin >> n;
   Factorial(n);
   return 0;
}