# Greedy Algorithm

## Greedy Algorithm의 개념

### Greedy Algorithm란

- 탐욕 알고리즘, 욕심쟁이 알고리즘 여러가지로 불린다.
- 매 선택에서 미래를 생각하지 않고 지금 이 순간 당장 최적인 답을 선택하여 결과를 도출하는 알고리즘이다.
- Greedy Algorithm은 **100\% 최적해를 보장해주지 않는다**  
  -ex) 매순간 최적을 따라가면 1-1-1-100의 거리로 가지만 중간 1-1-10-10으로 움직이는 것이 더 효율적일때

### Greedy Algorithm이 잘 작동하는 경우

1. greedy choice property  
   -앞의 선택이 이후의 선택에 영향을 주지 않는다는 것
1. optimal substructure  
   -문제에 대한 최적해가 부분문제에 대해서도 역시 최적해라는 것

### Greedy Algorithm이 사용되는 예시

- 거스름돈 문제
- 최소 신장 트리
- 제약조건이 많은 대부분의 문제
- 다익스트라 알고리즘  
  -[백준 동전 0](https://www.acmicpc.net/problem/11047)

### Greedy Algorithm이 실패하는 예시

- 외판원 순회 문제  
  -[백준 외판원 순회](https://www.acmicpc.net/problem/2098)
