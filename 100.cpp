#include <iostream>

using namespace std;

int main ()
{
	int start, end;
	while (cin >> start >> end)
	{
		cout << start << ' ' << end << ' ';
		if (start > end)
			swap(start, end);
		int ans = 0;
		for (int i = start; i <= end; ++i)
		{
			int count = 1;
			int n = i;
			while (n != 1)
			{
				if (n & 1)
					n = 3 * n + 1;
				else
					n >>= 1;
				++count;
			}
			if (ans < count)
				ans = count;
		}
		cout << ans << endl;
	}
}