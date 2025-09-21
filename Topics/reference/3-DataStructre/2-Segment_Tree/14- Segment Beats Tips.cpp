Segment Tree Beats – Quick Ops Reference
========================================

- max(a[i], x)   // range chmax
  store: min1, min2, cntMin
  tag condition: if (x <= min1) do nothing
  break condition: if (x < min2) go deeper (push down)
  apply: if (min1 < x < min2) => increase min1 to x and fix sum using cntMin

- min(a[i], x)   // range chmin
  store: max1, max2, cntMax
  tag condition: if (x >= max1) do nothing
  break condition: if (x > max2) go deeper (push down)
  apply: if (max2 < x < max1) => decrease max1 to x and fix sum using cntMax

- += x           // range add
  store: min1, min2, max1, max2, sum
  apply: add x to min1, min2, max1, max2, sum
  tag condition: always works (lazy tag)

- %= x
    store: min, max, cnt, sum
    tag condition: max == min
    break: max < x
    apply: mx = mn = mx % x, sum = cnt * mx

- gcd update (add x to range)
  store: first element + diff array idea
  note: gcd([a1, a2, ..., an]) = gcd(a1, (a2-a1), (a3-a2), ...)
  so usually store {first value, gcd of differences}

- /=, and range add:
    when mx/x - mx == mn/x - mn : tag condition
    then: pushsumm(mx/x - mx)

- &,| =x
    store |, & for subtree
    if (or ^ and) & x ==0 : tag condtion (~x if and oppration)
