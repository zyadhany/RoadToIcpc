#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<int, int>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9;

using namespace std;

ll n;
pl st;
vector<vector<string>> X;
bool beenthere[25][25][19683];
set<int> answers;

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};
int pow3[10];

bool test_win(int b)
{
  int cells[3][3];
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++) {
      cells[i][j] = b%3;
      b /= 3;
    }
  for (int r=0; r<3; r++) {
    if (cells[r][0] == 1 && cells[r][1] == 2 && cells[r][2] == 2) return true;
    if (cells[r][0] == 2 && cells[r][1] == 2 && cells[r][2] == 1) return true;
  }
  for (int c=0; c<3; c++) {
    if (cells[0][c] == 1 && cells[1][c] == 2 && cells[2][c] == 2) return true;
    if (cells[0][c] == 2 && cells[1][c] == 2 && cells[2][c] == 1) return true;
  }
  if (cells[0][0] == 1 && cells[1][1] == 2 && cells[2][2] == 2) return true;
  if (cells[0][0] == 2 && cells[1][1] == 2 && cells[2][2] == 1) return true;
  if (cells[2][0] == 1 && cells[1][1] == 2 && cells[0][2] == 2) return true;
  if (cells[2][0] == 2 && cells[1][1] == 2 && cells[0][2] == 1) return true;
  return false;
}

void dfs(ll l, ll r, ll b) {
    if (beenthere[l][r][b]) return;
    beenthere[l][r][b] = true;
    
    if (X[l][r][0] == 'M' || X[l][r][0] == 'O') {
        ll ro = X[l][r][1] - '1';
        ll co = X[l][r][2] - '1';
        ll idx = ro * 3 + co;
        ll cur = (b / pow3[idx]) % 3;
        
        if (cur == 0) {
            ll val = X[l][r][0]=='M' ? 1 : 2;
            b = (b % pow3[idx]) + val * pow3[idx] + (b - b % pow3[idx+1]);
            if (test_win(b)) {
                answers.insert(b);
                return;
            }
            beenthere[l][r][b] = true;
        }
    }

    if (X[l-1][r][0] != '#') dfs(l-1,r,b);
    if (X[l+1][r][0] != '#') dfs(l+1,r,b);
    if (X[l][r-1][0] != '#') dfs(l,r-1,b);
    if (X[l][r+1][0] != '#') dfs(l,r+1,b);
}

void solve(int tc) {
    cin >> n;

    X.assign(n, vector<string>(n));
    
    pow3[0] = 1;
    for (int i=1; i<=9; i++) pow3[i] = pow3[i-1]*3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            X[i][j] = "...";
            cin >> X[i][j][0] >> X[i][j][1] >> X[i][j][2];
            if (X[i][j] == "BBB") st = {i, j};
        }
    }
    dfs(st.first, st.second, 0);
    cout << answers.size() << ln;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("snowboots.in", "r", stdin);
    // freopen("snowboots.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
