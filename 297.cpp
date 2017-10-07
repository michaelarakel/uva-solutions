#include <iostream>
#include <string>

using namespace std;

int pow (const int a, const int n)
{
	int ans = 1;
	for (int i = 0; i < n; i++)
		ans*= a;
	return ans;
}

bool black (const char a, const char b)
{
	return (a == 'f' || b == 'f');
}

bool white (const char a, const char b)
{
	return (a == 'e' && b == 'e');
}

void parent (string& ans, const string& s, int& pos)
{
	ans.push_back('p');
	int count = 0;
	while (count < 4)
	{
		if (s[pos] != 'p')
			ans.push_back(s[pos++]);
		else
			parent(ans, s, ++pos);
		count++;
	}
}

void bothparents (const string& s1, int& pos1, const string& s2, int& pos2, string& ans)
{
	ans.push_back('p');
	int count = 0;
	while (count < 4)
	{
		++count;
		if (white(s1[pos1], s2[pos2]))
		{
			ans.push_back('e');
			++pos1;
			++pos2;
			continue;
		}
		if (black(s1[pos1], s2[pos2]))
		{
			ans.push_back('f');
			if (s1[pos1] == 'p')
				pos1 += 4;
			++pos1;
			if (s2[pos2] == 'p')
				pos2 += 4;
			++pos2;
			continue;
		}
		if (s1[pos1] == 'p' && s2[pos2] != 'p')
		{
			++pos2;
			parent(ans, s1, ++pos1);
			continue;
		}
		if (s1[pos1] != 'p' && s2[pos2] == 'p')
		{
			++pos1;
			parent(ans, s2, ++pos2);
			continue;
		}
		if (s1[pos1] == 'p' && s2[pos2] == 'p')
		{
			bothparents(s1, ++pos1, s2, ++pos2, ans);
		}
	}
}


void unneeded_len(const string& s, int& pos)
{
	int count = 0;
	while (count < 4)
	{
		if (s[pos] != 'p')
			pos++;
		else
			unneeded_len(s, ++pos);
	}
}


string picsum (string& s1, string& s2)
{
	string ans = "";
	int i, j;
	i = j = 0;
	while (i < s1.size() && j < s2.size())
	{
		if (white(s1[i], s2[i]))
		{
			ans.push_back('e');
			++i;
			++j;
		}
		if (black(s1[i], s2[j]))
		{
			ans.push_back('f');
			if (s1[i] == 'p')
				unneeded_len(s1, ++i);
			else
				++i;
			if (s2[j] == 'p')
				unneeded_len(s2, ++j);
			else
				++j;
			continue;
		}
		if (s1[i] == 'p' && s2[j] != 'p')
		{
			++j;
			parent(ans, s1, ++i);
			continue;
		}
		if (s1[i] != 'p' && s2[j] == 'p')
		{
			++i;
			parent(ans, s2, ++j);
			continue;
		}
		if (s1[i] == 'p' && s2[j] == 'p')
			bothparents(s1, ++i, s2, ++j, ans);
	}
	return ans;
}

void blacksum (const string& s, int level, int& ans, int& pos, int len)
{
	int count = 0;
	while (count < len)
	{
		count++;
		if (s[pos] == 'f')
		{
			int temp = pow(2, 5 - level);
			ans += pow(temp, 2);
			++pos;
			continue;
		}
		if (s[pos] == 'p')
		{
			blacksum(s, ++level, ans, ++pos, 4);
			--level;
		}
		if (s[pos] == 'e')
			++pos;
	}
}

int main ()
{
	int n;
	cin >> n;
	string s1, s2;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2;
		string ans = picsum(s1, s2);
		int count = 0, pos = 0;
		blacksum(ans, 0, count, pos, ans.size());
		cout << "There are " << count << " black pixels." << endl;
	}
}