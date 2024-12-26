#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm> // Include algorithm header for sort
using namespace std;

class Solution
{
public:
    int closestPairSum(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 2)
            return 0; // Not enough elements to form a pair

        sort(arr.begin(), arr.end()); // Sort the array
        int left = 0, right = n - 1;
        int closestSum = INT_MAX;
        int resultSum = 0;

        while (left < right)
        {
            int sum = arr[left] + arr[right];

            // Update resultSum if this pair is closer to zero
            if (abs(sum) < closestSum)
            {
                closestSum = abs(sum);
                resultSum = sum;
            }

            // Move pointers based on the sum
            if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return resultSum;
    }
};

int main()
{
    Solution solution;

    // Take input from the user
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int result = solution.closestPairSum(arr);
    cout << "Sum of two elements closest to zero: " << result << endl;

    return 0;
}
