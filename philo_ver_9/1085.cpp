#include <iostream>

using namespace std;

int main(void)
{
	int x, y, w, h;
	int disX, disY;
	cin >> x >> y >> w >> h;

	x < abs(w-x) ? disX = x : disX = abs(w-x);
	y < abs(h-y) ? disY = y : disY = abs(h-y);

	cout << min(disX, disY);
}