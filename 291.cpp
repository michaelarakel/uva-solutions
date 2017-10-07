#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <vector <int> > v(5);

bool check (const string& s)
{
	vector <vector <int> > g(5);
	for (int i = 0; i < s.size(); ++i)
	{
		int node = s[i] - '1';
		for (int k = -1; k < 2; k += 2)
			if (i + k >= 0 && i + k < s.size())
				g[node].push_back(s[i + k] - '1');
	}
	for (int i = 0; i < 5; ++i)
		sort(g[i].begin(), g[i].end());
	bool ans = (v == g);
	return (v == g);
}

int main ()
{
	v[0].push_back(1);
	v[0].push_back(2);
	v[0].push_back(4);

	v[1].push_back(0);
	v[1].push_back(2);
	v[1].push_back(4);

	v[2].push_back(0);
	v[2].push_back(1);
	v[2].push_back(3);
	v[2].push_back(4);

	v[3].push_back(2);
	v[3].push_back(4);

	v[4].push_back(0);
	v[4].push_back(1);
	v[4].push_back(2);
	v[4].push_back(3);

	vector <string> ans;
	string s;
	s = "112233455";
	while (s[0] == '1')
	{
		if (check(s))
		{
			ans.push_back(s);
		}
		next_permutation(s.begin(), s.end());
	}
	sort (ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;
}