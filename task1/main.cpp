#include <iostream>
using namespace std;

int main()
{
	float a, b, c, d, e, f, x, y;
	bool xr = false, yr = false, none = false, inf = false;
	cin >> a >> b >> c >> d >> e >> f;
	if (d && e && a / d == b / e) {
		if (f && a / d == c / f) 
			inf = true;
		else
			none = true;
	}
	if (a && b && d / a == e / b) {
		if (c && d / a == f / c)
			inf = true;
		else
			none = true;
	}
	if (!a && b) {
		y = c / b;
		if (!d) {
			if (e) {
				if (f / e == c / b)
					xr = true;
				else
					none = true;
			}
			else {
				if (f)
					none = true;
				else
					xr = true;
			}
		}
		else {
			x = (f - e * y) / d;
			yr = false;
		}
	}
	if (!b && a) {
		x = c / a;
		if (!e) {
			if (d) {
				if (f / d == c / a) {
					yr = true;
					//xr = false;
				}else
					none = true;
			}
			else {
				if (f)
					none = true;
				else {
					yr = true;
					//xr = false;
				}
			}
		}
		else {
			y = (f - d * x) / e;
			xr = false;
			//cout << "***";
		}
	}
	if (!a && !b) {
		if (c)
			none = true;
		else {
			if (!d && !e && !f)
				inf = true;
			if (!d && !e && f)
				none = true;
			if (!d && e) {
				xr = true;
				y = f / e;
			}
			if (d && !e) {
				yr = true;
				x = f / d;
			}
			if (d && e)
				inf = true;
		}
	}

	if (inf) cout << "infinite solutions \t";
	if (none) cout << "no solution \t";
	if (xr && !inf && !none) cout << "x belongs to R \t";
	if (!xr && !inf && !none) cout << "x = " << x << "\t";
	if (yr && !inf && !none) cout << "y belongs to R \t";
	if (!yr && !inf && !none) cout << "y = " << y << "\t";
	cout << endl;
	system("pause");
	return 0;
}