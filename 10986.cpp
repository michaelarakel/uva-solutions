#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main ()
{
	const int INF = 1000 * 1000 * 1000;
	int N;
	cin >> N;
	for (int itnum = 1; itnum <= N; ++itnum)
	{
		int n, m, start, end;
		cin >> n >> m >> start >> end;
		vector <vector <pair <int, int> > > g(n);
		for (int i = 0; i < m; ++i)
		{
			int node1, node2, weight;
			cin >> node1 >> node2 >> weight;
			g[node1].push_back(make_pair(node2, weight));
			g[node2].push_back(make_pair(node1, weight));
		}
		set <pair <int, int> > s;
		s.insert(make_pair(0, start));
		vector <int> dist(n, INF);
		dist[start] = 0;
		while (!s.empty())
		{
			set <pair <int, int> >::iterator it = s.begin();
			int node = it->second;
			s.erase(it);
			for (int i = 0; i < g[node].size(); ++i)
			{
				int curr = g[node][i].first, len = dist[node] + g[node][i].second;
				if (dist[curr] > len)
				{
					s.erase(make_pair(dist[curr], curr));
					dist[curr] = len;
					s.insert(make_pair(dist[curr], curr));
				}
			}
		}
		if (dist[end] == INF)
			cout << "unreachable";
		else
			cout << dist[end];
		cout << endl;
	}
}