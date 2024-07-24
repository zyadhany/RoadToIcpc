// Dp to find the longest increasing subsequence in (n^2)


ll n;
vi v, dp;
ll rec(ll i)
{
    if (i==n) // The end
    {
        return 0;
    }
    ll &ans = dp[i]; // to not need to change its value at the end
    /*
        // same example but I will reach the point with diffierent val
        ll &ans = dp[i][w]; // it will be 2d vector
    */
    if (ans != -1) // if it already calculated and I Reached it before
    {
        return ans;
    }
    for (ll j = i+1; j <= n; ++j) {
        if (v[j]>v[i])
            ans = max(ans, rec(j)+1); // try the point i with all values bigger than it
    }
    return ans;
}

void solve(ll test) {

    cin>>n;
    dp = vi(n+5, -1);
    v = vi(n+5);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    v[n] = 1e5;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, rec(i)); // test to start from any point
    }
    cout<<ans;
}




// longest common subsequence

vii dp;
string s, ss;
ll rec(ll i, ll j)
{
    if (i==s.size() || j==ss.size())
    {
        return 0;
    }
    ll &ans = dp[i][j];
    if (ans != -1)  // if it already calculated and I Reached it before
    {
        return ans;
    }
    if (s[i]==ss[j])  // if the two characters are the same
    {
        ans = rec(i+1, j+1)+1;
    }
    else
    {
        ans = max(rec(i+1, j), rec(i, j+1));  // try to skip one of them
    }
    
    return ans;
}

void solve(ll test) {

    cin>>s>>ss;
    dp = vector<vi>(1001, vi(1001, -1));
    cout<<rec(0,0)<<ln;

}





// if I have 5 numbers and I want cnt ways to get the sum x

ll x;
vii dp;
vi v = {1, 5, 10, 25, 50}; // the numbers
ll rec(ll i, ll n)
{
    if (n==0)  // if I reached the sum
    {
        return 1;
    }
    if (i==5)  // if I reached the end of the numbers
    {
        return 0;
    }
    ll &ans = dp[i][n]; // if I reached this point before
    if (ans != -1)
    {
        return ans;
    }
    ans = rec(i+1, n);  // try to skip the number
    if (n >= v[i])  // if the number is less than the sum
    {
        ans += rec(i, n-v[i]);  
    }
    return ans;
}

void solve(ll test) {
    dp = vii(5, vi(8000, -1)); // outside the loop to not do it every time
    while(cin>>x)
    {
        cout<<rec(0, x)<<"\n";  // start from the first number
    }
}



