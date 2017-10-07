#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int counter;
const int maxn = 15;
bool col[maxn], diag1[2 * maxn - 1], diag2[2 * maxn - 1];
char v[maxn][maxn];

void sol (int Qnum, int n)
{
	if (Qnum == n)
	{
		++counter;
		return;
	}
	int i = Qnum;
	for (int j = 0; j < n; j++)
	{
		int diag1Def = i - j + n - 1, diag2Def = i + j;
		if (v[i][j] != '*' && col[j] && diag1[diag1Def] && diag2[diag2Def])
		{
			v[i][j] = '*';
			col[j] = diag1[diag1Def] = diag2[diag2Def] = false;
			sol(Qnum + 1, n);
			v[i][j] = '.';
			col[j] = diag1[diag1Def] = diag2[diag2Def] = true;
		}
	}
	return;
}

void nextit (int n, int itnum)
{
	for (int i = 0; i < n; i++) 
	{
		col[i] = true;
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	}
	for (int i = 0; i < 2 * n - 1; ++i)
		diag1[i] = diag2[i] = true;
	counter = 0;
	int Qnum = 0;
	sol(Qnum, n);
	cout << "Case " << itnum << ": " << counter << endl;
}

int main ()
{
	int n, itnum = 1;
	cin >> n;
	while (n != 0)
	{
		nextit(n, itnum);
		cin >> n;
		++itnum;
	}
}