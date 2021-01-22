# 너비 우선 탐색(BFS, Breadth-First Search)

## BFS의 개념

### BFS란

- 루트 노드(혹은 다른 임의의 노드)에서 시작해서 인접한 노드를 먼저 탐색하는 방법이다.
- 시작 정점으로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회 방법.
  <br/>

### BFS의 특징

- 직관적이지 않은 면이 있다.
- 재귀적으로 동작하지 않는다.
- 어떤 노드를 방문했었는지 여부를 반드시 검사해야한다.
- 선입선출 원칙으로 탐색을하고 Queue 자료구조를 사용한다.
  <br/>

### BFS를 사용하는 경우

- 두 노드 사이의 최단 경로를 찾고 싶을 때.
- 임의의 경로를 찾고 싶을 때.
- Ex) 한 학급의 모든 친구관계를 그래프로 표현한 후 A와 D사이에 존재하는 경로를 찾는 경우
- DFS의 경우 모든 친구 관계를 다 살펴봐야 할 수도 있다.
- BFS의 경우 A와 가까운 관계부터 탐색을 한다.
  <br/>

### BFS의 과정

<br/>
<img src=https://github.com/jongyeon95/algorithmStudy/blob/master/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%20%EC%9D%B4%EB%A1%A0/images/DFS.png width="800px" height="600px"></img><br/><br/>

### BFS 구현

```c++
int arr[4][4]={
	{0,1,0,1},
	{1,0,0,0},
	{0,0,0,0},
	{1,0,0,0}
}

bool visit[4];

void bfs(int start){ 
  	queue<int> q; 
  	q.push(start); 
  	visit[start] = true; 
  	while(!q.empty()){
   // 큐에 값이 있을경우 계속 반복 실행 
   // 큐에 값이 있다. => 아직 방문하지 않은 노드가 존재 한다. 
	   int x = q.front(); 
	   q.pop(); 
	   printf("%d ", x); 
	   for(int i=0; i< arr[x].size(); i++){ 
		   int y = arr[x][i]; 
		   if(!visit[y]){ 
		   // 방문하지 않았다면 방문 표시
		   	visit[y] = true;
		   	q.push(y); 
	  		} 
		} 
	}
}

  ```
