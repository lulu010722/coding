#include "header.h"

class Solution
{
public:
    // 所谓滑动窗口，将原来每移动s中的一个字符，都要取m次区间，变成，只需要取s中前k个字符，然后每次向后滑动，这样避免的重复计算。
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> answer;
        int n = s.size(), m = words.size(), k = words[0].size();
        int totalLen = m * k;
        for (int i = 0; i < k && i + totalLen <= n; i++)
        {
            unordered_map<string, int> map;
            for (auto &&word : words)
                ++map[word];
            for (int j = 0; j < totalLen; j += k)
            {
                string sub = s.substr(i + j, k);
                if (--map[sub] == 0)
                    map.erase(sub);
            }

            for (int j = i; j <= n - totalLen; j += k)
            {
                if (j != i)
                {
                    string front = s.substr(j - k, k);
                    string back = s.substr(j + totalLen - k, k);
                    if (++map[front] == 0)
                        map.erase(front);
                    if (--map[back] == 0)
                        map.erase(back);
                }
                if (map.empty())
                    answer.emplace_back(j);
            }
        }
        return answer;
    }
};