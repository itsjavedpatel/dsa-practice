#include <bits/stdc++.h>
using namespace std;

class KMP {
public:
    vector<int> buildLPS(string pattern) {
        int n = pattern.length();
        vector<int> lps(n, 0);

        int pref = 0;
        int i = 1;

        while (i < n) {
            if (pattern[i] == pattern[pref]) {
                pref++;
                lps[i] = pref;
                i++;
            } else {
                if (pref == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    pref = lps[pref - 1];
                }
            }
        }

        return lps;
    }

    bool search(string text, string pattern) {
        int n = text.length();
        int m = pattern.length();

        if (m == 0) return true;
        if (m > n) return false;

        vector<int> lps = buildLPS(pattern);

        int i = 0;
        int j = 0;

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return true;
            } else if (i < n && text[i] != pattern[j]) {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }

        return false;
    }
};

int main() {
    string text = "ABAABAAA";
    string pattern = "ABAAA";

    KMP kmp;

    vector<int> lps = kmp.buildLPS(pattern);

    cout << "Pattern: " << pattern << endl;
    cout << "Text: " << text << endl;

    cout << "LPS: ";
    for (int x : lps) {
        cout << x << " ";
    }
    cout << endl;

    if (kmp.search(text, pattern)) {
        cout << "Pattern found" << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}