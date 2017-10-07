#include <iostream>
#include <vector>

using namespace std;

void solve(int n)
{
	vector <vector <pair <int, int> > > v(n);
	int h;
	cin >> h;
	vector <int> hotel(h);
	for (int i = 0; i < j; ++i)
		cin >> hotel[i];
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, cost;
		v[a - 1].push_back(make_pair(b - 1, cost));
		v[b - 1].push_back(make_pair(a - 1, cost));
	}
	vector <vector <pair <int, int> > > g(h + 2);
	dijkstra(g, v, 0);
	for (int i = 0; i < h; ++i)
		dijkstra(
}

int main ()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		solve(n);
		cin >> n;
	}
}