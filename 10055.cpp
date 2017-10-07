#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	long long a, b;
	while (cin >> a >> b)
	{
		if (cin.eof())
			break;
		cout << abs(b - a) << endl;
	}
}