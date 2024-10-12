#include <iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<numeric>
 
 
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	if (n % 2 == 0 && n > 2)
	{
		cout << "YES";
	}
	else cout << "NO";
}