#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct participant
{
	bool solved[9];
	long long penalty[9];
	int solvedNum;
	long long totalPenalty;
	int participantNum;
	bool participated;
};

bool operator > (const participant& first, const participant& second)
{
	if (first.solvedNum == second.solvedNum)
	{
		if (first.totalPenalty == second.totalPenalty)
			return first.participantNum < second.participantNum;
		return first.totalPenalty < second.totalPenalty;
	}
	return first.solvedNum > second.solvedNum;
}

ostream& operator << (ostream& out, participant& p)
{
	out << p.participantNum << ' ' << p.solvedNum << ' ' << p.totalPenalty;
	return out;
}

void countPenalty (participant& p)
{
	for (int i = 0; i < 9; ++i)
		if (p.solved[i])
		{
			++p.solvedNum;
			p.totalPenalty += p.penalty[i];
		}
}

int main ()
{
	//freopen ("INPUT.TXT", "r", stdin);
	//freopen ("OUPTUT.TXT", "w", stdout);
	int caseNum;
	cin >> caseNum;
	string input;
	getline(cin, input);
	getline(cin, input);
	for (int itNum = 0; itNum < caseNum; ++itNum)
	{
		participant contestants[100];
		for (int i = 0; i < 100; ++i)
		{
			contestants[i].participantNum = i + 1;
			contestants[i].totalPenalty = 0;
			contestants[i].solvedNum = 0;
			for (int j = 0; j < 9; ++j)
			{
				contestants[i].penalty[j] = 0;
				contestants[i].solved[j] = false;
			}
			contestants[i].participated = false;
		}
		getline(cin, input);
		while (input != "")
		{
			istringstream iss(input);
			int contestantNum, problemNum, time;
			char success;
			iss >> contestantNum >> problemNum >> time >> success;
			--contestantNum;
			--problemNum;
			contestants[contestantNum].participated = true;
			if (!contestants[contestantNum].solved[problemNum])
			{
				if (success == 'C')
				{
					contestants[contestantNum].solved[problemNum] = true;
					contestants[contestantNum].penalty[problemNum] += time;
				}
				if (success == 'I')
					contestants[contestantNum].penalty[problemNum] += 20;
			}
			getline(cin, input);
		}
		for (int i = 0; i < 100; ++i)
			if (contestants[i].participated)
				countPenalty(contestants[i]);
		sort (contestants, contestants + 100, greater <participant>());
		for (int i = 0; i < 100; ++i)
			if (contestants[i].participated)
				cout << contestants[i] << endl;
		if (itNum != caseNum - 1)
			cout << endl;
	}
}