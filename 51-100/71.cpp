#include "header.h"

class Solution
{
public:
    string simplifyPath(string path)
    {
        int n = path.size();
        stack<string> dirs;
        int i = 0;
        while (i < n)
        {
            while (i < n && path[i] == '/')
                i++;
            if ((i + 2 < n && path[i] == '.' && path[i + 1] == '.' && path[i + 2] == '/') || (i + 2 == n && path[i] == '.' && path[i + 1] == '.'))
            {
                if (!dirs.empty())
                    dirs.pop();
                i += 3;
            }
            else if ((i + 1 < n && path[i] == '.' && path[i + 1] == '/') || (i + 1 == n && path[i] == '.'))
                i += 2;
            else if (i < n)
            {
                string dir;
                while (i < n && path[i] != '/')
                    dir += path[i++];
                dirs.push(dir);
            }
        }

        if (dirs.empty())
            return "/";
        stack<string> reversed;
        while (!dirs.empty())
            reversed.push(dirs.top()), dirs.pop();
        string answer;
        while (!reversed.empty())
            answer += string(1, '/') + reversed.top(), reversed.pop();
        return answer;
    }
};