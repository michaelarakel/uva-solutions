#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef pair <int, pair <int, int> > node;

node make_node(int a, int b, int c)
{
	node temp;
	temp.second.first = a;
	temp.second.second = b;
	temp.first = c;
	return temp;
}

int main ()
{
	const int INF = 1000 * 1000 * 1000;
	int N;
	cin >> N;
	for (int itnum = 0; itnum < N; ++itnum)
	{
		int n, m;
		cin >> n >> m;
		vector <vector <int> > v(n, vector <int>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> v[i][j];
		vector <vector <vector <pair<int, int> > > > g(n, vector <vector < pair <int, int> > >(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				const int a[] = {1, -1, 0, 0},
						  b[] = {0, 0, 1, -1};
				for (int k = 0; k < 4; ++k)
					if (i + a[k] >= 0 && i + a[k] < n && j + b[k] >= 0 && j + b[k] < m)
						g[i][j].push_back(make_pair(i + a[k], j + b[k]));
			}
		node start = make_node(0, 0, v[0][0]);
		set <node> s;
		s.insert(start);
		vector <vector <int> > dist(n, vector <int>(m, INF));
		dist[0][0] = 0;
		while (!s.empty())
		{
			set <node>::iterator it = s.begin();
			pair <int, int> curr = make_pair(it->second.first, it->second.second);
			s.erase(it);
			for (int i = 0; i < g[curr.first][curr.second].size(); ++i)
			{
				pair <int, int> currNode = make_pair(g[curr.first][curr.second][i].first, g[curr.first][curr.second][i].second);
				int len = v[currNode.first][currNode.second] + dist[curr.first][curr.second];
				if (dist[currNode.first][currNode.second] > len)
				{
					s.erase(make_node(currNode.first, currNode.second, dist[currNode.first][currNode.second]));
					dist[currNode.first][currNode.second] = len;
					s.insert(make_node(currNode.first, currNode.second, dist[currNode.first][currNode.second]));
				}
			}
		}
		cout << dist[n - 1][m - 1] << endl;
	}
}