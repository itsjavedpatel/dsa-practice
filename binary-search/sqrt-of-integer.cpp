// Find the square root of a number to the nearest integer
// Example sqrt(24) -> 4 , sqrt(25) -> 5 sqrt(35) -> 5

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
            return x;
        int s = 1, e = x;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (mid == x / mid)
            {
                return mid;
            }
            else if (mid > x / mid)
            {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }

        return e;
    }
};

int main()
{

    Solution s;
    int num = 24;
    cout << "Sqrt root of " << num << " is : " << s.mySqrt(num);

    return 0;
}