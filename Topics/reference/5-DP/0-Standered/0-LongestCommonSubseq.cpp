ll LongestCommonSubseq(string &s, string &t) {
	vii X(s.size() + 1, vi(t.size() + 1));
	for (int i = 1; i <= s.size(); i++)
		for (int j = 1; j <= t.size(); j++)
		{
			X[i][j] = max(X[i][j - 1], X[i - 1][j]);
			X[i][j] = max(X[i][j], X[i - 1][j - 1] + (s[i - 1] == t[j - 1]));
		}
	return (X[s.size()][t.size()]);
}


// if all element are uniq we can map each element to index in other set and find the longest increasing subsequance.