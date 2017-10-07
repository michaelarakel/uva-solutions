#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> maxSub;
int maxAns;

void rec (const vector <int>& v, vector <int>& ans, const int tapeLen, int currSum, int pos)
{
	if (currSum > tapeLen)
		return;
	if (currSum <= tapeLen)
	{
		if (maxAns < currSum)
		{
			maxSub = ans;
			maxAns = currSum;
		}
	}
	for (int i = pos; i < v.size(); ++i)
	{
		ans.push_back(v[i]);
		currSum += v[i];
		rec(v, ans, tapeLen, currSum, i + 1);
		currSum -= v[i];
		ans.pop_back();
	}
}

int main ()
{
	int sum;
	while (cin >> sum)
	{
		maxAns = 0;
		int n;
		cin >> n;
		vector <int> v(n);
		for (int i = 0; i < n; ++i)
		cin >> v[i];
		vector <int> ans;
		rec(v, ans, sum, 0, 0);
		for (int i = 0; i < maxSub.size(); ++i)
			cout << maxSub[i] << " ";
		cout << "sum:" << maxAns << endl;
	}
}