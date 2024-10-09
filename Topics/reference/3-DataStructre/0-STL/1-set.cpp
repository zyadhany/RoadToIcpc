// custom copmprator
struct cmp {
    bool operator() (int a, int b) const {
        return a < b;
    }
};
set<int, cmp> st;


// find the greates element less than him in left.
vi Smallestonleft(vi& arr)
{
    int n = arr.size();
    vi Z(n);
    set<ll> X;
    X.insert(-1);

    for (int i = 0; i < n; i++)
    {
        auto it = X.insert(arr[i]).first;
        it--;
        Z[i] = *it;
    }

    return (Z);
}