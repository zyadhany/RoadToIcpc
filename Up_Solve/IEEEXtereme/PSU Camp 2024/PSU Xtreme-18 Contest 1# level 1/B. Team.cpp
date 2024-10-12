#include <iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<numeric>
 
 
using namespace std;
 
void FP()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
 
bool isPos(int num) {
	if (num > 0)
	{
		return true;
	}
	return false;
}
 
int main()
{
	FP();
	int n , r ,s , summ =0;
	cin >> n;
	while (n--)
	{
		s = 0;
		for (size_t i = 0; i < 3; i++)
		{
			cin >> r;
			s += r;
		}
		if (s > 1)
		{
			summ++;
		}
 
	}
 
	cout << summ;
 
}