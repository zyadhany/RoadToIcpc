// custom compare
struct com {
    bool operator()(int l,int r)
    {
        return l<r;
    }

};

priority_queue<int,vector<int>,com>p;