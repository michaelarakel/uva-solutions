#include <iostream>

using namespace std;

int main()
{
	long long a, b;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
			break;
		int carry = 0,
			operation_num = 0;
		while (a != 0 || b != 0)
		{
			int temp = a % 10 + b % 10 + carry;
			a /= 10;
			b /= 10;
			if (temp > 9)
			{
				carry = 1;
				++operation_num;
			}
			else
				carry = 0;
		}
		if (operation_num == 1)
			cout << 1 << " carry operation.";
		else if (operation_num)
			cout << operation_num << " carry operations.";
		else
			cout << "No carry operation.";
		cout << endl;
	}

}