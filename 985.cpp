#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

struct node 
{
	int first;
	int second;
	int third;
};

bool operator != (const node& a, const node& b)
{
	return (a.first != b.first) || (a.second != b.second) || (a.third != b.third);
}

string reverse (const string& s)
{
	if (s == "exit")
		return s;
	string ans = "";
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'N')
			ans.push_back('E');
		if (s[i] == 'S')
			ans.push_back('W');
		if (s[i] == 'E')
			ans.push_back('S');
		if (s[i] == 'W')
			ans.push_back('N');
	}
	return ans;
}


void rev (const vector <vector <string> >& v1, vector <vector <string> >& v2)
{
	for (int i = 1; i < v1.size() - 1; ++i)
		for (int j = 1; j < v1[j].size() - 1; ++j)
			v2[i][j] = reverse(v1[i][j]);
}

void bfs(vector <vector <vector <string> > >& v, int n, int m)
{
	node start;
	start.first = 0;
	start.second = start.third = 1;
	deque <node> d;
	d.push_back(start);
	vector < vector <vector <pair <char, int> > > > used(4, vector <vector <pair <char, int> > >(n + 2, vector <pair <char, int> >(m + 2)));
	used[0][1][1].first = true;
	used[0][1][1].second = 0;
	while (!d.empty())
	{
		node curr = d[0];
		d.pop_front();
		string s = v[curr.first][curr.second][curr.third];
		int num = used[curr.first][curr.second][curr.third].second + 1;
		for (int i = 0; i < s.size(); ++i)
		{
			node temp;
			temp.first = (curr.first + 1) % 4;
			if (s[i] == 'N')
			{
				if (!used[temp.first][curr.second - 1][curr.third].first)
				{
					used[temp.first][curr.second - 1][curr.third].first = true;
					used[temp.first][curr.second - 1][curr.third].second = num;
					temp.second = curr.second - 1;
					temp.third = curr.third;
					d.push_back(temp);
				}
			}
			if (s[i] == 'S')
			{
				if (!used[temp.first][curr.second + 1][curr.third].first)
				{
					used[temp.first][curr.second + 1][curr.third].first = true;
					used[temp.first][curr.second + 1][curr.third].second = num;
					temp.second = curr.second + 1;
					temp.third = curr.third;
					d.push_back(temp);
				}
			}
			if (s[i] == 'W')
			{
				if (!used[temp.first][curr.second][curr.third - 1].first)
				{
					used[temp.first][curr.second][curr.third - 1].first = true;
					used[temp.first][curr.second][curr.third - 1].second = num;
					temp.second = curr.second;
					temp.third = curr.third - 1;
					d.push_back(temp);
				}
			}
			if (s[i] == 'E')
			{
				if (!used[temp.first][curr.second][curr.third + 1].first)
				{
					used[temp.first][curr.second][curr.third + 1].first = true;
					used[temp.first][curr.second][curr.third + 1].second = num;
					temp.second = curr.second;
					temp.third = curr.third + 1;
					d.push_back(temp);
				}
			}
		}
		if (used[0][n][m].first)
		{
			cout << used[0][n][m].second << endl;
			return;
		}
		if (used[1][n][m].first)
		{
			cout << used[1][n][m].second << endl;
			return;
		}
		if (used[2][n][m].first)
		{
			cout << used[2][n][m].second << endl;
			return;
		}
		if (used[3][n][m].first)
		{
			cout << used[3][n][m].second << endl;
			return;
		}
	}
	cout << "no path to exit" << endl;
}

int main ()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector <vector <vector <string> > > v(4, vector <vector <string> >(n + 2, vector <string>(m + 2)));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (i * j != n * m)
					cin >> v[0][i][j];
			}
		}
		v[0][n][m] = "exit";
		for (int k = 1; k < 4; ++k)
			rev(v[k - 1], v[k]);
		bfs(v, n, m);
	}
}