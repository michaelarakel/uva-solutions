#include <iostream>

using namespace std;

int main()
{
	int v, t;
	while(cin >> v >> t)
	{
		if (cin.eof())
			break;
		cout << ((v * t) << 1) << endl;
	}
}