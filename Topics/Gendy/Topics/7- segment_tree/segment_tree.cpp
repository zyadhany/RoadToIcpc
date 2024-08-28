// my segment


typedef ll item;
/*struct item{
    ll sum, ma;
};*/
struct segment {
    ll sz;
    vector<item> sums;

    item neural = 0; // change
    void init(ll n)
    {
        sz = 1;
        while(sz < n)
        {
            sz *= 2;
        }
        sums.assign(2*sz, neural);
    }

    item merge(item a, item b)
    {
        return (a^b);
    }

    item single(ll v)
    {
        return v;
    }
    void build(vi &a, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1){
            if (lx < a.size())
            {
                sums[x] = single(a[lx]);
            }
            return;
        }
        ll mid = (lx + rx)/2;
        build(a, 2*x+1, lx, mid);
        build(a, 2*x+2, mid, rx);
        sums[x] = merge(sums[2*x+1] , sums[2*x+2]);
    }

    void build(vi &a)
    {
        build(a, 0, 0, sz);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx-lx == 1)
        {
            sums[x] = single(v);
            return;
        }
        ll mid = (lx+rx) / 2;
        if (i < mid)
        {
            set(i, v, 2*x+1, lx, mid);
        }
        else
        {
            set(i, v, 2*x+2, mid, rx);
        }
        sums[x] = merge(sums[2*x+1] , sums[2*x+2]);
    }

    void set(ll i, ll v)
    {
        set(i, v, 0, 0, sz);
    }


    item sum(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >=r || l >= rx)
            return neural;

        if (lx >= l && rx <= r)
            return sums[x];

        ll mid = (lx + rx)/2;
        item s1 = sum(l, r, 2*x+1, lx, mid);
        item s2 = sum(l, r, 2*x+2, mid, rx);
        return merge(s1 , s2);

    }
    item sum(ll l, ll r)
    {
        return sum(l, r, 0, 0, sz);
    }

    /*void add(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx-lx == 1)
        {
            sums[x] += single(v);
            return;
        }
        ll mid = (lx+rx) / 2;
        if (i < mid)
        {
            add(i, v, 2*x+1, lx, mid);
        }
        else
        {
            add(i, v, 2*x+2, mid, rx);
        }
        sums[x] = merge(sums[2*x+1] , sums[2*x+2]);
    }

    void add(ll i, ll v)
    {
        add(i, v, 0, 0, sz);
    }

    ll find(ll k, ll idx, ll x, ll lx, ll rx){

        if (sums[x]<k || rx <= idx)
            return -1;
        if (rx-lx == 1)
            return lx;
        ll mid = (lx+rx)/2;
        ll res = find(k, idx,2*x+1, lx, mid);
        if (res == -1) {
            res = find(k, idx, 2*x+2, mid, rx);;
        }
        return res;
    }

    ll find(ll k, ll idx){
        return find(k, idx,0, 0, sz);
    }


    ll find(ll k, ll x, ll lx, ll rx){
        if (rx-lx == 1)
            return lx;

        ll mid = (lx+rx)/2;
        ll sr = sums[2*x+2];
        if (k < sr) {
            return find(k, 2*x+2, mid, rx);
        }
        else {
            return find(k-sr, 2*x+1, lx, mid);
        }

    }

    ll find(ll k){
        return find(k, 0, 0, sz);
    }*/


};


void solve(ll test) {

    ll n,m;cin>>n>>m;
    segment st;
    vi a(n);
    st.init(n);
    cin(a);
    st.build(a);
    for (int i = 0; i < m; ++i) {
        ll op;cin>>op;
        if (op==1)
        {
            ll l,r;cin>>l>>r;
            st.set(l-1, r);
        }
        else
        {
            ll l,r;cin>>l>>r;
            cout<<st.sum(l-1, r)<<"\n";
        }
    }



}























































ll N = 2e5+5;
vi a(N), seg(N<<2);

