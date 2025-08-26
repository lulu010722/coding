#include "header.h"

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= newInterval[0])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
            if (i == intervals.size() - 1)
                intervals.push_back(newInterval);
        }
        if (intervals.size() == 0)
            intervals.push_back(newInterval);
        vector<vector<int>> answer;
        answer.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            auto &last = answer.back();
            if (last[1] >= intervals[i][0])
                last[1] = max(intervals[i][1], last[1]);
            else
                answer.push_back(intervals[i]);
        }
        return answer;
    }
};