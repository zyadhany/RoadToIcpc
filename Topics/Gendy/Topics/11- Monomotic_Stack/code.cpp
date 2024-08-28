    ll n;cin>>n;
    vi v(n);cin(v);
    vi ans(n,-1);
    stack<pair<ll,ll>>st;
    for (int i = 0; i < n; ++i) {
        if (st.empty())
            st.emplace(v[i],i);
        else if (v[i]>st.top().F)
        {
            while(!st.empty()&&v[i]>st.top().F)
            {
                ans[st.top().S]=i+1;
                st.pop();
            }
            st.emplace(v[i],i);
        }
        else
            st.emplace(v[i],i);
    }
    ll q;cin>>q;
    while(q--)
    {
        ll a;cin>>a;
        cout<<ans[a-1]<<"\n";
    }