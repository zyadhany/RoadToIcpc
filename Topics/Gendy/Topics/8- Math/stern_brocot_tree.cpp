/*
The tree
starts with 0/1 and 1/0 and will keep
go right and left and the new value
be the sum of the up and down part or r and l
example:
         1/1
      /       \
   1/2        2/1
  /   \      /   \
1/3   2/3  3/2   3/1
*/
int com(ll l1, ll l2, ll r1, ll r2)
{
    // make them for same denominator
    l1 *= r2;
    r1 *= l2;
    // compare
    if (l1 < r1)
        return -1;
    return l1 > r1;
}

void solve(ll test)
{

    ll n, m;
    cin >> n >> m; // 1 3
    string ans = "";
    ll l1 = 0, l2 = 1, r1 = 1, r2 = 0;
    while (true)
    {
        ll m1 = l1 + r1, m2 = l2 + r2;
        // Compare the end to the new value
        ll is = com(n, m, m1, m2);
        // Reached it
        if (is == 0)
            break;
        // Go left if smaller and else right
        if (is == -1)
            r1 = m1, r2 = m2, ans += 'L';
        else
            l1 = m1, l2 = m2, ans += 'R';
    }
    cout << ans << "\n";  // the answer is LL
}