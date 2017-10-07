#include <iostream>
#include <string>
#include <vector>
using namespace std;

int subword (vector <int>& v, vector <int>& word)
{
	for (int i = 0; i < v.size(); i++)
		if (v[i] > word[i])
			return false;
	return true;
}

int main ()
{
	vector <vector <int> > v;
	string s;
	int k = 0;
	cin >> s;
	while (s != "#")
	{
		v.push_back(vector <int>(26));
		for (int i = 0; i < s.size(); i++)
			v[k][ (int) (s[i] - 'a') ]++;
		k++;
		cin >> s;
	}
	s = "";
	vector <int> count;
	getline(cin, s);
	getline (cin, s);
	while (s != "#")
	{
		int num = 0;
		vector <int> word(26);
		for (int i = 0; i < s.size(); i++)
			if (s[i] != ' ')
				word[ (int) (s[i] - 'a') ]++;
		for (int i = 0; i < v.size(); i++)
			if (subword(v[i], word))
				num++;
		count.push_back(num);
		getline (cin, s);
	}
	for (int i = 0; i < count.size(); i++)
		cout << count [i] << endl;
}