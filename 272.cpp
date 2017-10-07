#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	string s, text;
	while (getline(cin, s))
	{
		text += s;
		text += "\n";
	}

	deque <int> d;
	for (int i = 0; i < text.size(); ++i)
	if (text[i] == '"')
		d.push_back(i);

	bool turn = 1;
	bool checker = (d.size() & 1);
	for (int i = 0; i < text.size(); ++i)
	{
		if (d.size() <= 1 && checker)
			cout << text[i];
		else
		{
			if (!d.empty() && i == d.front())
			{
				if (turn)
					cout << "``";
				else
					cout << "''";
				turn = !turn;
				d.pop_front();
			}
			else
				cout << text[i];
		}
	}
}