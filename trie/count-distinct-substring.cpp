#include <bits/stdc++.h>
using namespace std;

class Node
{
    Node *links[26];

public:
    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = NULL;
        }
    }
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *getNextNode(char ch)
    {

        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    int n = s.size();
    Node *root = new Node();
    Node *node;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        node = root;
        for (int j = i; j < n; j++)
        {
            if (!node->containsKey(s[j]))
            {
                cnt++;
                node->put(s[j], new Node());
            }

            node = node->getNextNode(s[j]);
        }
    }

    return cnt + 1;
}

int main()
{
    string s;

    int T;
    cout << "Number of testcases:";
    cin >> T;
    while (T--)
    {
        cout << "Enter your String : ";

        cin >> s;
        if (s.length() == 0)
        {
            cout << "String length must be greater than 0" << endl;
            continue;
        }
        int ans = countDistinctSubstrings(s);

        cout << "Number of distinct substrings of string  " << s << " are : " << ans << endl;
    }
    return 0;
}