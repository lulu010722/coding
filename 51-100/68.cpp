#include "header.h"

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> answer;
        int currentLength = 0;
        vector<string> currentWords;
        string currentLine;
        for (auto &&word : words)
        {
            if (currentLength + word.size() > maxWidth)
            {
                if (currentWords.size() == 1)
                    answer.push_back(currentWords[0] + string(maxWidth - currentWords[0].size(), ' '));
                else
                {
                    vector<int> spaces(currentWords.size() - 1, (maxWidth - currentLength + currentWords.size()) / (currentWords.size() - 1));
                    int remain = maxWidth - currentLength + currentWords.size() - spaces[0] * (currentWords.size() - 1);
                    for (int i = 0; i < remain; i++)
                        spaces[i]++;
                    string temp = currentWords[0];
                    for (int i = 0; i < currentWords.size() - 1; i++)
                        temp += string(spaces[i], ' ') + currentWords[i + 1];
                    answer.push_back(temp);
                }
                currentLength = 0;
                currentWords.clear();
                currentLine = "";
            }
            currentLength += 1 + word.size();
            currentWords.push_back(word);
            currentLine += word + ' ';
        }
        if (currentLine.size() == maxWidth + 1)
            answer.push_back(currentLine.substr(0, currentLine.size() - 1));
        else
            answer.push_back(currentLine + string(maxWidth - currentLine.size(), ' '));
        return answer;
    }
};