#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        int hour = stoi(line.substr(0, 2));
        int minute = stoi(line.substr(3, 2));
        int count = (12 * 60 - hour * 60 - minute) / 10 + 1;
        if (minute % 10 > 0 && minute % 10 <= 5)
            count++;
        cout << count << endl;
    }

    return 0;
}