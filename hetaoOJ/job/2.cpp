#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        double x1, y1, r1;
        double x2, y2, r2;
        int c;
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;
        cin >> c;
        // 精度问题，如果用int作为坐标，那么平方之后会溢出
        cout << fixed << setprecision(7) << (r1 - r2 - sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))) / c << endl;
    }

    return 0;
}