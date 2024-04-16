
// compare function
struct mycmp {
    // top is smallest number
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

priority_queue<ll, vi, mycmp> L;