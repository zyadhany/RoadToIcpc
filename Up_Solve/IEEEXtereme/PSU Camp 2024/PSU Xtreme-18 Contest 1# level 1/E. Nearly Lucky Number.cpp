#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    string s;
    cin >> s;
    bool s4 = 0, s7 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '4' || s[i] == '7')
        {
            n++;
        }
    }
    do
    {
        if (n%10 != 7 && n%10 !=4)
        {
            cout << "NO";
            return 0;
        }
        n /= 10;
    } while (n > 0);

    cout << "YES";
}