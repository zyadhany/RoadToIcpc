/*
    De Bruijn Sequence is sequance of a given length n, is string that contains every possible combination if string with k characters
    of length n as a substring.

    in case for k = 2, that is binary string, at n = 2 we can have 00, 01, 10, 11 so sequance is 00110.
    
    To generate De Bruijn Sequence we can use Eulerian path in a directed graph, where each node is a string of length n-1, and each edge is either 0 or 1 added to the end of the string.
    The path will visit every edge exactly once, and the resulting sequence will contain every possible combination
*/

void solve(int tc) {
	ll n;

	cin >> n;
	if (n == 1) {
		cout << "01\n";
		return;
	}
	n--;
	Graph gr(1<<n);
	for (int i = 0; i < (1<<n); i++)
	{
		ll re = ((i & ((1<<(n-1))-1)) << 1);
		gr.addEdge(i, re);
		gr.addEdge(i, re|1);		
	}
	auto Z = gr.EulerPath(0);
	for (int i = 0; i < n-1; i++) cout << "0";
	for (auto a : Z) cout << (a&1);
}
