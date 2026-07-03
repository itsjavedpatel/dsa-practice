#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[26]; // assuming all are lowecase
    bool flag;
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    bool setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
    ~Node()
    {

        for (int i = 0; i < 26; i++)
        {
            delete links[i];
        }
      
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

    void insert(string s)
    {

        int n = s.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            if (!node->containsKey(ch))
            {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }

        node->setEnd();
    }

public:
    bool search(string word)
    {

        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {

            if (!(node->containsKey(word[i])))
            {
                return false;
            }

            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix)
    {

        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!(node->containsKey(prefix[i])))
                return false;

            node = node->get(prefix[i]);
        }

        return true;
    }
    ~Trie()
    {

        delete root;
    }
};
int main()
{
    
    Trie *t = new Trie();
    
    string totalWords[] = {"abcsfd", "abcfg", "abcfd", "adbcdadbfg"};
    string searchWords[] = {"abcfg", "abcfd", "abcfd", "abcdadbfg"};
    string startWith[] = {"abc", "babc", "adb", "afg"};
    
    for (int i = 0; i < 4; i++)
    {
        t->insert(totalWords[i]);
    }
    
    for (int i = 0; i < 4; i++)
    {
        
        if (t->search(searchWords[i]))
        {
            cout << searchWords[i] << " exists in the our trie" << endl;
        }
        else
        {
            cout << "Not exists" << endl;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        
        if (t->startsWith(startWith[i]))
        {
            cout << "string starts with " << startWith[i] << endl;
        }
        else
        {
            cout << "Not starts with " << startWith[i] << endl;
        }
    }
    delete t;
    return 0;
}
