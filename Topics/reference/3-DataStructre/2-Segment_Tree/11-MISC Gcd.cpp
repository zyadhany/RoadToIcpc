/*
Gcd, Range query, range increasement
gcd(l, ... r) = gcd(a_l, a_l+1, ..., a_r)
= gcd(a_l, a_l+1 - a_l, ..., a_r - a_r-1)

Store two segment trees: one for adding some number to range and taking value of element (usual segment tree with lazy propagation) and one based on differences of adjacent elements. When you add a number to the range, only two values in second segment tree change, so you can easily recalculate values in second tree.

*/

SegmentTree sg;
SegmentTree diff;
sg.build(arr);
diff.build(D); // Differnce array value

// increase range [l, r] by x
sg.set(l, r, x);
diff.set(l, x);
diff.set(r+1, -x);

// find gcd in range [l, r]
g = sg.getrange(l, l);
if (l < r) g = gcd(g, diff.getrange(l+1, r));