// get lexicographically Largest subseq
vp lexicographicallyLargestSubSeq(string &s) {
    vp res;
    for (int i = 0; i < s.size(); i++)
    {
        while (!res.empty() && res.back().first < s[i])
            res.pop_back();
        res.push_back({s[i], i});
    }
    return (res);
}
