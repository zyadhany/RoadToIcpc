// idea here is to optmize backtracking
// if you use better best case it can handle time.

ll req(vii &vis, string &s, ll at, ll l, ll r) {
    if (vis[l][r]) return (0);
    if (l == 7 && r == 1) return (at == 48);
    if (vis[l - 1][r] && vis[l + 1][r] && !vis[l][r - 1] && !vis[l][r + 1]) return (0);
    if (!vis[l - 1][r] && !vis[l + 1][r] && vis[l][r - 1] && vis[l][r + 1]) return (0);
    if (vis[l - 1][r + 1] && !vis[l - 1][r] && !vis[l][r + 1]) return (0);
    if (vis[l + 1][r + 1] && !vis[l + 1][r] && !vis[l][r + 1]) return (0);
    if (vis[l + 1][r - 1] && !vis[l + 1][r] && !vis[l][r - 1]) return (0);
    if (vis[l - 1][r - 1] && !vis[l - 1][r] && !vis[l][r - 1]) return (0);
    vis[l][r] = 1;
 
    ll summ = 0;
 
    if (s[at] == '?') {
        summ += req(vis, s, at + 1, l + 1, r);
        summ += req(vis, s, at + 1, l - 1, r);
        summ += req(vis, s, at + 1, l, r + 1);
        summ += req(vis, s, at + 1, l, r - 1);
    }else if (s[at] == 'U') {
        summ += req(vis, s, at + 1, l - 1, r);
    } else if (s[at] == 'D') {
        summ += req(vis, s, at + 1, l + 1, r);
    } else if (s[at] == 'R') {
        summ += req(vis, s, at + 1, l, r + 1);
    } else if (s[at] == 'L'){
        summ += req(vis, s, at + 1, l, r - 1);
    }
 
    vis[l][r] = 0;
    return (summ);
}
