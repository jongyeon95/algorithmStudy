#include <iostream>

using namespace std;


int N, F;


int sol()

{
        int start = (N / 100) * 100;
        int result;
        for (int i = start; i < (start + 100); i++)
                 if (i % F == 0)
                 {
                         result = i % 100;
                        break;
                 }
        return result;

}


int main()
{

        cin >> N >> F;

 

        int result = sol();

        if (result >= 0 && result < 10)

                 cout << "0";

        cout << result << endl;

        return 0;

}

