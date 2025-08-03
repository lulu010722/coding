#include "header.h"

class Solution
{
private:
    vector<vector<int>> answer;
    vector<int> candidates;
    vector<int> combination;
    int target;
    int sum;

    void recurse(int start)
    {
        if (sum == target)
        {
            answer.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (i != start && candidates[i] == candidates[i - 1])
                continue;
            int curr = candidates[i];
            if (curr + sum > target)
                return;
            combination.push_back(curr);
            sum += curr;
            recurse(i + 1);
            sum -= curr;
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        this->target = target;
        recurse(0);
        return answer;
    }
};