#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string fibinarysum (string& s1, string& s2)
{
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int diff = abs(s1.size() - s2.size());
	if (s1.size() < s2.size())
		for (int i = 0; i < diff; i++)
			s1.push_back('0');
	if (s2.size() < s1.size())
		for (int i = 0; i < diff; i++)
			s2.push_back('0');
	string ans = "";
	bool inmind = false;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == '0' && s2[i] == '1' ||
			s1[i] == '1' && s2[i] == '0')
		{
			if (inmind)
				ans.push_back('0');
			else
				ans.push_back('1');
		}
		if (s1[i] == '1' && s2[i] == '1')
		{
			if (inmind)
				ans.push_back('1');
			else
				ans.push_back('0');
			inmind = true;
		}
		if (s1[i] == '0' && s2[i] == '0')
		{
			if (inmind)
			{
				ans.push_back('1');
				inmind = false;
			}
			else
				ans.push_back('0');
		}
	}
	bool follOne = false;
	for (int i = 1; i < ans.size(); i++)
	{
		if (follOne)
		{
			if (ans[i] == '0')
			{
				ans[i] = '1';
				follOne = false;
			}
			else
				ans[i] = '0';
		}
		if (ans[i] == '1' && ans[i - 1] == '1')
		{
			follOne = true;
			ans[i] = ans[i - 1] = '0';
		}
	}
	if (follOne)
		ans.push_back('1');
	reverse(ans.begin(), ans.end());
	return ans;
}

int main ()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << fibinarysum(s1, s2);
}