void build(ll node, ll s, ll e)
{
    if (s==e)
    {
        seg[node] = a[s];
        return;
    }
    ll mid = (s+e)>>1;
    build(node<<1, s, mid);
    build(node<<1 | 1, mid+1, e); //(node<<1) | 1 == node<<1 + 1
    seg[node] = seg[node<<1] + seg[node<<1 | 1];
}

void update(ll node, ll s, ll e, ll i, ll val)
{
    if (s==e)
    {
        seg[node] = val;
        return;
    }
    ll mid = (s+e)>>1;
    if (i <= mid)
        update(node<<1, s, mid, i, val);
    else
        update(node<<1|1, mid+1, e, i, val);
    seg[node] = seg[node<<1] + seg[node<<1 | 1];
}

ll query(ll node, ll s, ll e, ll l, ll r)
{
    if (s > r || e < l)
    {
        return 0; // value not make problem
    }
    if (l <= s && e <= r)
    {
        return seg[node];
    }
    ll mid = (s+e)>>1;
    return query(node<<1, s, mid, l, r) + query(node<<1 | 1, mid+1, e, l, r); // result
}


    build(1, 1, n);
    string s;
    while(cin>>s && s != "END")
    {
        ll x,y;cin>>x>>y;
        if (s == "S")
            update(1, 1, n, x, y);
        else
            cout<<query(1, 1, n, x, y)<<"\n";
    }




// get number of characters in range


string str;
ll n;
ll N = 2e5+5;
vi a(N);
vii seg(N<<2, vi(26));

void build(ll node, ll s, ll e)
{
    if (s==e)
    {
        seg[node][str[s]-'a'] = 1;
        return;
    }
    ll mid = (s+e)>>1;
    build(node<<1, s, mid);
    build(node<<1 | 1, mid+1, e); //(node<<1) | 1 == node<<1 + 1
    for (int i = 0; i < 26; ++i) {
        seg[node][i] = seg[node<<1][i] + seg[node<<1 | 1][i];
    }

}

void update(ll node, ll s, ll e, ll i, char val)
{
    if (s==e)
    {
        seg[node][str[s]-'a']--;
        str[s] = val;
        seg[node][str[s]-'a']++;
        return;
    }
    ll mid = (s+e)>>1;
    if (i <= mid)
        update(node<<1, s, mid, i, val);
    else
        update(node<<1|1, mid+1, e, i, val);
    for (int j = 0; j < 26; ++j) {
        seg[node][j] = seg[node<<1][j] + seg[node<<1 | 1][j];
    }
}
vi res(26);
void query(ll node, ll s, ll e, ll l, ll r)
{
    if (s > r || e < l)
    {
        return; // value not make problem
    }
    if (l <= s && e <= r)
    {
        for (int i = 0; i < 26; ++i) {
            res[i] += seg[node][i];
        }
        return;
    }
    ll mid = (s+e)>>1;
    query(node<<1, s, mid, l, r);
    query(node<<1 | 1, mid+1, e, l, r); // result
}


void solve(ll test) {

    cin>>str;
    n = str.size();
    build(1, 0, n-1);
    ll q;cin>>q;
    while(q--)
    {
        ll x;cin>>x;
        if (x==1)
        {
            ll aa;
            char c;
            cin>>aa>>c;
            update(1, 0, n-1, aa-1, c);
        }
        else
        {
            ll aa,b;cin>>aa>>b;
            res = vi(26, 0);
            query(1, 0, n-1, aa-1, b-1);
            ll cnt = 0;
            for (int i = 0; i < 26; ++i) {
                if (res[i])
                    cnt++;
            }
            cout<<cnt<<"\n";
        }
    }

}











// segment tree from edu

struct segment {
    ll sz;
    vi sums;
    void init(ll n)
    {
        sz = 1;
        while(sz < n)
        {
            sz *= 2;
        }
        sums.assign(2*sz, 0ll);
    }

