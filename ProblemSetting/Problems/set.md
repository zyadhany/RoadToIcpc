
- https://codeforces.com/contest/1451/problem/D
  make it another shape and calculate all posibble moves to win.

- https://codeforces.com/contest/1451/problem/E1
    you have array permution of n elements but you forget it, you have n - 1 value the a_i ^ a_(i+1) try to find array that construct it.

- https://codeforces.com/contest/1926/problem/C
    given l, r find summtion of range from l to r.

- altnating string "0101010101"
  - queries l, r swap digits determin if it's ertnating or no.
  - find longest beuuful altnating in range.develop

- https://codeforces.com/contest/1926/problem/D
  - no ones in same place.

- https://codeforces.com/contest/733/problem/C
  - let n = 1e5
  - make checker with Sg

- https://codeforces.com/contest/1946/problem/D
  - let it's xor be less than or equal x
  - min num of opp to make Xor <= x, opp th choice any index and divide it by 2^m: 1<=m<=30;
  - max k you can get after performe at most k opp

- Given array, how many element in range that is divisable by one of it's element.

- Gcd Extended: xa + yb = n, how many valid postive value of x, y.

- equation x^2 + y^2 + c = n;

- given array of n, k, q queries| each query has 2 opp: 1 l x, replace X[l] = x, 2 l  say how many number from 1 to k is't divided by any number in that range.
- make it compeny with probbalities and money with employee come in and out.

- https://codeforces.com/group/aN1Hg8Z9V6/contest/512441/problem/H
 array of n element and q queries
 1 l x, make arr[l] = x
 2 k, say how many elements in array gcd(k, arr[i]) == 1, say how beauty array is for k.

- https://codeforces.com/problemset/problem/877/B
  sprate them into k parts not just 3.

-   https://codeforces.com/group/u3Ii79X3NY/contest/270796/problem/E 
  - make it all the possible solution, dp()

- you have array and q queries
  1.  given index say first element is greater than him.
  2.  gieven index change it's value to k.5

- you have array, and have k opration
  - what is mx beutful you can get after uing at most k opration
  - beutful of array is for every i find first j such i X[i] < X[j] add j - i.

- bird-tree-hard (polygon)

- given array of n and q queries l, r
  - for each query find medin of that range.

- max Trapping Rain Water after doing k oppration
  - each oppratoion is to dig one block down.
  - https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

- given graph find how many bipartite in it.

- 2d array with '.' and '#':
  '#' is door you can come out from,
  you need to finded shortestpath from anydoor to X[l][r] then back to different door. ttt

- you are playing game with n stage (topologicalOrder with priorty qeue)
  - each stage have requered a[i] point, and score bounce of b[i].
    - to be able to enter stage i you mush have at least a[i] points.
    - and when you end it you earn b[i] points.
  - got m roles each role have l, r
    - that to open stage r you need to end stage l first.
  - you can use magic cure to increase your points by one.

  - ouput minumum number of magical cure you need to use to end game
  - then n represent any valid order of stage you enter.