#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int findPeakElement(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 1)
            return 0;

        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int s = 1, e = n - 2;

        while (s <= e)
        {

            int mid = (s + e) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] > nums[mid - 1])
            {
                s = mid + 1;
            }
            else
                e = mid - 1;
        }

        return -1;
    }
};

int main()
{
    vector<int> arr = {1, 2, 6, 4, 5, 6, 7, 6, 4, 5, 7, 8, 5};

    Solution s;

    int idx = s.findPeakElement(arr);

    cout << "Peak element is at index: " << idx << endl;

    return 0;
}