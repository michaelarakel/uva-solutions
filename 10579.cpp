#include <iostream>
#include <vector>

using namespace std;

void print (const vector <int>& v, int n)
{
	cout << "The Fibonacci number for " << n << " is "; 
	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i];
	cout << endl;
}


vector <int> sum (vector <int> v1, vector <int> v2)
{
	vector <int> sum;
	bool inmind = false;
	int m = max(v1.size(), v2.size());
	v1.resize(m);
	v2.resize(m);
	for (int i = 0; i < v1.size(); i++)
	{
		int temp = v1[i] + v2[i];
		if (temp == 9)
		{
			if (inmind)
				sum.push_back(0);
			else
				sum.push_back(9);
		}
		else if (temp <= 8)
		{
			if (inmind)
			{
				++temp;
				inmind = false;
			}
			sum.push_back(temp);
		}
		else
		{
			if (inmind)
				temp++;
			sum.push_back(temp - 10);
			inmind = true;
		}
	}
	if (inmind)
		sum.push_back(1);
	return sum;
}

int main ()
{
	vector < vector <int> > fib;
	vector <int> one(1, 0), two (1, 1);
	fib.push_back(one);
	fib.push_back(two);
	for (int i = 2; i <= 5002; i++)
		fib.push_back(sum(fib[i - 2], fib[i - 1]));
	int n;
	while (cin >> n)
		print(fib[n], n);
}