    void build(vi &a, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1){
            if (lx < a.size())
            {
                sums[x] = a[lx];
            }
            return;
        }
        ll mid = (lx + rx)/2;
        build(a, 2*x+1, lx, mid);
        build(a, 2*x+2, mid, rx);
        sums[x] = sums[2*x+1] + sums[2*x+2]; // change
    }

    void build(vi &a)
    {
        build(a, 0, 0, sz);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx-lx == 1)
        {
            sums[x] = v;
            return;
        }
        ll mid = (lx+rx) / 2;
        if (i < mid)
        {
            set(i, v, 2*x+1, lx, mid);
        }
        else
        {
            set(i, v, 2*x+2, mid, rx);
        }
        sums[x] = sums[2*x+1] + sums[2*x+2]; // change
    }

    void set(ll i, ll v)
    {
        set(i, v, 0, 0, sz);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >=r || l >= rx)
            return 0; // change

        if (lx >= l && rx <= r)
            return sums[x];

        ll mid = (lx + rx)/2;
        ll s1 = sum(l, r, 2*x+1, lx, mid);
        ll s2 = sum(l, r, 2*x+2, mid, rx);
        return s1 + s2; // change

    }
    ll sum(ll l, ll r)
    {
        return sum(l, r, 0, 0, sz);
    }


};


void solve(ll test) {

    ll n;cin>>n;
    segment st;
    st.init(n);
    st.build(a); // build the segment in linear time

    ll i,v;cin>>i>>v;
    st.set(i, v); // set element in idx i to v

    ll l, r;cin>>l>>r;
    cout<<st.sum(l, r)<<"\n";  // get sum renge from l to r
            
        
}




// add item to can change in it as cnt or another things

struct item{
    ll m, c;
};

struct segment {
    ll sz;
    vector<item> sums;
    item neutral = {INT64_MAX, 0};  // change  // empty value
    void init(ll n)
    {
        sz = 1;
        while(sz < n)
        {
            sz *= 2;
        }
        sums.assign(2*sz, neutral);
    }

    item merge(item a, item b)  // how to merge  // change
    {
        if (a.m < b.m)
            return a;
        if (b.m<a.m)
            return b;
        return {a.m, a.c + b.c};
    }

    item single(ll v)
    {
        return {v, 1};
    }
    void build(vi &a, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1){
            if (lx < a.size())
            {
                sums[x] = single(a[lx]);
            }
            return;
        }
        ll mid = (lx + rx)/2;
        build(a, 2*x+1, lx, mid);
        build(a, 2*x+2, mid, rx);
        sums[x] = merge(sums[2*x+1] , sums[2*x+2]);
    }

    void build(vi &a)
    {
        build(a, 0, 0, sz);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx-lx == 1)
        {
            sums[x] = single(v);
            return;
        }
        ll mid = (lx+rx) / 2;
        if (i < mid)
        {
            set(i, v, 2*x+1, lx, mid);
        }
        else
        {
            set(i, v, 2*x+2, mid, rx);
        }
        sums[x] = merge(sums[2*x+1] , sums[2*x+2]);
    }

    void set(ll i, ll v)
    {
        set(i, v, 0, 0, sz);
    }

    item sum(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >=r || l >= rx)
            return neutral;

        if (lx >= l && rx <= r)
            return sums[x];

        ll mid = (lx + rx)/2;
        item s1 = sum(l, r, 2*x+1, lx, mid);
        item s2 = sum(l, r, 2*x+2, mid, rx);
        return merge(s1 , s2);

    }
    item sum(ll l, ll r)
    {
        return sum(l, r, 0, 0, sz);
    }


};



void solve(ll test) {

    ll n,m;cin>>n>>m;
    segment st;
    st.init(n);
    vi a(n);
    cin(a);
    st.build(a);
    for (int j = 0; j < m; ++j) {
        ll op;cin>>op;
        if (op == 1)
        {
            ll i,v;cin>>i>>v;
            st.set(i, v);
        }
        else
        {
            ll l, r;cin>>l>>r;
            cout<<st.sum(l, r).m <<' '<<st.sum(l, r).c<<"\n";
        }
    }

}









// if we need the max segment the changes will be like that

