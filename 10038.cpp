#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		if (n == 1)
		{
			int num;
			cin >> num;
			cout << "Jolly" << endl;
			continue;
		}
		vector <int> v(n);
		vector <char> used(n, false);
		int num1, num2;
		cin >> num1;
		for (int i = 1; i < n; ++i)
		{
			cin >> num2;
			if (abs(num2 - num1) > 0 && abs(num2 - num1) <= n)
				used[abs(num2 - num1) - 1] = true;
			num1 = num2;
		}
		bool ans = true;
		for (int i = 0; i < n - 1; ++i)
		if (!used[i])
		{
			ans = false;
			break;
		}
		if (ans)
			cout << "Jolly";
		else
			cout << "Not jolly";
		cout << endl;
	}
}