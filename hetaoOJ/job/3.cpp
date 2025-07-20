#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

class Solution
{
private:
    vector<vector<int>> graph;
    vector<int> costs;
    vector<int> visited;
    vector<int> dp;

    int dfs(int start)
    {
        if (dp[start] != -1)
            return dp[start];
        if (visited[start])
            return INF;
        visited[start] = true;

        if (graph[start].empty())
            dp[start] = costs[start];
        else
        {
            int result = INF;
            for (auto next : graph[start])
                result = min(result, dfs(next));
            if (result == INF)
                dp[start] = INF;
            else
                dp[start] = costs[start] + result;
        }

        visited[start] = false;
        return dp[start];
    }

public:
    void init()
    {
        int n;
        cin >> n;
        graph.reserve(n);
        costs.resize(n);
        visited.resize(n, 0);
        dp.resize(n, -1);
        for (int i = 0; i < n; i++)
            cin >> costs[i];

        for (int i = 0; i < n; i++)
        {
            int pre_count;
            cin >> pre_count;
            vector<int> pres(pre_count);
            for (int i = 0; i < pre_count; i++)
                cin >> pres[i];

            graph.push_back(pres);
        }
    }

    void solve()
    {
        int n = graph.size();
        for (int i = 0; i < n; i++)
        {
            cout << dfs(i) << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Solution s;
        s.init();
        s.solve();
    }

    return 0;
}