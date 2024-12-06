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

