#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void print (const vector <int>& v)
{
	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i];
	cout << " ";
}

bool operator >= (const vector <int>& v1, const vector <int>& v2)
{
	if (v1.size() > v2.size())
		return true;
	if (v1.size() < v2.size())
		return false;
	for (int i = v1.size() - 1; i >= 0; --i)
	{
		if (v1[i] > v2[i])
			return true;
		if (v1[i] < v2[i])
			return false;
	}
	return true;
}

vector < vector <int> > fib;

void fibsonint(vector <int>& v1, vector <int>& v2)
{
	reverse (v1.begin(), v1.end());
	reverse (v2.begin(), v2.end());
	int v1Count = 0, v2Count = 0;
	for (int i = 0; i < fib.size(); i++)
	{
		if (v1 >= fib[i])
		{
			v1Count++;
			if (v1 == fib[i])
				v1Count--;
		}
		if (v2 >= fib[i])
		{
			v2Count++;
		}
		else
			break;
	}
	cout << v2Count - v1Count << endl;
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
	vector <int> one(1, 1), two (1, 2);
	fib.push_back(one);
	fib.push_back(two);
	for (int i = 2; i <= 10000; i++)
		fib.push_back(sum(fib[i - 2], fib[i - 1]));
	string s1, s2;
	cin >> s1 >> s2;
	while (s1 != "0" || s2 != "0")
	{
		istringstream iss1(s1);
		istringstream iss2(s2);
		char num1, num2;
		vector <int> v1, v2;
		while (iss1 >> num1)
			v1.push_back(num1 - '0');
		while (iss2 >> num2)
			v2.push_back(num2 - '0');
		fibsonint(v1, v2);
		cin >> s1 >> s2;
	}
}