struct item{
    ll seg,pref,suf,sum;  // we use pref and suf to handle all cases of segment    //----
                                                                                   //---  the first 3 elements will be 2 from first 1 from second
};

struct segment {
    ll sz;
    vector<item> sums;

    item neural = {0, 0, 0, 0}; // change as the empty value is 0
    void init(ll n)
    {
        sz = 1;
        while(sz < n)
        {
            sz *= 2;
        }
        sums.assign(2*sz, neural);
    }

    item merge(item a, item b)
    {
        return {
            max({a.seg, b.seg, a.suf+b.pref}),  // the max segment
            max(a.pref, a.sum+b.pref),  // the max prefix
            max(b.suf, b.sum+a.suf),  // the max suffix
            a.sum+b.sum  // the sum of the segment
        };
    }

    item single(ll v)
    {
        if (v>0)
            return {v, v, v, v};  // if the value is positive keep it
        else
            return {0ll, 0ll, 0ll, v};  // if the value is negative make it empty
    }

}











// adding find to look for element idx

typedef ll item;
/*struct item{
    ll sum;
};*/

struct segment {
    ll sz;
    vector<item> sums;

    item neural = 0; // change
    void init(ll n)
    {
        sz = 1;
        while(sz < n)
        {
            sz *= 2;
        }
        sums.assign(2*sz, neural);
    }

    item merge(item a, item b)
    {
        return max(a, b);
    }

    item single(ll v)
    {
        return v;
    }
    void build(vi &a, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1){
            if (lx < a.size())
            {
                sums[x] = single(a[lx]);
            }
            return;
        }
        ll mid = (lx + rx)/2;
        build(a, 2*x+1, lx, mid);
        build(a, 2*x+2, mid, rx);
        sums[x] = merge(sums[2*x+1] , sums[2*x+2]);
    }

    void build(vi &a)
    {
        build(a, 0, 0, sz);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx-lx == 1)
        {
            sums[x] = single(v);
            return;
        }
        ll mid = (lx+rx) / 2;
        if (i < mid)
        {
            set(i, v, 2*x+1, lx, mid);
        }
        else
        {
            set(i, v, 2*x+2, mid, rx);
        }
        sums[x] = merge(sums[2*x+1] , sums[2*x+2]);
    }

    void set(ll i, ll v)
    {
        set(i, v, 0, 0, sz);
    }

    item sum(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >=r || l >= rx)
            return neural;

        if (lx >= l && rx <= r)
            return sums[x];

        ll mid = (lx + rx)/2;
        item s1 = sum(l, r, 2*x+1, lx, mid);
        item s2 = sum(l, r, 2*x+2, mid, rx);
        return merge(s1 , s2);

    }
    item sum(ll l, ll r)
    {
        return sum(l, r, 0, 0, sz);
    }

    ll find(ll k, ll x, ll lx, ll rx){
        if (rx-lx == 1)
            return lx;

        ll mid = (lx+rx)/2;
        ll sl = sums[2*x+1];
        if (k < sl) {
            return find(k, 2*x+1, lx, mid);
        }
        else {
            return find(k-sl, 2*x+2, mid, rx);
        }

    }

    ll find(ll k){
        return find(k, 0, 0, sz);
    }


};

void solve(ll test) {

    ll n,m;cin>>n>>m;
    segment st;
    st.init(n);
    vi a(n);
    cin(a);
    st.build(a);
   
    a[x] = val;
    st.set(x, val);

    ll x;cin>>x;
    cout<<st.find(x)<<"\n";
        

}






// find the first element greater than or equal to x and idx > idx

ll find(ll k, ll idx, ll x, ll lx, ll rx){  // add idx to the function

        if (sums[x]<k || rx <= idx)
            return -1;

        if (rx-lx == 1)
            return lx;

        ll mid = (lx+rx)/2;
        ll res = find(k, idx,2*x+1, lx, mid);
        if (res == -1) {
            res = find(k, idx, 2*x+2, mid, rx);;
        }
        return res;
    }

    ll find(ll k, ll idx){
        return find(k, idx,0, 0, sz);
    }




