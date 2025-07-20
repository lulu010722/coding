#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> intervals;
    intervals.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int si, fi;
        cin >> si >> fi;
        intervals.emplace_back(make_pair(si, fi));
    }

    sort(intervals.begin(), intervals.end());

    int solution = 1;

    for (int i = 1; i < n; i++)
    {
        pair<int, int> last = intervals[i - 1];
        pair<int, int> current = intervals[i];
        if (current.first >= last.second)
            solution++;
        else if (current.second > last.second)
            intervals.erase(intervals.begin() + i--), n--;
        else
            intervals.erase(intervals.begin() + --i), n--;
    }

    cout << intervals.size() << endl;

    return 0;
}