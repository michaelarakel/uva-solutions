#include <iostream>
//#include <bitset>

using namespace std;

/*void binary (int a)
{
	cout << bitset <numeric_limits<long int>::digits + 1>(a) << endl;
}*/

int main ()
{
	int borders[4] = {};
	int temp = 0;
	for (int i = 0; i < 8; ++i)
		temp = (temp << 1) + 1;
	borders[0] = (temp << 24);
	borders[1] = (temp << 16);
	borders[2] = (temp << 8);
	borders[3] = (temp);
	int n;
	while (cin >> n)
	{
		int tempN = n;
		if (n < 0)
			n = ~n;
		int ans = ((n & borders[0]) >> 24) | ((n & borders[1]) >> 8) | ((n & borders[2]) << 8) | ((n & borders[3]) << 24);
		if (tempN < 0)
			ans = ~ans;
		cout << tempN << " converts to " << ans << endl;
	}
}