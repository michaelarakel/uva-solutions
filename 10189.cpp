#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n, m;
	int itnum = 1;
	cin >> n >> m;
	while (1)
	{
		cout << "Field #" << itnum << ':' << endl;
		vector <vector <char> > board(n, vector <char>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> board[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (board[i][j] == '.')
				{
					board[i][j] = '0';
					for (int x = -1; x <= 1; ++x)
					if (i + x >= 0 && i + x < n)
						for (int y = -1; y <= 1; ++y)
						if (j + y >= 0 && j + y < m &&
							board[x + i][j + y] == '*')
							++board[i][j];
				}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cout << board[i][j];
			cout << endl;
		}
		++itnum;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		cout << endl;
	}
}