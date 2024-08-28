//How to use find in string

string str,str1;cin>>str>>str1;
int found = str.find(str1); //return -1 if not found and the index of the first char if found
if (found != -1)
{
    cout<<"YES\n";
    cout<<found;
    return;
}
cout<<"NO";

// find too
string str,str1;cin>>str>>str1;
size_t found = str.find(str1);
if (found != string::npos) // change
{
    cout<<"YES";
    cout<<it;
    return;
}
cout<<"NO";



//getline
getline(cin,s);



ll Longest_Increasing_SubSeq(vi X) {
    vi Z;
    for (int i = 0; i < X.size(); i++){
        ll re = upper_bound(Z.begin(), Z.end(), X[i]) - Z.begin();
        if (re == Z.size())Z.push_back(X[i]);
        else Z[re] = X[i];
    }
    return Z.size();
}




int longestPalindrome(string s) {
      unordered_map<char, int> mp;
      for (auto i : s)
         mp[i]++;
      int ma = 0, c = 0, ans = 0;
      for (auto i : mp) {
         if ((i.second) % 2 == 1)
            ma++;
         c += i.second;
      }
      if (ma > 0)
         ma--;
      ans = c - ma;
      return ans;
   }
