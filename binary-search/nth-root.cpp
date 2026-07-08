#include <bits/stdc++.h>
using namespace std;

int calculatePower(int a, int b)
{

    int ans = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            if (ans > INT_MAX / a)
            {
                return INT_MAX;
            }
            ans = ans * a;
            b--;
        }
        else
        {

            if (ans > INT_MAX / a || ans * a > INT_MAX / a)
                return INT_MAX;
            a = a * a;

            b = b >> 1;
        }
    }

    return ans;
}

int NthRoot(int n, int m)
{

    // Write your code here.

    if (m == 0 || m == 1 || n == 1)
        return m;

    int s = 1, e = m;

    while (s <= e)
    {

        int mid = s + (e - s) / 2;
        int currPower = calculatePower(mid, n);
        if (currPower == m)
            return mid;
        else if (currPower > m)
            e = mid - 1;
        else
            s = mid + 1;
    }

    return -1;
}

int main()
{

    int m = 64;
    int n = 3;

    cout << n << "th root of " << m << " is : " << NthRoot(n, m) << endl;
}