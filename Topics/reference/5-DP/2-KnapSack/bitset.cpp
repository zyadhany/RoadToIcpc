// we can use bitset to optimize knapsack with time O(n*k / w)
// it only tell us if we can make sum k or not not compute count (1/0)



/*
- if we have k elements and summ of all of them does not exceed n.
we can optimize it to O(n*sqrt(n) / w) -> very good it's like O(n log(n))

for each value w we will mantain it's count of elements c_w.
represent it as summ of powers of 2 > c_w = 2^0 + 2^1 + ... + 2^p + r
where p is the max power of 2 that is <= c_w and r is the remainder

then now we have at most log(c_w) + 1 elements of value w.
{2^0 * w, 2^1 * w, 2^2 * w, ..., 2^p * w, r * w}
we can add then in bitset with regular way: dp |= (dp << value);
*/
for (int i = 1; i <= n; i++)
{
    if (!frq[i]) continue;
    ll c = frq[i];
    for (int j = 1; j <= mxn; j<<=1)
    {
        if (c >= j) {
            dp |= (dp << (j * i));
            c-=j;
        }
    }
    if (c) dp |= (dp << (c * i));
}