#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result = {-1, -1};
        int left = 0, right = nums.size() - 1;

        // Find the first position
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (left >= nums.size() || nums[left] != target)
        {
            return result;
        }

        result[0] = left;

        // Find the last position
        right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        result[1] = right;
        return result;
    }
};

int main()
{
    Solution solution;

    // Take input from the user
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    vector<int> result = solution.searchRange(nums, target);
    cout << "First and last positions of " << target << ": [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
