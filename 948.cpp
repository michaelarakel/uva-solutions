#include <iostream>
#include <vector>

using namespace std;

vector <long long> fib;

void print (const vector <char>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}

void fibinary (long long n, int pos)
{
	/*for (int i = 0; i < 1000; i++)
			if (n < fib[i])
			{
				pos = i - 1;
				break;
			}*/
	vector <char> v;
	long long temp = n;
	for (int i = pos; i >= 0; --i)
	{
		if (temp >= fib[i])
		{
			v.push_back('1');
			temp -= fib[i];
		}
		else
			v.push_back('0');
	}
	cout << n << " = ";
	print(v);
	if (n == 0)
		cout << '0';
	cout << " (fib)" << endl;
}

int main ()
{
	fib.push_back(1);
	fib.push_back(2);
	for (int i = 2; i < 1000; i++)
		fib.push_back(fib[i - 1] + fib[i - 2]);
	long long n;
	int pos;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		for (int i = 0; i < 1000; i++)
			if (n < fib[i])
			{
				pos = i - 1;
				break;
			}
		fibinary(n, pos);
	}

}