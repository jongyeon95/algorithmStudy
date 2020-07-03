#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int map[9][9];
        bool result=true;
        
        //입력
        for(int i=0; i<9; i++){
        	for(int j=0; j<9; j++){
            	cin >> map[i][j];
            }
        }
        
        //가로
        for(int i=0; i<9; i++){
            if(!result) break; // 앞에서 한번이라도 불만족시 break
            int check[9]={0,};
        	for(int j=0; j<9; j++){
            	if(check[map[i][j]-1]>0){
                    result=false;
                    break;
                }
                else
                    check[map[i][j]-1]+=1;
            }
        }
        
        //세로
        for(int i=0; i<9; i++){
            if(!result) break; // 앞에서 한번이라도 불만족시 break
            int check[9]={0,};
        	for(int j=0; j<9; j++){
            	if(check[map[j][i]-1]>0){
                    result=false;
                    break;
                }
                else
                    check[map[j][i]-1]+=1;
            }
        }
        
        //3*3 사각형
        for(int i = 0; i < 3; i++) {
            if(!result) break; // 앞에서 한번이라도 불만족시 break
            for(int j = 0; j < 3; j++) {
                int check[9]={0,};
				for(int k = 0; k < 3; k++) {
					for(int s = 0; s < 3; s++) {
						if(check[map[3*i + k][3*j + s]-1]>0){
                            result=false;
                       		break;
                        }
                        else
                            check[map[3*i + k][3*j + s]-1]+=1;
					}
				}
			}
		}

        cout <<"#"<<test_case<<" "<<result<<"\n";

	}
	return 0;
}