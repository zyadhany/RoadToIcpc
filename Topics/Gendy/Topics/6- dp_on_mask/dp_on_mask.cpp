// We use mask as it is easy to check if a number is visited or not
// mask is a number have the visited as bit equal to 1 ->  visited index 2^1 + 2^2 + 2^3 -> 1, 2, 3 are visited

const int N = 15;
ll n;
vi dp(1<<N, -1);

ll rec(ll mask)
{
    if (__builtin_popcount(mask) == n) // all the nodes are visited
        return 0;
    ll &ans = dp[mask];
    if (ans != -1)
        return ans;

    ans = INT64_MAX;
    for (int i = 1; i <= n; ++i) {
        if (!((1<<i) & mask))
        {
            ans = min(ans, rec(mask + (1<<i))); // mark i is visited
        }
    }
    return ans;
}





void solve(ll test) {


    dp = vi(1<<N); // 2^N
    ll is = rec(1); // 0 is the starting point 2^0 -> 1
    cout<<is<<"\n";

}











// count ways to reach value


const int N = 17;
ll n;
vii dp;
vii ways;
vi v;
ll rec(ll idx, ll mask, ll cnt)
{
    if (__builtin_popcount(mask) == n+1) // all the nodes are visited
    {
        return v[idx];
    }
    ll &ans = dp[idx][mask];
    if (ans != -1)
    {
        return ans;
    }

    ans = 0;
    for (ll i = 1; i <= n; ++i) {
        if (!((1<<i) & mask))
        {
            ll next = rec(i, mask + (1<<i), cnt + abs(v[i]-v[idx])) + abs(v[i]-v[idx]); // mark i is visited
            if (next > ans)
            {
                ans = next;
                ways[idx][mask] = ways[i][mask + (1<<i)];
            }
            else if (next == ans)
            {
                ways[idx][mask] += ways[i][mask + (1<<i)];
            }
        }
    }
    return ans;
}

void solve(ll test) {

    dp = vii(16, vi(1<<N, -1)); // 2^N
    ways = vii(16, vi(1<<N, 1)); // 2^N;
    v = vi(n+1);
    v[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin>>v[i];
    }
    v.push_back(0);
    ll is = rec(0, 1, 0); // 0 is the starting point 2^0 -> 1
    cout<<is+(2*n)<<' '<<ways[0][1]<<"\n";
}









// find path to reah value
double rec(ll idx, ll mask)
{
    for (ll i = 1; i <= n; ++i) {
        if (!((1<<i) & mask))
        {
            double nx = rec(i, mask + (1<<i)) + dis(idx, i);
            if (nx < ans) // Add this to store the parents
            {
                ans = nx;
                par[idx][mask] = i;
            }
        }
    }
    return ans;
}


void printPath(ll idx, ll mask)
{
    if (__builtin_popcount(mask) == n + 1) // all the nodes are visited
    {
        return;
    }
    ll nextNode = par[idx][mask];
    cout << nextNode << " ";
    printPath(nextNode, mask + (1 << nextNode));
}


void solve(ll test) {

    ld is = rec(0, 1);
    cout<<fixed(2)<<is<<"\n";
    // Print path
    cout << "Path: ";
    printPath(0, 1);
    cout << "\n";
}