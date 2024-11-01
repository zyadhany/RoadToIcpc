#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    string a, b;

    cin >> a >> b;

    if ((a == "Red" && b == "Blue") || (a == "Blue" && b == "Red")) cout << "Purple\n";
    else if ((a == "Yellow" && b == "Blue") || (a == "Blue" && b == "Yellow")) cout << "Green\n";
    else cout << "Orange\n";
}
