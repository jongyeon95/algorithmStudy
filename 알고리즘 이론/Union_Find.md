# Union-Find

## Union-Find의 개념
### Union Find란
Disjoint Set(서로소 집합)을 표현할 때 사용하는 알고리즘
- 집합을 구현하는 데는 비트 벡터, 배열, 연결 리스트를 이용할 수도 있으나 그 중 가장 효율적인 트리구조를 이용하여 구현

### Union Find의 연산
- make-set(x)
  - 초기화
  - x를 유일한 원소로 하는 새로운 집합을 만든다.
- union(x, y)
  - 합하기
  - x가 속한 집합과 y가 속한 집합을 합친다. 즉 x와 y가 속한 두 집합을 합치는 연산이다.
- find(x)
  - 찾기 
  - x가 속한 집합의 대표값을 반환한다. 즉 x가 어떤 집합에 속해 있는지 찾는 연산.

 ### 기본적인 구현
  ```c++
  int root[MAX_SIZE];

  //초기화
  for (int i = 0; i < MAX_SIZE; ++i)
   {
   	 parent[i]=i;
   }


   //재귀를 이용한 find(x)
   int find(int x){
   		//루트 노드는 부모 노드 번호이므로 자기 자신 환환
   		if(root[x]==x)
   			return x;
   		else
   			//각 노드의 부모 노드를 찾아 올라감
   			return find(root[x]);
   }

   //union
   void union(int ,x int y){
   	x= find(x);
   	y= find(y);
   	root[y]=x;
   }

  ```
