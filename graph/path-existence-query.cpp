#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Given sorted array nums and maxDiff.
Nodes i and j are connected by an edge if |nums[i] - nums[j]| <= maxDiff.
For each query [u, v], return true if u and v are in the same connected component.

Key idea:
Since nums is sorted, a component breaks only when:
    nums[i] - nums[i - 1] > maxDiff

Time:  O(n + q)
Space: O(n)
*/

class Solution
{
public:
    vector<bool> pathExistenceQueries(
        int n,
        vector<int> &nums,
        int maxDiff,
        vector<vector<int>> &queries)
    {
        vector<int> component(n);

        int compId = 0;
        component[0] = compId;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] > maxDiff)
            {
                compId++;
            }

            component[i] = compId;
        }

        vector<bool> answer;

        for (auto &query : queries)
        {
            int u = query[0];
            int v = query[1];

            answer.push_back(component[u] == component[v]);
        }

        return answer;
    }
};

int main()
{
    Solution sol;

    int n = 4;
    vector<int> nums = {2, 5, 6, 8};
    int maxDiff = 2;

    vector<vector<int>> queries = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3}};

    vector<bool> ans = sol.pathExistenceQueries(n, nums, maxDiff, queries);

    for (bool value : ans)
    {
        cout << (value ? "true" : "false") << " ";
    }

    return 0;
}