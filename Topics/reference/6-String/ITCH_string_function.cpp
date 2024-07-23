string substr (size_t pos, size_t len) const;
string r = s1.substr(3, 2);
==============================================
size_t find (const string& str, size_t pos = 0); // for C++ Style Strings
         or
size_t find (const char* s, size_t pos = 0);     // for C-Style Strings
str: The sub-string to be searched.
s: The sub-string to be searched, given as a C-style string.
pos: The initial position from where the string search is to begin.

string str = "geeksforgeeks a computer science";
  string str1 = "geeks";
   
  // Find first occurrence of "geeks"
  size_t found = str.find(str1);
  if (found != string::npos)
    cout << "First occurrence is " << 
             found << endl;
   
  // Find next occurrence of "geeks".
  // Note here we pass
  // "geeks" as C style string.
  char arr[] = "geeks";
  found = str.find(arr, found+1);
  if (found != string::npos)
    cout << "Next occurrence is " << 
             found << endl;
  return 0;
=====================================================