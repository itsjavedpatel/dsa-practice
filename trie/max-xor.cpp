#include <bits/stdc++.h>
using namespace std;

/*
Question: Maximum XOR of Two Numbers in an Array

Given an integer array nums, return the maximum result of nums[i] XOR nums[j],
where 0 <= i <= j < nums.size().

Example:
Input: nums = {3, 10, 5, 25, 2, 8}
Output: 28

Explanation:
The maximum XOR is 5 XOR 25 = 28.

Approach:
We use a Binary Trie.

Each number is stored in binary form from the 31st bit to the 0th bit.
For every number x, we try to find another number in the Trie that gives
the maximum XOR with x.

To maximize XOR:
- If current bit of x is 0, we prefer 1.
- If current bit of x is 1, we prefer 0.

This is because different bits give XOR value 1, which increases the answer.
*/

class Node {
public:
    Node* bits[2];

    Node() {
        bits[0] = NULL;
        bits[1] = NULL;
    }

    bool containsKey(int bit) {
        return bits[bit] != NULL;
    }

    void setBit(int bit, Node* node) {
        bits[bit] = node;
    }

    Node* getNextNode(int bit) {
        return bits[bit];
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit)) {
                node->setBit(bit, new Node());
            }

            node = node->getNextNode(bit);
        }
    }

    int maxXor(int x) {
        Node* node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;

            // To maximize XOR, try to move to the opposite bit
            if (node->containsKey(1 - bit)) {
                ans = ans | (1 << i);
                node = node->getNextNode(1 - bit);
            } else {
                node = node->getNextNode(bit);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();

        // Insert all numbers into the Trie
        for (int element : nums) {
            trie->insert(element);
        }

        int maxi = 0;

        // Find maximum XOR for every number
        for (int element : nums) {
            maxi = max(maxi, trie->maxXor(element));
        }

        return maxi;
    }
};

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};

    Solution obj;

    int result = obj.findMaximumXOR(nums);

    cout << "Maximum XOR is: " << result << endl;

    return 0;
}