#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main ()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	double a, b, c;
	cin >> a >> b >> c;
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
				cout << -1;
			else
				cout << 0;
		}
		else
		{
			double x;
			cout << 1 << endl;
			if (c == 0)
				x = 0;
			else
				x = -1.*c/b;
			cout << fixed << setprecision(10) << x;
		}
			
	}
	else
	{
		double D = b * b - 4 * a * c;
		if (D < 0)
			cout << 0;
		else
		{
			D = sqrt(D);
			double x1 = (-b + D)/(2 * a);
			double x2 = x1 - D/a;
			if (fabs(x1 - x2) < 1e-11)
				cout << 1 << endl << fixed << setprecision(10) << x1;
			else
				cout << 2 << endl << fixed <<setprecision(10) << x1 << endl << x2;
		}
	}
}
