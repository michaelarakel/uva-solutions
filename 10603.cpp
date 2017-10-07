#include <iostream>
#include <map>
#include <deque>
#include <vector>

using namespace std;

struct node
{
	int first;
	int second;
	int third;
};

node make_node(int a, int b, int c)
{
	node temp;
	temp.first = a;
	temp.second = b;
	temp.third = c;
	return temp;
}

int main ()
{
	int N;
	cin >> N;
	for (int itnum = 0; itnum < N; ++itnum)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (d > a && d > b && d > c)
		{
			cout << max(a, max(b, c)) << " " << 2;
			continue;
		}
		deque <pair <node, int> > g;
		g.push_back(make_pair(make_node(0, 0, c), 0));
		vector <vector <vector <char> > > used(a + 1, vector <vector <char> >(b + 1, vector <char>(c + 1)));
		used[g[0].first.first][g[0].first.second][g[0].first.third] = true;
		pair <int, int> max = make_pair(0, 0);
		while (!g.empty())
		{
			node curr = g[0].first;
			int len = g[0].second;
			g.pop_front();
			if (curr.first == d || curr.second == d || curr.third == d)
			{
				cout << len << " " << d << endl;
				break;
			}
			if (max.first < curr.first && curr.first < d)
				max = make_pair(curr.first, len);
			if (max.first < curr.second && curr.second < d)
				max = make_pair(curr.second, len);
			if (max.first < curr.third && curr.third < d)
				max = make_pair(curr.third, len);
			int toFirst = a - curr.first,
				toSecond = b - curr.second,
				toThird = c - curr.third;
			if (curr.first != 0)
			{
				if (toSecond > 0)
				{
					node temp;
					int tempLen = 0;
					if (curr.first > toSecond)
					{
						temp = make_node(curr.first - toSecond, b, curr.third);
						tempLen = toSecond;
					}
					else
					{
						temp = make_node(0, curr.second + curr.first, curr.third);
						tempLen = curr.first;
					}
					if (!used[temp.first][temp.second][temp.third])
					{
						used[temp.first][temp.second][temp.third] = true;
						g.push_back(make_pair(temp, len + tempLen));
					}
				}
				if (toThird > 0)
				{
					node temp;
					int tempLen = 0;
					if (curr.first > toThird)
					{
						temp = make_node(curr.first - toThird, curr.second, c);
						tempLen = toThird;
					}
					else
					{
						temp = make_node(0, curr.second, curr.third + curr.first);
						tempLen = curr.first;
					}
					if (!used[temp.first][temp.second][temp.third])
					{
						used[temp.first][temp.second][temp.third] = true;
						g.push_back(make_pair(temp, len + tempLen));
					}
				}
			}
			if (curr.second != 0)
			{
				if (toFirst > 0)
				{
					node temp;
					int tempLen = 0;
					if (curr.second > toFirst)
					{
						temp = make_node(a, curr.second - toFirst, curr.third);
						tempLen = toFirst;
					}
					else
					{
						temp = make_node(curr.first + curr.second, 0, curr.third);
						tempLen = curr.second;
					}
					if (!used[temp.first][temp.second][temp.third])
					{
						used[temp.first][temp.second][temp.third] = true;
						g.push_back(make_pair(temp, len + tempLen));
					}
				}
				if (toThird > 0)
				{
					node temp;
					int tempLen = 0;
					if (curr.second > toThird)
					{
						temp = make_node(curr.first, curr.second - toThird, c);
						tempLen = toThird;
					}
					else
					{
						temp = make_node(curr.first, 0, curr.third + curr.second);
						tempLen = curr.second;
					}
					if (!used[temp.first][temp.second][temp.third])
					{
						used[temp.first][temp.second][temp.third] = true;
						g.push_back(make_pair(temp, len + tempLen));
					}
				}
			}
			if (curr.third != 0)
			{
				if (toFirst > 0)
				{
					node temp;
					int tempLen = 0;
					if (curr.third > toFirst)
					{
						temp = make_node(a, curr.second, curr.third - toFirst);
						tempLen = toFirst;
					}
					else
					{
						temp = make_node(curr.first + curr.third, curr.second, 0);
						tempLen = curr.third;
					}
					if (!used[temp.first][temp.second][temp.third])
					{
						used[temp.first][temp.second][temp.third] = true;
						g.push_back(make_pair(temp, len + tempLen));
					}
				}
				if (toSecond > 0)
				{
					node temp;
					int tempLen = 0;
					if (curr.third > toSecond)
					{
						temp = make_node(curr.first, b, curr.third  - toSecond);
						tempLen = toSecond;
					}
					else
					{
						temp = make_node(curr.first, curr.second + curr.third, 0);
						tempLen = curr.third;
					}
					if (!used[temp.first][temp.second][temp.third])
					{
						used[temp.first][temp.second][temp.third] = true;
						g.push_back(make_pair(temp, len + tempLen));
					}
				}
			}
		}
		if (g.empty())
			cout << max.first << " " << max.second << endl;
	}
}