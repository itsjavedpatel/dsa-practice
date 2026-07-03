#include <bits/stdc++.h>
using namespace std;

/*
Problem idea:
We have to find the longest string such that all of its prefixes
are also present in the given array.

Example:
If "ninja" is present, then:
"n", "ni", "nin", "ninj", and "ninja"
all must also be present.

If multiple valid strings have the same length,
return the lexicographically smallest one.

If no valid string exists, return "None".

Approach:
1. Insert all words into a Trie.
2. For every word, check whether every prefix node is marked as end of a word.
3. Keep the longest valid word.
4. If length is same, keep the lexicographically smaller word.
*/

class Node {
public:
    Node* links[26];
    bool flag;

    Node() {
        flag = false;

        // Very important:
        // Initialize all child pointers with NULL.
        // Otherwise they may contain garbage addresses.
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void setLinks(char ch, Node* newNode) {
        links[ch - 'a'] = newNode;
    }

    Node* getNextTrie(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        // Marks that a complete word ends at this node
        flag = true;
    }

    bool getEnd() {
        return flag;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];

            // If character path does not exist, create a new node
            if (!node->containsKey(ch)) {
                node->setLinks(ch, new Node());
            }

            // Move to the next node
            node = node->getNextTrie(ch);
        }

        // Mark the end of this word
        node->setEnd();
    }

    bool isCompleteString(string word) {
        Node* node = root;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            // If path does not exist, word itself is not present properly
            if (!node->containsKey(ch)) {
                return false;
            }

            node = node->getNextTrie(ch);

            /*
            Main check:
            After moving to every character,
            that prefix must be a complete word.

            Example for "apple":
            "a", "ap", "app", "appl", "apple"
            should all have flag = true.
            */
            if (!node->getEnd()) {
                return false;
            }
        }

        return true;
    }
};

string completeString(int n, vector<string>& a) {
    Trie* trie = new Trie();

    // Insert all words into Trie
    for (int i = 0; i < n; i++) {
        trie->insert(a[i]);
    }

    string ans = "";

    // Check every word
    for (int i = 0; i < n; i++) {
        string s = a[i];

        if (trie->isCompleteString(s)) {
            // Choose longer valid string
            if (s.length() > ans.length()) {
                ans = s;
            }

            // If same length, choose lexicographically smaller string
            else if (s.length() == ans.length() && s < ans) {
                ans = s;
            }
        }
    }

    if (ans.length() == 0) {
        return "None";
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << completeString(n, a) << endl;
    }

    return 0;
}