#include <bits/stdc++.h>

using namespace std;

/*
Question: Maximum XOR With an Element From Array

You are given an array arr and queries where each query is [xi, ai].

For every query:
- Find the maximum XOR value of xi with any element from arr
  such that the selected element is less than or equal to ai.
- If no such element exists, return -1.

Return answers in the same order as the queries.

Example:
arr = {0, 1, 2, 3, 4}
queries = {{3, 1}, {1, 3}, {5, 6}}

Output: {3, 3, 7}
*/

class Node
{
public:
    Node *bits[2];

    Node()
    {
        bits[0] = NULL;
        bits[1] = NULL;
    }

    bool containsKey(int bit)
    {
        return bits[bit] != NULL;
    }

    void setBit(int bit, Node *node)
    {
        bits[bit] = node;
    }

    Node *getNextNode(int bit)
    {
        return bits[bit];
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit))
            {
                node->setBit(bit, new Node());
            }

            node = node->getNextNode(bit);
        }
    }

    int maxXor(int x)
    {
        Node *node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (x >> i) & 1;

            // To maximize XOR, try to move to the opposite bit
            if (node->containsKey(1 - bit))
            {
                ans = ans | (1 << i);
                node = node->getNextNode(1 - bit);
            }
            else
            {
                node = node->getNextNode(bit);
            }
        }

        return ans;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    // Write your coode here.
    int n = arr.size();

    sort(arr.begin(), arr.end());

    // {ai,{xi,i}};
    vector<pair<int, pair<int, int>>> offlineQ;
    int q = queries.size();

    for (int i = 0; i < q; i++)
    {
        offlineQ.push_back({queries[i][1], {queries[i][0], i}});
    }

    sort(offlineQ.begin(), offlineQ.end());

    int idx = 0;

    vector<int> ans(q, 0);
    Trie *root = new Trie();

    for (int i = 0; i < q; i++)
    {
        int ai = offlineQ[i].first;
        int xi = offlineQ[i].second.first;
        int qIdx = offlineQ[i].second.second;

        while (idx < n && arr[idx] <= ai)
        {
            root->insert(arr[idx]);
            idx++;
        }

        if (idx == 0)
        {
            ans[qIdx] = -1;
        }
        else
        {
            ans[qIdx] = root->maxXor(xi);
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {0, 1, 2, 3, 4};

    vector<vector<int>> queries = {
        {3, 1},
        {1, 3},
        {5, 6}};

    vector<int> result = maxXorQueries(arr, queries);

    cout << "Answers: ";
    for (int value : result)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}