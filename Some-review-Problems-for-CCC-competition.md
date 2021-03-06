## TODO List
- [ ] [**COCI '21 Contest 4 #2 Autobus**](https://dmoj.ca/problem/coci21c4p2)
- [ ] [**CCC '11 S5 - Switch**](https://dmoj.ca/problem/ccc11s5)
- [ ] [**Fortune Telling**](https://codeforces.com/contest/1634/problem/B)





# Review problems for CCC contest

## Graph Algorithms

### Shortest Path

#### Dijkstra
==Time Complexity== $O(E + V\log V)$ 

- [x] [**Shortest Routes I**](https://cses.fi/problemset/task/1671) [code](C:\WSM\CodeSpaceWSM\CP-problems\CCC\Review for 2022 CCC Senior\Shortest Routes I\SR1_Dijkstra.cpp)
- [ ] [**Flight Discount**](https://cses.fi/problemset/task/1195)
- [ ] [**Investigation**](https://cses.fi/problemset/task/1202)

#### Bellman-Ford
==Time Complexity== $O(VE)$

- [x] [**Shortest Routes I**](https://cses.fi/problemset/task/1671) [code](C:\WSM\CodeSpaceWSM\CP-problems\CCC\Review for 2022 CCC Senior\Shortest Routes I\SR1_BellmanFord.cpp) (can't pass some cases, cause the the it is $O(nm)$)
- [ ] [**High Score**](https://cses.fi/problemset/task/1673)

#### Floyd-Warshall
==Time Complexity== $O(V^3)$

- [x] [**Shortest Routes II**](https://cses.fi/problemset/task/1672) [code](C:\WSM\CodeSpaceWSM\CP-problems\CCC\Review for 2022 CCC Senior\Shortest Routes II\SR2.cpp)

### Color Nodes

- [x] [**Building Teams**](https://cses.fi/problemset/task/1668) [code](C:\WSM\CodeSpaceWSM\CP-problems\CCC\Review for 2022 CCC Senior\Building Teams\BT.cpp) For this problem, you can use a trick that is **1^-1 = -2** and **-2^-1 = 1**

### Find Cycles

We usually use Bellman-Ford algorithm to solve cycle finding problems
So the time complexity is like so $O(VE)$

- [ ] [**Round Trip**](https://cses.fi/problemset/task/1669)
- [ ] [**Cycle Find**](https://cses.fi/problemset/task/1197)

### Topo Sort on graph

- [ ] [**Longest Flight Route**](https://cses.fi/problemset/task/1680/)


### DSU


### MST


### SCC


## Tree Algorithms

### Subordinates



### Diameter




## DP

### unsorted

- [ ] [**CCC '18 S4 - Balanced Trees**](https://dmoj.ca/problem/ccc18s4)

### Backpack DP

#### 0-1 backpack

#### Complete backpack

### Range DP


## Binary Search
[oi-wiki binary search](https://oi-wiki.org/basic/binary/#_1)

## Prefix

### Prefix sum

### Minimum/maximum prefix

## Math

### Prime test

### Counting Divisors

- [ ] [**Counting Divisors**](https://cses.fi/problemset/task/1081)
### Prime factorization

- [ ] [**CCC '13 S5 - Factor Solitaire**](https://dmoj.ca/problem/ccc13s5) [code](C:\WSM\CodeSpaceWSM\CP-problems\CCC\CCC 13\CCC 13 S5 - Factor Solitaire\FactorSolitaire.cpp)

  It's hard to calculate from 1 to N, but its way easier to calculate from N to 1.

### GCD

- [ ] [**Common Divisors**](https://cses.fi/problemset/task/1081)

### LCM