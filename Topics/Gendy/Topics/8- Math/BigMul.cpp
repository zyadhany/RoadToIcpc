string a, b;
cin >> a >> b;
if (a == "0" || b == "0")
{
    cout << "0" << endl;
    return;
}
reverse(a.begin(), a.end());
reverse(b.begin(), b.end());
vi ans(600, 0);
for (int i = 0; i < a.size(); ++i)
{
    for (int j = 0; j < b.size(); ++j)
    {
        ans[i + j] += (a[i] - '0') * (b[j] - '0');
    }
}
for (int i = 0; i < 599; ++i)
{
    ans[i + 1] += ans[i] / 10;
    ans[i] %= 10;
}
while (ans.back() == 0)
    ans.pop_back();
for (int i = ans.size() - 1; i >= 0; --i)
{
    cout << ans[i];
}
cout << endl;