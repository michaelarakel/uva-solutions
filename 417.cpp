#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool is_uniquely_sorted (const string& s)
{
	for (int i = 1; i < s.size(); ++i)
		if (s[i] <= s[i - 1])
			return false;
	return true;
}

int main ()
{
	vector < vector <int> > d(5, vector <int> (26));
	for (int j = 0; j < 26; ++j)
		d[0][j] = 1;
	for (int i = 1; i < 5; ++i)
		for (int j = 0; j < 26; ++j)
		{
			int sum = 0;
			for (int k = j + 1; k < 26; ++k)
				sum += d[i - 1][k];
			d[i][j] = sum;
		}
	string input;
	while (cin >> input)
	{
		if (!is_uniquely_sorted(input))
			cout << 0;
		else
		{
			int ans = 1, pos = input[0] - 'a';
			for (int i = 0; i < input.size(); ++i)
				for (int j = 0; j < 26; ++j)
				{
					if (i == input.size() - 1 &&
						j == pos)
						break;
					ans += d[i][j];
				}
			input.erase(input.begin());
			while (!input.empty())
			{
				int end = input[0] - 'a', i = input.size() - 1;
				for (int j = pos + 1; j < end; ++j)
					ans += d[i][j];
				pos = end;
				input.erase(input.begin());
			}
			cout << ans;
		}
		cout << endl;
	}
}