#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumAndMultiply(int n)
    {

        int sum = 0;
        int newNum = 0;
        int multiflyFactor = 1;
        while (n)
        {
            int rem = n % 10;

            n = n / 10;
            if (rem != 0)
            {
                newNum = newNum + rem * multiflyFactor;
                multiflyFactor *= 10;
                sum += rem;
            }
        }

        long long ans = 1LL * newNum * sum;
        return ans;
    }
};

int main()
{

    int num = 10203004;

    Solution s;

    int ans = s.sumAndMultiply(num);

    if (ans == 0)
    {
        cout << "No Non-Zero digit found in the number";
    }
    else
    {
        cout << "Answer after concatenating non zero and multiply with sum is : " << ans;
    }

    return 0;
}