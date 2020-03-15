# Spanning Tree

**Spanning Tree 란?
그래프 내의 모든 정점을 포함하는 트리이다.
 - Spanning Tree = 신장 트리
 - Spanning Tree는 그래프의 최소 연결 부분 그래프이다.
   - 최소 연결이란 간선의 수가 가장 적다는 것을 뜻한다.
   - n개의 정점을 가지는 그래프의 최소 간선의 수는 n-1개 이고, 정확히 n-1개로 연결되어 있으면 이것이 바로 Sapnning Tree이다.

**Spanning Treed의 특징
-DFS, BFS를 이용하여 그래프에서 Spanning Tree를 찾을 수 있다.
-하나의 그래프에는 많은 Spanning Tree가 존재할 수 있다.
-Spanning Tree는 특수한 형태이므로 모든 정점들이 연결 되어있어야 하고 사이클을 포함해서는 안된다.

