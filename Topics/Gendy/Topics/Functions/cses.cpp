// cnt sub arrays have sum % k = 0

ll cntSubarrayWithSumModK(vi v,ll k)
{
    ll sum = 0, a = 0;
    mi m;
    m[0]++;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
        ll rem = (sum%k + k) % k;
        a += m[rem];
        m[rem]++;
    }
    return a;
}


/* 
عناصر عددهم (k)
مجموعهم (n)
*/
ll n,k ; cin >> n >> k;
ll x=(n-(k*(k-1)/2));
if(x%k==0){
    cout<<x/k<<" "<<(x/k)+k-1<<endl;
    return;
}
cout << -1 <<endl;


// the number of subarrays having sum x all positive
ll n,x;cin>>n>>x;
    vi v(n);
    cin(v);
    ll end = 0, st = 0, sum = 0;
    ll cnt = 0;
    while(end<n)
    {
        if (sum + v[end] <= x)
        {
            sum += v[end];
            end++;
        }
        if (sum == x)
        {
            cnt++;
        }
        while(sum + v[end] > x)
        {
            sum-=v[st];
            sum = max(0LL, sum);
            st++;
            end = max(st, end);
        }
    }
    cout<<cnt;


// the number of subarrays having sum x with negatives
ll n,x;cin>>n>>x;
    vi v(n);
    cin(v);
    mi m;
    ll pr = 0, cnt = 0;
    m[0] = 1;
    for (int i = 0; i < n; ++i) {
        pr += v[i];
        cnt += m[pr - x];
        m[pr]++;
    }
    cout<<cnt;


/*
The number of times there is Subarray with sum equal to target
in all ranges l, r
Tested with target = 0 only
*/
    string s;
    cin >> s;
    ll target = 0;
    // cin >> target;

    ll n = s.size();
    vi v;
    v.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
            v.push_back(-1);
        else
            v.push_back(1);
    }

    pre(v);

    mi m;
    ll cnt = 0;

    for (int i = 0; i <= n; ++i)
    {
        ll required_sum = v[i] - target;
        cnt = (cnt + (n - i + 1) * m[required_sum]) % MOD;
        m[v[i]] = (m[v[i]] + (i + 1)) % MOD;
    }
    cout << cnt << "\n";





    // the number of subarrays where the sum of values is divisible by n
    // with negatives
    ll n;
    cin >> n;
    vi v(n);
    cin(v);
    mi m;
    ll rem = 0, cnt = 0;
    m[0] = 1;
    for (int i = 0; i < n; ++i) {
        rem = (v[i]%n + rem%n + n)%n;
        cnt += m[rem];
        m[rem]++;
    }
    cout<<cnt;


// the number of subarrays that have at most k distinct values
    ll n,x;cin>>n>>x;
    vi v(n);
    cin(v);
    ll end = 0, st = 0;
    ll cnt = 0;
    mi m;
    ll dis = 0;
    while(end<n)
    {
        m[v[end]]++;
        if (m[v[end]] == 1)
            dis++;
 
        while(dis > x)
        {
            m[v[st]]--;
            if (m[v[st]] == 0)
                dis--;
            st++;
        }
        cnt += end - st + 1;
        end++;
    }
    cout<<cnt;


// calculate the median of each window of k elements, from left to right
    ll n,k;cin>>n>>k;
    ordered_set os;
    vi v(n);
    cin(v);
    for (int i = 0; i < k-1; ++i) {
        os.insert({v[i], i});
    }
    ll st = 0;
    for (int i = k-1; i < n; ++i) {
        os.insert({v[i], i});
        auto is = os.find_by_order(k/2-(k%2==0));
        cout<<(*is).F<<' ';
        os.erase({v[st], st});
        st++;
    }


// the maximum sum of values in a contiguous subarray with length between a and b
// with negatives

void MaximumSubarraySumII(int N, int A, int B,
                        vector<ll>& arr)
{
    // Initialize a deque to store indices in increasing
    // order of prefix sum values
    deque<ll> dq;

    // Initialize a prefixSum array to store cumulative sums
    vector<ll> prefixSum(N + 1);

    // Initialize the answer to track the maximum sum
    ll ans = LLONG_MIN;

    // Calculate cumulative sums
    for (int i = 1; i <= N; i++) {
        prefixSum[i] += prefixSum[i - 1] + arr[i - 1];
    }

    // Loop through the first (B-1) indices to initialize
    // deque
    for (int i = 1; i < B; i++) {
        // Maintain deque in increasing order of prefix sum
        // values
        while (!dq.empty()
            && prefixSum[dq.front()] <= prefixSum[i]) {
            dq.pop_front();
        }
        dq.push_front(i);
    }

    // Loop through each starting index i from 0 to (n-a)
    for (int i = 0; i <= (N - A); i++) {

        // Maintain deque in increasing order of prefix sum
        // values
        while (i + B <= N && !dq.empty()
            && prefixSum[dq.front()]
                    <= prefixSum[i + B]) {
            dq.pop_front();
        }

        // Push the right end index to the front of deque
        if (i + B <= N)
            dq.push_front(i + B);

        // If the index of maximum element outside the
        // current window , pop elements from the back of
        // the deque until the back index(index of maximum
        // element) is within the current window.

        while (!dq.empty() && dq.back() < (A + i)) {
            dq.pop_back();
        }

        // Update the answer by taking the maximum of the
        // current answer and the difference between the
        // prefix sum at the back(maximum element) of the
        // deque and the prefix sum at index i
    
        ans = max(ans, prefixSum[dq.back()] - prefixSum[i]);
    }

    cout << ans << "\n";
}
