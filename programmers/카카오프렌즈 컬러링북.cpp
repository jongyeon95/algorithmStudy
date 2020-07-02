#include<iostream>
#include<queue>
#include<vector>

using namespace std;


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    bool visit[100][100] = { 0, }; // 방문 체크
    int number_of_area = 0; // 영역 갯수
    int max_size_of_one_area = 0;
    int idx = 0;// 색 

    queue<pair<int, int>>q;

    for (int j = 0; j < picture.size(); j++)
    {
        for (int i = 0; i < picture[j].size(); i++)
        {
            int area = 0; // 새로운 영역의 넓이

            // 색이 칠해져있고 방문 하지 않았다면
            if (picture[j][i] != 0 && !visit[i][j])
            {
                q.push({i, j});
                idx = picture[j][i];
                number_of_area++;
                area++;
                visit[i][j] = true;         
            }

            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;           
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int tx = x + dx[k];
                    int ty = y + dy[k];

                    if (tx<0 || tx>=n || ty<0 || ty>=m)
                        continue;
                    // 앞으로 갈 위치의 색과 현재 색이 같고 방문 하지 않았다면
                    if (idx == picture[ty][tx] && !visit[tx][ty])
                    {
                        q.push({tx,ty});
                        area++;
                        visit[tx][ty] = true;
                    }
                }
            }
            // 제일 큰 넓이 구하기
            if(max_size_of_one_area < area)
                max_size_of_one_area=area;    
        }

    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;


    return answer;
}