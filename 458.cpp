#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		if (cin.eof())
			break;
		for (int i = 0; i < s.size(); ++i)
			s[i] = char(s[i] - 7);
		cout << s << endl;
	}
}