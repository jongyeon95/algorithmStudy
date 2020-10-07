#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main(){
   int n,l;
   int answer=0;
   cin >> n >> l;
   int arr[n][n];
   for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
         cin >> arr[i][j];
      }
   }
   bool visited[n];
   for (int i = 0; i < n; ++i)
   {
      memset(visited,false,sizeof(visited));
      bool check=true;
      
      for (int j = 0; j < n-1; ++j)
      {
         if(abs(arr[i][j]-arr[i][j+1])>1){
            check=false;
            break;
         }

         else if(arr[i][j]-arr[i][j+1]==1){
            int temp=arr[i][j+1];
            if(j+l>=n){
               check=false;
               break;
            }
            for (int k = j+1; k<=j+l; ++k){
               if(arr[i][k]!=temp||visited[k]){
                  check=false;
                  break;
               }
            }
            if (check){
               for (int k = j+1; k<=j+l; ++k){
                 visited[k]=true;
               }
            }
                     
         }
         else if(arr[i][j]-arr[i][j+1]==-1){
            int temp=arr[i][j];
            if(j-l+1<0){
               check=false;
               break;
            }
            for (int k = j; k>=j-l+1; --k){
               if(arr[i][k]!=temp||visited[k]){
                  check=false;
                  break;
               }
            }
            if (check){
               for (int k = j; k>=j-l+1; --k){
                 visited[k]=true;
               }
            }

         }


      }
      if(check){
         answer++;
      }


   }
   for (int i = 0; i < n; ++i)
   {
      memset(visited,false,sizeof(visited));
      bool check=true;
      
      for (int j = 0; j < n-1; ++j)
      {
         if(abs(arr[j][i]-arr[j+1][i])>1){
            check=false;
            break;
         }

         else if(arr[j][i]-arr[j+1][i]==1){
            int temp=arr[j+1][i];
            if(j+l>=n){
               check=false;
               break;
            }
            for (int k = j+1; k<=j+l; ++k){
               if(arr[k][i]!=temp||visited[k]){
                  check=false;
                  break;
               }
            }
            if (check){
               for (int k = j+1; k<=j+l; ++k){
                 visited[k]=true;
               }
            }
                     
         }
         else if(arr[j][i]-arr[j+1][i]==-1){
            int temp=arr[j][i];
            if(j-l+1<0){
               check=false;
               break;
            }
            for (int k = j; k>=j-l+1; --k){
               if(arr[k][i]!=temp||visited[k]){
                  check=false;
                  break;
               }
            }
            if (check){
               for (int k = j; k>=j-l+1; --k){
                 visited[k]=true;
               }
            }

         }


      }
      if(check){
         answer++;
      }
      

   }

   cout<<answer;
}