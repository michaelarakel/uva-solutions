#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void solve (vector <vector <char> >& v, int n, int m, pair <int, int> sJ, vector <pair <int, int> > sF)
{
	deque <pair <int, int> > d1, d2;
	for (int i = 0; i < sF.size(); ++i)
		d1.push_back(sF[i]);
	d2.push_back(sJ);
	vector <vector <int> > len(n + 2, vector <int>(m + 2));
	while (!d2.empty())
	{
		const int a[] = { 1, -1, 0, 0},
				  b[] = { 0, 0, 1, -1};
		if(!d1.empty())
		{
			int size = d1.size();
			for (int j = 0; j < size; ++j)
			{
				pair <int, int> pos = d1[0];
				d1.pop_front();
				for (int i = 0; i < 4; ++i)
				{
					int x = pos.first + a[i], y = pos.second + b[i];
					if (x > 0 && x <= n &&
						y > 0 && y <= m &&
						v[x][y] != '#' &&
						v[x][y] != 'F')
					{
						d1.push_back(make_pair(x, y));
						v[x][y] = 'F';
					}
				}
			}
		}
		if (!d2.empty())
		{
			int size = d2.size();
			for (int j = 0; j < size; ++j)
			{
				pair <int, int> curr = d2[0];
				d2.pop_front();
				if (curr.first == 0 || curr.first == n + 1 ||
					curr.second == 0 || curr.second == m + 1)
				{
					cout << len[curr.first][curr.second] << endl;
					return;
				}
				for (int i = 0; i < 4; ++i)
				{
					int x = curr.first + a[i], y = curr.second + b[i];
					if (x >= 0 && x < n + 2 &&
						y >= 0 && y < m + 2 &&
						v[x][y] == '.')
					{
						d2.push_back(make_pair(x, y));
						len[x][y] = len[curr.first][curr.second] + 1;
						v[x][y] = 'J';
					}
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main ()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		int n, m;
		cin >> n >> m;
		vector <vector <char> > v(n + 2, vector <char>(m + 2, '.'));
		pair <int, int> John;
		vector <pair <int, int> > Fire;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				cin >> v[i][j];
				if (v[i][j] == 'J')
					John = make_pair(i, j);
				if (v[i][j] == 'F')
					Fire.push_back(make_pair(i, j));
			}
		solve(v, n, m, John, Fire);
	}
}