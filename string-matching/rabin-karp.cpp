#include <bits/stdc++.h>
using namespace std;

class RKA
{

private:
    double base = 101;
    double calculateHash(string s)
    {

        int n = s.length();
        double hash = 0;

        for (int i = 0; i < n; i++)
        {
            hash = hash + s[i] * pow(base, i);
        }
        return hash;
    }

    double updateHash(int prevIndex, int newIndex,int patternLength, double prevHash, string s)
    {
        double newHash = (prevHash - s[prevIndex]) / base;
        newHash = newHash + s[newIndex] * pow(base, patternLength-1);
        return newHash;
    }

public:
    void search(string s, string pattern)
    {
        int cnt = 0;
        int strLen = s.size();
        int patternLen = pattern.size();
        if (patternLen > strLen)
        {
            cout << "length of pattern must be less than that of search string " << endl;
            return;
        }
        double patternHash = calculateHash(pattern);
        double substrHash = calculateHash(s.substr(0, patternLen));

        for (int i = 0; i <= strLen - patternLen; i++)
        {
        
            if (patternHash == substrHash)
            {
                if (s.substr(i, patternLen) == pattern)
                {
                    cout << "Pattern found at index : " << i << endl;
                    cnt++;
                }
            }
            if(i<strLen-patternLen)
            substrHash = updateHash(i, i + patternLen, patternLen, substrHash, s);
        }

        if(cnt!=0){
            cout<<"There are "<<cnt<<" matching substr in our search string"<<endl;
            return;
        }
        cout << "Pattern not found" << endl;
    }
};

int main()
{

    RKA algo = RKA();

    algo.search("abcdabcdefdabcbdabc", "dabc");

    return 0;
}