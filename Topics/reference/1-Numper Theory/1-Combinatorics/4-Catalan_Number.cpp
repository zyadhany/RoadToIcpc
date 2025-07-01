// number of possibilities of various combinations.

/*
* Number of correct bracket sequences consisting of **n** opening and **n** closing brackets.
* The number of rooted full binary trees with **n + 1** leaves (vertices are not numbered). A rooted binary tree is full if every vertex has either two children or no children.
* The number of ways to completely parenthesize **n + 1** factors.
* The number of triangulations of a convex polygon with **n + 2** sides (i.e., the number of partitions of polygon into disjoint triangles by using the diagonals).
* The number of ways to connect the **2n** points on a circle to form **n** disjoint chords.
* The number of **non-isomorphic** full binary trees with **n** internal nodes (i.e., nodes having at least one son).
* The number of monotonic lattice paths from point **(0, 0)** to point **(n, n)** in a square lattice of size **n × n**, which do not pass above the main diagonal (i.e., connecting **(0, 0)** to **(n, n)**).
* Number of permutations of length **n** that can be **stack sorted** (i.e., it can be shown that the rearrangement is stack sorted if and only if there is no such index **i < j < k**, such that **a\_k < a\_i < a\_j**).
* The number of **non-crossing partitions** of a set of **n** elements.
* The number of ways to cover the ladder **1...n** using **n** rectangles (The ladder consists of **n** columns, where the *i-th* column has a height **i**).
*/

// C[0] = C[1] = 1;
// 1, 1, 2, 5, 14, 42, 132, 429, 1430, .....

/**
 * dp solution return array catalon numbers.
 * C(n) = summtion(C(i) * C(n - i - 1)).
 * Time O(n * n).
 * Space O(n).
*/

vi catalanDP(int n)
{
    vi C(n + 1, 0);
    C[0] = C[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++)
            C[i] += C[j] * C[i - j - 1];
    return (C);
}

/**
 * C(n) = (C(n - 1) * (4 * n - 2)) / (n + 1).
 * Time O(n).
 * Space O(n).
*/
vi catalanDP(int n)
{
    vi C(n + 1, 0);
    C[0] = C[1] = 1;
    for (int i = 2; i <= n; i++)
        C[i] += (C[i - 1] * (4 * i - 2)) / (i + 1);
    return (C);
}

// C(n) = nCr(2 * n, n) / (n + 1)
ll catalan(int n)
{
    return nCr(2 * n, n) / (n + 1);
}

// C(n) = (2n)! / ((n + 1)! * n!) 
ll catalan(int n)
{
    ll res = fac[2 * n];
    res *= (facinv[n+1] * facinv[n]) % MODE;
    return (res) % MODE;
}

/**
 * if we have k partition and out solution:>
 * ((A)B)C. |A|+|B|+|C| = n.
 * sol is all possible values of C(A)*C(B)*C(C).
 * C(n, k) = ((k + 1) * nCr(2 * n + k, n)) / (n + k + 1).
*/
ll catalanKparts(int n, ll k)
{
    ll res = ((k + 1) * nCr(2 * n + k, n)) % MODE;
    res *= modeenv(n + 1 + k);
    return (res) % MODE;
}

/**
 * using recurance relation with dp
 * C(n,k) = (C(n-1,k)*(2*n+k-1)*(2*n+k))/(n*(n+k+1)).
*/
vi catalanKpartsDp(int n, ll k)
{
    vi C(n + 1, 0);
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i] = C[i - 1];
        C[i] *= ((2 * i + k - 1) * (2 * i + k)) % MODE;
        C[i] %= MODE;
        C[i] *= modeenv((i * (i + k + 1)) % MODE);
        C[i] %= MODE;
    }
    return (C);
}
