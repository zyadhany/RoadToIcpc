#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
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

const int MODE = 1e9 + 7;

using namespace std;

string NumStringToBinery(string num) {
    string res = "";
    bool isvalue = 1;
    int ptr = 0;
    
    while(ptr < num.size())
    {
        int lst = num[num.size() - 1] - '0';
        num[num.size() - 1] = (lst / 2) + '0';
        res += (lst % 2) + '0';

        for (int j = num.size() - 2; j >= ptr; j--)
        {
            int at = num[j] - '0';
            num[j] = (at / 2) + '0';
            int nxt = num[j + 1] - '0' + 5 * (at % 2);

            if (nxt >= 10) {
                num[j]++;
                num[j + 1] = nxt % 10 + '0';
            } else {
                num[j + 1] = nxt + '0';
            }   
        }        
        while (ptr < num.size() && num[ptr] == '0') ptr++;   
    }

    reverse(all(res));
    return res;
}

string multiplyByPowerOf2(const string& num, int power) {
    string result = num;
    for (int i = 0; i < power; ++i) {
        int carry = 0;
        for (int j = result.size() - 1; j >= 0; --j) {
            int digit = (result[j] - '0') * 2 + carry;
            result[j] = (digit % 10) + '0';
            carry = digit / 10;
        }
        if (carry > 0) {
            result.insert(result.begin(), carry + '0');
        }
    }
    return result;
}

string binaryToDecimalHelper(const string& bin, int start, int end) {
    if (start == end) {
        return bin[start] == '1' ? "1" : "0";
    }
    int mid = (start + end) / 2;
    string left = binaryToDecimalHelper(bin, start, mid);
    string right = binaryToDecimalHelper(bin, mid + 1, end);

    int power = end - mid;
    string leftShifted = multiplyByPowerOf2(left, power);
    string result = leftShifted;

    int carry = 0;
    int i = leftShifted.size() - 1, j = right.size() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int leftDigit = (i >= 0) ? (result[i] - '0') : 0;
        int rightDigit = (j >= 0) ? (right[j] - '0') : 0;
        int sum = leftDigit + rightDigit + carry;
        if (i >= 0) {
            result[i] = (sum % 10) + '0';
        } else {
            result.insert(result.begin(), (sum % 10) + '0');
        }
        carry = sum / 10;
        --i;
        --j;
    }

    return result;
}

string BineryToNumString(const string& bin) {
    return binaryToDecimalHelper(bin, 0, bin.size() - 1);
}

string AddNumStringBinery(string a, string b) {
    string res = "";
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int aDigit = (i >= 0) ? (a[i] - '0') : 0;
        int bDigit = (j >= 0) ? (b[j] - '0') : 0;
        int sum = aDigit + bDigit + carry;
        res.insert(res.begin(), (sum % 2) + '0');
        carry = sum / 2;
        --i;
        --j;
    }

    return res;
}

string BigIntMul(string a, string b) {
    string binA = NumStringToBinery(a);
    string binB = NumStringToBinery(b);

    string res = "";
    for (int i = 0; i < binB.size(); i++) {
        if (binB[i] == '0') continue;
        string temp = binA;
        for (int j = 0; j < binB.size() - i - 1; j++) {
            temp += '0';
        }
        res = AddNumStringBinery(res, temp);
    }

    res = BineryToNumString(res);
    return res;
}

string req(string s, string t) {
    string a = NumStringToBinery(s);    
    string b = NumStringToBinery(t);    
    return AddNumStringBinery(a, b);
}

void solve(int tc) {
    string s, t;
    cin >> s >> t;
    cout << BigIntMul(s, t).size() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
